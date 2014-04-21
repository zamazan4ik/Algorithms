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
	int ls,rs,sum;
	tree(){}
	tree(int value):ls(0),rs(0),sum(value){}
} t[N];

int c,n,a[N],root[N],k;

int build(int l,int r){
	int v=++c;
	if (l==r) t[v]=tree(a[l]);
	else {
		t[v].ls=build(l,(l+r)/2);
		t[v].rs=build((l+r)/2+1,r);
		t[v].sum=t[t[v].ls].sum+t[t[v].rs].sum;
	}
	return v;
}

int getsum(int v,int l,int r,int tl,int tr){
	if (tl>r || tr<l) return 0;
	if (tl>=l && tr<=r) return t[v].sum;
	return getsum(t[v].ls,l,r,tl,(tl+tr)/2)+getsum(t[v].rs,l,r,(tl+tr)/2+1,tr);
}

int modify(int v,int pos,int value,int tl,int tr){
	int nv=++c;
	if (tl==tr) t[nv]=tree(value);
	else {
		int mid=(tl+tr)/2;
		if (pos<=mid) t[nv].rs=t[v].rs,t[nv].ls=modify(t[v].ls,pos,value,tl,mid);
		else t[nv].ls=t[v].ls,t[nv].rs=modify(t[v].ls,pos,value,mid+1,tr);
		t[nv].sum=t[t[nv].ls].sum+t[t[nv].rs].sum;
	}
	return nv;
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