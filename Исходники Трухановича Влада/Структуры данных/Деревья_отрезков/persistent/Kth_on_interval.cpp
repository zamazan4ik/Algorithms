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
const int N=15000000;
const int INF=111111111;
const double eps=1e-9;
const double pi=3.14159265358979;

struct tree{
	int ls,rs,sum;
	tree(){}
	tree(int value):ls(0),rs(0),sum(value){}
} t[N];

int c,n,a[100001],root[100001],k,sorted[100001],m;

int build(int l,int r){
	int v=++c;
	if (l==r) t[v]=tree(0);
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
		else t[nv].ls=t[v].ls,t[nv].rs=modify(t[v].rs,pos,value,mid+1,tr);
		t[nv].sum=t[t[nv].ls].sum+t[t[nv].rs].sum;
	}
	return nv;
}

int get_k(int p,int q,int k,int tl,int tr){
	if (tl==tr) return tl;
	if (t[t[q].ls].sum-t[t[p].ls].sum>=k) return get_k(t[p].ls,t[q].ls,k,tl,(tl+tr)/2);
	else return get_k(t[p].rs,t[q].rs,k-t[t[q].ls].sum+t[t[p].ls].sum,(tl+tr)/2+1,tr);
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