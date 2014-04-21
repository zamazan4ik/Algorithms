#include <iostream>
#include <algorithm>
#define N 111111

using namespace std;

struct treap{
	int ls,rs,x,y,sz;
} t[N];

inline int szof(int x){
	return x?t[x].sz:0;
}

inline void recalc(int x){
	t[x].sz=szof(t[x].ls)+szof(t[x].rs)+1;
}

int a[N],root,n,c;

void merge(int &x,int l,int r){
	if (!l || !r) x=l?l:r;
	else if (t[l].y>t[r].y) x=l,merge(t[x].rs,t[x].rs,r);
	else x=r,merge(t[x].ls,l,t[x].ls);
	recalc(x);
}

void split (int x,int key,int &l,int &r){
	if (!x) l=r=0;
	else if (t[x].x<=key) l=x,split(t[x].rs,key,t[x].rs,r);
	else r=x,split(t[x].ls,key,l,t[x].ls);
	recalc(x);
}

void insert(int & x,int num){
	if (!x) x=num;
	else if (t[x].y<t[num].y) split(x,t[num].x,t[num].ls,t[num].rs),x=num;
	else insert(t[x].x<t[num].x?t[x].rs:t[x].ls,num);
	recalc(x);
}

void erase(int & x,int key){
	if (!x) return;
	else if (t[x].x==key) merge(x,t[x].ls,t[x].rs);
	else erase(t[x].x<=key?t[x].rs:t[x].ls,key);
	recalc(x);
}

void print(int x){
	if (!x) return;
	print(t[x].ls);
	cout<<t[x].x<<" ";
	print(t[x].rs);
}

int kth(int x,int k){
	int sl=szof(t[x].ls)+1;
	if (sl==k) return t[x].x;
	if (sl<k) return kth(t[x].rs,k-sl);
	if (sl>k) return kth(t[x].ls,k);
}

int main(){
	cin>>n;
	for (int i=0;i<n;i++) a[i]=i;
	random_shuffle(a,a+n);
	for (int i=0;i<n;i++){
		cin>>t[++c].x;
		t[c].y=a[i];t[c].sz=1;
		insert(root,c);
	}
	int x;
	cin>>x;
	cout<<kth(root,x);
}