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
const int N=111111;
const int L=16;
const int INF=111111111;
const double eps=1e-9;
const double pi=3.14159265358979;

struct tree{
	int sum;
	tree *l,*r;
	tree(){}
	tree(int value):l(NULL),r(NULL),sum(value){}
	tree(tree* l, tree *r):l(l),r(r){
		sum=l->sum+r->sum;
	}
	 
} t[N];
typedef tree* ptree;

ptree root[N];
int es[N+N],next[N+N],up[N][L+1],n,m,a[N],tin[N],tout[N],c,timer,sorted[N],first[N];

inline void add(int x,int y){
	next[++c]=first[x];first[x]=c;
	es[c]=y;
}

inline bool upper(int x,int y){
	return tin[x]<=tin[y] && tout[x]>=tout[y];
}

ptree build(int l,int r){
	if (l==r) return new tree(0);
	return new tree(build(l,(l+r)/2),build((l+r)/2+1,r));
}

int getsum(ptree t,int l,int r,int tl,int tr){
	if (tl>r || tr<l) return 0;
	if (tl>=l && tr<=r) return t->sum;
	return getsum(t->l,l,r,tl,(tl+tr)/2)+getsum(t->r,l,r,(tl+tr)/2+1,tr);
}

ptree modify(ptree t,int pos,int value,int tl,int tr){
	if (tl==tr) return new tree(value);
	else {
		if (pos<=(tl+tr)/2) return new tree(modify(t->l,pos,value,tl,(tl+tr)/2),t->r);
		else return new tree(t->l,modify(t->r,pos,value,(tl+tr)/2+1,tr));	
	}
}

inline int lca(int a,int b){
	if (upper(a,b)) return a;
	if (upper(b,a)) return b;
	for (int i=L;i>=0;--i) if (!upper(up[a][i],b)) a=up[a][i];
	return up[a][0];
}

void dfs(int v,int p=1){
	tin[v]=++timer;
	up[v][0]=p;
	forn(i,L) up[v][i]=up[up[v][i-1]][i-1];
	if (v!=1) root[v]=modify(root[p],a[v],getsum(root[p],a[v],a[v],1,n)+1,1,n);
	else root[v]=modify(root[0],a[v],1,1,n);
	forg(h,v) if (es[h]!=p) dfs(es[h],v);
	tout[v]=++timer;
}

int get_k(ptree p, ptree q,int k,int tl,int tr){
	if (tl==tr) return tl;
	if (q->l->sum-p->l->sum>=k) return get_k(p->l,q->l,k,tl,(tl+tr)/2);
	else return get_k(p->r,q->r,k-q->l->sum+p->l->sum,(tl+tr)/2+1,tr);
}                     

int get_k(ptree p, ptree q, ptree lc, int value,int k,int tl,int tr){
	if (tl==tr) return tl;
	if (value<=(tl+tr)/2 && value>=tl){
		if (p->l->sum+q->l->sum-2*lc->l->sum+1>=k) return get_k(p->l,q->l,lc->l,value,k,tl,(tl+tr)/2);
		else return get_k(p->r,q->r,lc->r,value,k-(p->l->sum+q->l->sum-2*lc->l->sum+1),(tl+tr)/2+1,tr);
	} else {
		if (p->l->sum+q->l->sum-2*lc->l->sum>=k) return get_k(p->l,q->l,lc->l,value,k,tl,(tl+tr)/2);
		else return get_k(p->r,q->r,lc->r,value,k-(p->l->sum+q->l->sum-2*lc->l->sum),(tl+tr)/2+1,tr);
	}
}		

int get_k(ptree p,int k,int tl,int tr){
	if (tl==tr) return tl;
	if (p->l->sum>=k) return get_k(p->l,k,tl,(tl+tr)/2);
	else return get_k(p->r,k-p->l->sum,(tl+tr)/2+1,tr);
}

inline void query(int a,int b,int k){
	int lc=lca(a,b);
	if (lc==b) swap(a,b);
	if (lc==a){
		if (a>1) printf("%d\n",sorted[get_k(root[up[a][0]],root[b],k,1,n)]);
		else printf("%d\n",sorted[get_k(root[b],k,1,n)]);
	} else printf("%d\n",sorted[get_k(root[a],root[b],root[lc],::a[lc],k,1,n)]);
}

int main(){
//	ropen("input.txt");
//	wopen("output1.txt");
	scanf("%d%d",&n,&m);
	forn(i,n) scanf("%d",&a[i]);
	forn(i,n) sorted[i]=a[i];
	sort(sorted+1,sorted+n+1);
	forn(i,n) a[i]=lower_bound(sorted+1,sorted+n+1,a[i])-sorted;
	forn(i,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	root[0]=build(1,n);
	dfs(1);
	forn(i,m){
		int a,b,k;
		scanf("%d%d%d",&a,&b,&k);
		query(a,b,k);
	}
	return 0;
}