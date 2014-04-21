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
typedef unsigned long long ll;
typedef pair <ll,ll> pll;
typedef vector<int> vi;
const int N=5555;
const int INF=111111111;
const double eps=1e-9;
const double pi=3.14159265358979;

struct pt {
	int x,y;
	bool operator < (const pt & q)const{
		return x<q.x || x==q.x && y<q.y;
	}
} a[N],up[N],down[N],p1,p2;

int n,c1=1,c2=1;

bool cw (pt a, pt b, pt c) {
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x) < 0;
}

bool ccw (pt a, pt b, pt c) {
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x) > 0;
}

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a,a+n);
	p1=a[0];p2=a[n-1];
	up[0]=down[0]=p1;
	forn(i,n-1){
		if (i==n-1 || cw(p1,a[i],p2)){
			while (c1>=2 && !cw(up[c1-2],up[c1-1],a[i])) --c1;
			up[c1++]=a[i];
		}
		if (i==n-1 || ccw(p1,a[i],p2)){
			while (c2>=2 && !ccw(down[c2-2],down[c2-1],a[i])) --c2;
			down[c2++]=a[i];
		}
	}
	n=0;
	rep(i,c1) a[n++]=up[i];
	for (int i=c2-2;i>0;i--) a[n++]=down[i];
	a[n++]=a[0];
	return 0;
}