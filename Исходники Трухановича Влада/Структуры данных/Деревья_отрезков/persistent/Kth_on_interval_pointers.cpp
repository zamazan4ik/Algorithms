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
int n,a[N],k,sorted[N],m;

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

int get_k(ptree p, ptree q,int k,int tl,int tr){
	if (tl==tr) return tl;
	if (q->l->sum-p->l->sum>=k) return get_k(p->l,q->l,k,tl,(tl+tr)/2);
	else return get_k(p->r,q->r,k-q->l->sum+p->l->sum,(tl+tr)/2+1,tr);
}

int main(){
//	ropen("input.txt");
	scanf("%d%d",&n,&m);
	forn(i,n) scanf("%d",&a[i]);
	forn(i,n) sorted[i]=a[i];
	sort(sorted+1,sorted+n+1);
	forn(i,n) a[i]=lower_bound(sorted+1,sorted+n+1,a[i])-sorted;
	root[k++]=build(1,n);
	forn(i,n){
		int val=getsum(root[k-1],a[i],a[i],1,n);
		root[k]=modify(root[k-1],a[i],val+1,1,n);
		++k;
	}
	rep(i,m){              
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",sorted[get_k(root[l-1],root[r],k,1,n)]);
	}                                                            
	return 0;
}	