#include <iostream>
#include <algorithm>
#define N 111111

using namespace std;

struct treap{
	int ls,rs,y,cost,sz;
} t[N];

int a[N],root,n,c;

inline int szof(int x){
	return x?t[x].sz:0;
}

inline void recalc(int x){
	if (x) t[x].sz=szof(t[x].ls)+szof(t[x].rs)+1;
}

void merge(int &x,int l,int r){
	if (!l || !r) x=l?l:r;
	else if (t[l].y>t[r].y) x=l,merge(t[x].rs,t[x].rs,r);
	else x=r,merge(t[x].ls,l,t[x].ls);
	recalc(x);
}

void split (int x,int key,int &l,int &r){
	if (!x) l=r=0;
	else {
		int ck=szof(t[x].ls)+1;
		if (ck<=key) l=x,split(t[x].rs,key-ck,t[x].rs,r);
		else r=x,split(t[x].ls,key,l,t[x].ls);
		recalc(x);
	}
}

void print(int x){
	if (!x) return;
	print(t[x].ls);
	cout<<t[x].cost<<" ";
	print(t[x].rs);
}

void insert(int pos,int x){
	t[++c]=(treap){0,0,a[c-1],x,1};
	int l,r,m;
	split(root,pos,l,r);
	merge(m,l,c);
	merge(root,m,r);
}

void erase(int pos){
	int l,r,m,r1;
	split(root,pos-1,l,r);
	split(r,1,m,r1);
	merge(root,l,r1);
}

int kth(int x,int k){
	int sl=szof(t[x].ls)+1;
	if (sl==k) return t[x].cost;
	if (sl<k) return kth(t[x].rs,k-sl);
	if (sl>k) return kth(t[x].ls,k);
}

int main(){
	cin>>n;
	for (int i=0;i<n;i++) a[i]=i;
	random_shuffle(a,a+n);
	for (int i=0;i<n;i++){
		int x;
		cin>>x;
		insert(i+1,x);
	}
	int pos,value;
	cin>>pos>>value;
	insert(pos,value);
	cin>>pos;
	erase(pos);
	print(root);
}