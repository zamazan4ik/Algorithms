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
	int x,y;
	treap *l,*r;
	treap(){}
	treap(int x,int y) :x(x),y(y),l(NULL),r(NULL){};
};
typedef treap* ptreap;

ptreap root;
int a[N],c,n;

void split (ptreap t, int x, ptreap & l, ptreap & r) {
	if (!t)	l=r=NULL;
	else if (x<t->x) split(t->l,x,l,t->l),r=t;
	else split(t->r,x,t->r,r),l=t;
}

void insert (ptreap & t, ptreap it) {
	if (!t)	t = it;
	else if (it->y>t->y) split (t,it->x,it->l,it->r),  t=it;
	else insert(it->x<t->x?t->l:t->r,it);
}

void merge (ptreap & t, ptreap l, ptreap r) {
	if (!l || !r) t=l?l:r;
	else if (l->y>r->y) merge(l->r,l->r, r),t=l;
	else merge(r->l,l,r->l),t=r;
}

void erase (ptreap & t, int x) {
	if (t->x==x) merge (t,t->l,t->r);
	else erase(x<t->x?t->l:t->r,x);
}

void print(ptreap x){
	if (x==NULL) return;
	print(x->l);
	cout<<x->x<<" ";
	print(x->r);
}

int main(){
	cin>>n;
	forn(i,n) a[i]=i;
	forn(i,n){
		int x;
		cin>>x;
		ptreap q = new treap(x,a[++c]);
		insert(root,q);
	}
	print(root);
}