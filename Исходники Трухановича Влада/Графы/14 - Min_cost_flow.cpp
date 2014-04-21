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
const int N=66;
const int M=22222;
const int INF=111111111;
const double eps=1e-9;
const double pi=3.14159265358979;

int ef[M],es[M],first[N],next[M],ev[M],ec[M],S=1,T,a[N],b[N],x,y,z,c,n,sum1,sum2,ans,from[N],edge[N],d[N],m,k;

inline int be(int x){
	return (x&1)?x+1:x-1;
}

inline void add(int x,int y,int z,int co){
	next[++c]=first[x];first[x]=c;
	ef[c]=x;es[c]=y;ev[c]=z;ec[c]=co;
}

void create_graph(){
	rep(i,m){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		++x;++y;
		add(x,y,1,z);
		add(y,x,0,-z);
	}
	T=n;
}               

inline bool find_path(){
	mem(d,63);
	d[S]=0;
	forn(i,n) forn(j,c){
		if (!ev[j]) continue;
		if (d[es[j]]>d[ef[j]]+ec[j] && d[ef[j]]<1000000000){
			d[es[j]]=d[ef[j]]+ec[j];
			from[es[j]]=ef[j];
			edge[es[j]]=j;
		}
	}
	return d[T]<1000000000;
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	if (n==0 && m==0) return 0;
	create_graph();
	while (find_path()){
		int q=INF;
		for (int v=T;v!=S;v=from[v]) q=min(q,ev[edge[v]]);
		ans+=min(k,q)*d[T];
		k-=min(k,q);
		if (k==0) break;
		for (int v=T;v!=S;v=from[v]){
			ev[edge[v]]-=q;
			ev[be(edge[v])]+=q;
		}
	}
	if (k) puts("Not possible");
	else printf("%d\n",ans);
	return 0;
}