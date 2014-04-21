#include <iostream>
#include <algorithm>
#define N 111111

using namespace std;

struct treap{
	int ls,rs,y,cost,sz,sum,color;
} t[N];

int a[N],root,n,c;

inline int szof(int x){
	if (x) return t[x].sz; else return 0;
}

inline int sumof(int x){
	if (x){
		if (t[x].color==-1) return t[x].sum;
		else return t[x].color*szof(x);
	} else return 0;
}

inline void recalc(int x){
	if (x){
		t[x].sz=szof(t[x].ls)+szof(t[x].rs)+1;
		t[x].sum=sumof(t[x].ls)+sumof(t[x].rs)+t[x].cost;
	}
}

inline void push(int x){
	if (x && t[x].color!=-1){
		t[x].cost=t[x].color;
		t[t[x].ls].color=t[x].color;
		t[t[x].rs].color=t[x].color;
		t[x].color=-1;
	}
}

void merge(int &x,int l,int r){
	push(l);push(r);
	if (!l || !r) x=l?l:r;
	else if (t[l].y>t[r].y) x=l,merge(t[x].rs,t[x].rs,r);
	else x=r,merge(t[x].ls,l,t[x].ls);
	recalc(x);
}

void split (int x,int key,int &l,int &r){
	if (!x) l=r=0;
	else {
		push(x);
		int ck=szof(t[x].ls)+1;
		if (ck<=key) l=x,split(t[x].rs,key-ck,t[x].rs,r);
		else r=x,split(t[x].ls,key,l,t[x].ls);
		recalc(x);
	}
}

void print(int x){
	if (!x) return;
	push(x);
	print(t[x].ls);
	cout<<t[x].cost<<" ";
	print(t[x].rs);
}

inline void insert(int pos,int x){
	t[++c]=(treap){0,0,a[c-1],x,1,x,-1};
	int l,r,m;
	split(root,pos,l,r);
	merge(m,l,c);
	merge(root,m,r);
}

inline void erase(int pos){
	int l,r,m,r1;
	split(root,pos-1,l,r);
	split(r,1,m,r1);
	merge(root,l,r1);
}

inline void coloring(int l,int r,int color){
	int L,M,R,L1;
	split(root,r,L,R);
	split(L,l-1,L1,M);
	t[M].color=color;
	merge(L,L1,M);
	merge(root,L,R);
}

inline int get_sum(int l,int r){
	int L,M,R,L1;
	split(root,r,L,R);
	split(L,l-1,L1,M);
	int ans=sumof(M);
	merge(L,L1,M);
	merge(root,L,R);
	return ans;
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
	int l,r,color;
	cin>>l>>r>>color;
	coloring(l,r,color);
	cin>>l>>r;
	cout<<get_sum(l,r);
}