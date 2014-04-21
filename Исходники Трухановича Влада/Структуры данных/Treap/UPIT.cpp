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

struct treap{
	int ls,rs,y,sz,color;
	ll cost,sum,a,b;
	treap(){}
	treap(int ls,int rs,int y,ll cost,int sz,ll sum,int color,ll a,ll b):ls(ls),rs(rs),y(y),cost(cost),sz(sz),sum(sum),color(color),a(a),b(b){}
} t[N];

int a[N],root,n,c,m;

inline int szof(int x){
	if (x) return t[x].sz; else return 0;
}

inline ll sumof(int x){
	if (x){
		ll res=t[x].sum;
		if (t[x].color!=-1) res=t[x].sz*t[x].color;
		res+=t[x].sz*t[x].a+(t[x].sz+1)*t[x].b*t[x].sz/2;
		return res;
	} else return 0;
}

inline void recalc(int x){
	if (x){
		t[x].sz=szof(t[x].ls)+szof(t[x].rs)+1;
		t[x].sum=sumof(t[x].ls)+sumof(t[x].rs)+t[x].cost;
	}
}

inline void push(int x){
	if (x && t[x].color!=-1){
		t[x].cost=t[x].color;
		t[t[x].ls].color=t[x].color;
		t[t[x].rs].color=t[x].color;
		t[x].color=-1;
		t[t[x].ls].a=t[t[x].ls].b=t[t[x].rs].a=t[t[x].rs].b=0;
	}
	if (x && (t[x].a || t[x].b)){
		t[t[x].ls].b+=t[x].b;
		t[t[x].rs].b+=t[x].b;
		t[t[x].ls].a+=t[x].a;
		t[t[x].rs].a+=t[x].a+(szof(t[x].ls)+1)*t[x].b;
		t[x].cost+=t[x].a+(szof(t[x].ls)+1)*t[x].b;
		t[x].a=t[x].b=0;
	}
}

void merge(int &x,int l,int r){
	push(l);push(r);
	if (!l || !r) x=l?l:r;
	else if (t[l].y>t[r].y) x=l,merge(t[x].rs,t[x].rs,r);
	else x=r,merge(t[x].ls,l,t[x].ls);
	recalc(x);
}

void split (int x,int key,int &l,int &r){
	if (!x) l=r=0;
	else {
		push(x);
		int ck=szof(t[x].ls)+1;
		if (ck<=key) l=x,split(t[x].rs,key-ck,t[x].rs,r);
		else r=x,split(t[x].ls,key,l,t[x].ls);
		recalc(x);
	}
}

inline void insert(int pos,int x){
	t[++c]=treap(0,0,a[c-1],x,1,x,-1,0,0);
	int l,r,m;
	split(root,pos,l,r);
	merge(m,l,c);
	merge(root,m,r);
}

inline void erase(int pos){
	int l,r,m,r1;
	split(root,pos-1,l,r);
	split(r,1,m,r1);
	merge(root,l,r1);
}

inline void coloring(int l,int r,int color){
	int L,M,R,L1;
	split(root,r,L,R);
	split(L,l-1,L1,M);
	t[M].color=color;
	t[M].a=t[M].b=0;
	merge(L,L1,M);
	merge(root,L,R);
}

inline void update(int l,int r,ll x){
	int L,M,R,L1;
	split(root,r,L,R);
	split(L,l-1,L1,M);
	t[M].b+=x;
	merge(L,L1,M);
	merge(root,L,R);
}
inline ll get_sum(int l,int r){
	int L,M,R,L1;
	split(root,r,L,R);
	split(L,l-1,L1,M);
	ll ans=sumof(M);
	merge(L,L1,M);
	merge(root,L,R);
	return ans;
}

int main(){
	ropen("input.txt");
	wopen("output.txt");
	scanf("%d%d",&n,&m);
	rep(i,n+m) a[i]=i;
	random_shuffle(a,a+n+m);
	forn(i,n){
		int x;
		scanf("%d",&x);
		insert(i,x);
	}
	forn(i,m){
		int T,a,b;
		ll c;
		scanf("%d%d%d",&T,&a,&b);
		if (T<3) scanf("%I64d",&c);
		if (T==1) coloring(a,b,c);
		if (T==2) update(a,b,c);
		if (T==3) insert(a-1,b);
		if (T==4) printf("%I64d\n",get_sum(a,b));
	}
	return 0;
}