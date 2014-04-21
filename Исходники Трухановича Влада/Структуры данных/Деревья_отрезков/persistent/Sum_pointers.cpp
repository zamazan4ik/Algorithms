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
const int N=1111111;
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
int n,a[N],k;

ptree build(int l,int r){
	if (l==r) return new tree(a[l]);
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

int main(){
	ropen("input.txt");
	scanf("%d",&n);
	forn(i,n) scanf("%d",&a[i]);
	root[k++]=build(1,n);
	int l1,r1,l2,r2;
	scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
	root[k++]=modify(root[0],l1,r1,1,n);
	printf("%d %d\n",getsum(root[0],l2,r2,1,n),getsum(root[1],l2,r2,1,n));
	return 0;
}	