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
const int N=222222;
const int INF=111111111;
const double eps=1e-9;
const double pi=3.14159265358979;

int n,a[N],ptr,g[N];
bool b[N];
ld ans=0,x[N],y[N],t=100.0,minans,t0=100.0;

inline ld dist(int i,int j){
	return (sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j])));
}

void solve_greedy(){
	int cur=0;
	b[0]=1;a[ptr++]=0;
	rep(steps,n-1){
		int num=-1;
		rep(i,n) if (!b[i] && (num==-1 || dist(cur,num)>dist(cur,i))) num=i;
		ans+=dist(cur,num);
		cur=num;
		a[ptr++]=cur;
		b[cur]=a;
	}
	ans+=dist(a[ptr-1],0);
	minans=ans; 
}

inline ld get_ans(){
	ld cur=0;
	g[n]=0;
	rep(i,n) cur+=dist(g[i],g[i+1]);
	return cur;
}

inline void get_next(){
	int k=n*(t/t0);
	if (k<2) k=2;
	rep(i,n) g[i]=a[i];
	while(k--){
		int num1=rand()%(n-1);
		while (g[num1]==0) num1=rand()%(n-1);
		swap(g[num1],g[num1+1]);
	}
}

inline ld get_rand(){
	return ((rand()*1ll*rand())%1000001)/1000000.0;
}

int main(){
	ropen("input.txt");
	wopen("output.txt");
	srand(time(NULL));
	cin>>n;
	rep(i,n) cin>>x[i]>>y[i];
	solve_greedy();
	int k=20000;
	while (k--){
		get_next();
		ld ff=get_ans();
		if (ff<ans){
			ans=ff;
			rep(i,n) a[i]=g[i];
		} else {
			ld delta=ff-ans;
			ld p=exp(-delta/t);
			if (get_rand()<=p){
				ans=ff;
				rep(i,n) a[i]=g[i];
			}
		}
		t*=0.99;
		minans=min(minans,ans);
	}
	printf("%lf\n",minans);
	return 0;
}