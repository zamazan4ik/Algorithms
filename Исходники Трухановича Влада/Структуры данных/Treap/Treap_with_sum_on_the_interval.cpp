#include <iostream>
#include <algorithm>
#define N 111111

using namespace std;

struct treap{
	int ls,rs,x,y,sum,cost;
} t[N];

inline int sumof(int x){
	return x?t[x].sum:0;
}

inline void recalc(int x){
	t[x].sum=sumof(t[x].ls)+sumof(t[x].rs)+t[x].cost;
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

inline int get_sum(int l,int r){
	int res,L,R,M,L1;
	split(root,r,L,R);
	split(L,l-1,L1,M);
	res=sumof(M);
	merge(L,L1,M);
	merge(root,L,R);
	return res;
}

int main(){
	cin>>n;
	for (int i=0;i<n;i++) a[i]=i;
	random_shuffle(a,a+n);
	for (int i=0;i<n;i++){
		cin>>t[++c].x>>t[c].cost;
		t[c].sum=t[c].cost;
		t[c].y=a[i];
		insert(root,c);
	}
	int l,r;
	cin>>l>>r;
	cout<<get_sum(l,r);
}