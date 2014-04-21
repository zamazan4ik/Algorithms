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
const int N=2222;
const int INF=111111111;
const double eps=1e-9;
const double pi=3.14159265358979;

int n,a[N],g[N];
ld x[N],y[N];

inline ld get_rand(){
	return ((rand()*1ll*rand()*rand())%1000000001)/1000000000.0;
}

inline void getRC(int *res,int m){
	rep(i,n) res[i]=i;
	rep(i,m){
		int j=n-1;
		if (n-i>0) j-=rand()%(n-i);
		swap(res[i],res[j]);
	}
}

inline void getRP(int *res,int m){
	rep(i,n) res[i]=i;
	for (int i=m-1;i>0;i--){
		int j=rand()%(i+1);
		swap(res[i],res[j]);
	}
}

inline void get_next(int changes) {
	int p[N],r[N];
	getRC(p,changes);
	getRP(r,changes);
	rep(i,n) g[i]=a[i];
	rep(i,changes) g[p[i]]=a[p[r[i]]];
}

inline ld eval(){
	ld res=0;
	g[n]=g[0];
	rep(i,n) res+=sqrt(sqr(x[g[i]]-x[g[i+1]])+sqr(y[g[i]]-y[g[i+1]]));
	return res;
}

inline ld prob(ld cur,ld nw,ld t){
	ld delta=nw-cur;
	if (delta<0) return 1.0;
	else return exp(-delta/t);
}

ld solve_greedy(){
	int cur=0,ptr=0;
	ld ans=0.0;
	bool b[N];memo(b);
	b[0]=1;a[ptr++]=0;
	rep(steps,n-1){
		int num=-1;
		rep(i,n) if (!b[i] && (num==-1 || sqr(x[cur]-x[num])+sqr(y[cur]-y[num])>sqr(x[cur]-x[i])+sqr(y[cur]-y[i]))) num=i;
		ans+=sqrt(sqr(x[cur]-x[num])+sqr(y[cur]-y[num]));
		cur=num;
		a[ptr++]=cur;
		b[cur]=1;
	}
	ans+=sqrt(sqr(x[a[n-1]]-x[0])+sqr(y[a[n-1]]-y[0]));
	return ans;
}

void anneal(){
	ld ans,minans;
	ans=minans=solve_greedy();
	ld mxt=100.0;
	for (ld curt=mxt;curt>0.01;curt*=0.999){
		int changes=max(2,(int)(curt/mxt*n));
		get_next(changes);
		ld nw=eval();
		ld ff=prob(ans,nw,curt);
		if (ff>=get_rand()){
			ans=nw;
			rep(i,n+1) a[i]=g[i];
		}
		if (ans<minans) minans=ans;
	}
	printf("%lf\n",minans);
}

int main(){
	ropen("input.txt");
	wopen("output.txt");
	srand(time(NULL));
	scanf("%d",&n);
	rep(i,n) scanf("%lf %lf",&x[i],&y[i]);
	anneal();
	return 0;
}