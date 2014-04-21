#include <iostream>
#include <algorithm>
#define N 111111

using namespace std;

struct treap{
	int ls,rs,x,y,sum,cost,sz,add;
} t[N];

int a[N],root,n,c;

inline int sumof(int x){
	return x?t[x].sum+t[x].sz*t[x].add:0;
}

inline int szof(int x){
	return x?t[x].sz:0;
}

inline void recalc(int x){
	if (x){
		t[x].sum=sumof(t[x].ls)+sumof(t[x].rs)+t[x].cost;
		t[x].sz=szof(t[x].ls)+szof(t[x].rs)+1;
	}
}

inline void push(int x){
	if (x && t[x].add){
		t[x].cost+=t[x].add;
		t[t[x].ls].add+=t[x].add;
		t[t[x].rs].add+=t[x].add;
		t[x].add=0;
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
	push(x);
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

inline int get_sum(int l,int r){
	int L,M1,M2,R;
	split(root,l-1,L,M1);
	split(M1,r,M2,R);
	int q=sumof(M2);
	merge(M1,M2,R);
	merge(root,L,M1);
	return q;
}

inline void add(int l,int r,int x){
	int L,M1,M2,R;
	split(root,l-1,L,M1);
	split(M1,r,M2,R);
	t[M2].add+=x;
	merge(M1,M2,R);
	merge(root,L,M1);
}

int main(){
	cin>>n;
	for (int i=0;i<n;i++) a[i]=i;
	random_shuffle(a,a+n);
	for (int i=0;i<n;i++){
		cin>>t[++c].x>>t[c].cost;
		t[c].sum=t[c].cost;t[c].sz=1;
		t[c].y=a[i];
		insert(root,c);
	}
	int l,r,val;
	cin>>l>>r>>val;
	add(l,r,val);
	cin>>l>>r;
	cout<<get_sum(l,r);
}