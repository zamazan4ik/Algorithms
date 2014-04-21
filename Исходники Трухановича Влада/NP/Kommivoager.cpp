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
const int N=14;
const int INF=111111111;
const double eps=1e-9;
const double pi=3.14159265358979;

int g[N][N],n,f[N][1<<N],ans=INF,p[N][1<<N],pos;

int calc(int last,int mask){
	if (f[last][mask]!=-1) return f[last][mask];
	int &res=f[last][mask];
	mask^=1<<last;
	res=INF;
	rep(i,n) if (mask&(1<<i)){
		int q=calc(i,mask)+g[i][last];
		if (q<res){
			res=q;
			p[last][mask|(1<<last)]=i;
		}
	}
	return res;
}

int main(){
	ropen("input.txt");
	wopen("output.txt");
	scanf("%d",&n);
	rep(i,n) rep(j,n) scanf("%d",&g[i][j]);
	int lim=(1<<n)-1;
	mem(f,255);
	f[0][1]=0;
	forn(i,n-1){
		int q=calc(i,lim)+g[i][0];
		if (q<ans){
			pos=i;
			ans=q;
		}
	}
	printf("%d\n",ans);
	printf("1 ");
	rep(i,n){
		printf("%d ",pos+1);
		int q=pos;
		pos=p[pos][lim];
		lim^=1<<q;
	}
}