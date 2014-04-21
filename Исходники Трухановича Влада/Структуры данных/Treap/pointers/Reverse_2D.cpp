#pragma comment(linker, "/STACK:65777216")
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <string>
#include <memory.h>
#include <iterator>
#define y1 trololoy1
#define y0 trololoy0
#define mem(A,X) memset(A,X,sizeof(A))
#define memo(A) memset(A,0,sizeof(A))
#define forn(I,B) for (int I=1;I<=(B);I++)
#define forg(H,V) for (int H=first[V];h;h=next[H])
#define rep(I,B) for (int I=0;I<(B);I++) 
#define labs(X) (((X)>0)?(X):(-(X)))
#define ropen(X) freopen(X,"r",stdin)
#define wopen(X) freopen(X,"w",stdout)
#define rwopen(X) freopen(X".in","r",stdin);freopen(X".out","w",stdout)
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(),(X).end()
#define sqr(X) ((X)*(X))

using namespace std;

typedef pair <int,int> pii;
typedef double ld;
typedef long long ll;
typedef pair <ll,ll> pll;
typedef vector<int> vi;
const int N=1111;
const int INF=111111111;
const double eps=1e-9;
const double pi=3.14159265358979;

struct treap{
	int y,cnt,value;
	bool rev;
	treap *l,*r;
	treap(){}
	treap(int x,int y) :value(x),y(y),l(NULL),r(NULL),cnt(1),rev(false){};
};

typedef treap* ptreap;

ptreap root[N];
int a[N*N],c,n;

inline int cnt(ptreap t){
	return t?t->cnt:0;
}

inline void push(ptreap t){
	if (t && t->rev){
		if (t->l) t->l->rev^=1;
		if (t->r) t->r->rev^=1;
		swap(t->l,t->r);
		t->rev=0;
	}
}

inline void recalc(ptreap t){
	if (t) t->cnt=1+cnt(t->l)+cnt(t->r);
}

void split (ptreap t, int x, ptreap & l, ptreap & r) {
	if (!t)	return void(l=r=NULL);
	push(t);
	int cur_key=cnt(t->l)+1;
	if (cur_key<=x) split(t->r,x-cur_key,t->r,r),l=t;
	else split(t->l,x,l,t->l),r=t;
	recalc(t);
}

void merge (ptreap & t, ptreap l, ptreap r) {
	push(l);push(r);
	if (!l || !r) t=l?l:r;
	else if (l->y>r->y) merge(l->r,l->r, r),t=l;
	else merge(r->l,l,r->l),t=r;
	recalc(t);
}

void print(ptreap x){
	if (x==NULL) return;
	push(x);
	print(x->l);
	cout<<x->value<<" ";
	print(x->r);
}

void insert(ptreap &root,int pos,int value){
	ptreap q=new treap(value,a[++c]);
	if (!root){
		root=q;
		return;
	}
	ptreap L,M,R;
	split(root,pos-1,L,R);
	merge(M,L,q);
	merge(root,M,R);
}

inline void reverse(ptreap & t,int l,int r){
	ptreap t1,t2,t3,t4;
	split(t,r,t2,t3);
	split(t2,l-1,t1,t4);
	t4->rev^=true;
	merge(t2,t1,t4);
	merge(t,t2,t3);	
}

inline void swap_r(ptreap & root1, ptreap & root2,int l,int r){
	ptreap L1,L2,R1,R2,M1,M2,LL1,LL2;
	split(root1,r,L1,R1);
	split(L1,l-1,LL1,M1);
	split(root2,r,L2,R2);
	split(L2,l-1,LL2,M2);
	merge(L1,LL1,M2);
	merge(root1,L1,R1);
	merge(L2,LL2,M1);
	merge(root2,L2,R2);
}
	

int main(){
	int n,m,k;
	ropen("input.txt");
	wopen("output.txt");
	scanf("%d%d",&n,&m);
	forn(i,n*m) a[i]=i;
	random_shuffle(a+1,a+n*m+1);
	forn(i,n) forn(j,m){
		int x;
		scanf("%d",&x);
		insert(root[i],j,x);
	}
	scanf("%d\n",&k);
	forn(i,k){
		char c;
		int x1,y1,x2,y2;
		scanf("%c %d %d %d %d\n",&c,&x1,&y1,&x2,&y2);
		if (c=='H' && y1==y2 || c=='V' && x1==x2) continue;
		if (c=='H') for(int i=x1;i<=x2;i++) reverse(root[i],y1,y2);
		else while (x2>x1){
			swap_r(root[x1],root[x2],y1,y2);
			++x1;
			--x2;
		}
	}
	forn(i,n){
		print(root[i]);
		putchar('\n');
	}
	return 0;
}