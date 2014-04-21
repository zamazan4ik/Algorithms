#include <cstdio>
#include <algorithm>
#include <vector>
#define forn(I,B) for (int I=1;I<=(B);I++)
#define rep(I,B) for (int I=0;I<(B);I++) 
#define rwopen(X) freopen(X".in","r",stdin);freopen(X".out","w",stdout)
#define pb push_back

using namespace std;

typedef vector<int> vi;
const int N=100001;
const int M=200000;
const int L=16;

struct tree{
	int l,r,add,sum;
};

int ef[M],es[M],next[M],first[N],up[N][L+1],tin[N],tout[N],n,m,c,timer,f[N],cw,where[N],num[N],i,h[N];
bool b[N];
vi ways[N];
vector<tree> RSQ[N];

inline void add(int x,int y){
	next[++c]=first[x];first[x]=c;
	es[c]=y;ef[c]=x;
	next[++c]=first[y];first[y]=c;
	es[c]=x;ef[c]=y;
}

inline bool upper(int a,int b){
	return tin[a]<=tin[b] && tout[a]>=tout[b];
}

void calc_up(int v,int p=1){
	up[v][0]=p;f[v]=1;
	tin[v]=++timer;
	for (i=1;i<=L;i++) up[v][i]=up[up[v][i-1]][i-1];
	for (h[v]=first[v];h[v];h[v]=next[h[v]]) if (es[h[v]]!=p){
		calc_up(es[h[v]],v);
		f[v]+=f[es[h[v]]];
	}
	for (h[v]=first[v];h[v];h[v]=next[h[v]]) if (es[h[v]]!=p && f[es[h[v]]]>f[v]/2){
		b[v]=1;
		break;
	}
	tout[v]=++timer;
}

inline int lca(int a,int b){
	if (upper(a,b)) return a;
	if (upper(b,a)) return b;
	for (int i=L;i>=0;--i) if (!upper(up[a][i],b)) a=up[a][i];
	return up[a][0];
}

inline int get(vector<tree> & t,int v,int sumadd=0){
	return t[v].sum+(t[v].r-t[v].l+1)*(t[v].add+sumadd);
}

void build(vector<tree> & t,int v,int l,int r){
	t[v].l=l;t[v].r=r;t[v].add=t[v].sum=0;
	if (l!=r){
		build(t,v+v,l,(l+r)/2);
		build(t,v+v+1,(l+r)/2+1,r);
	}
}

void inc(vector<tree> & t,int v,int l,int r){
	if (t[v].l>r || t[v].r<l) return;
	if (t[v].l>=l && t[v].r<=r) ++t[v].add;
	else {
		inc(t,v+v,l,r);
		inc(t,v+v+1,l,r);
		t[v].sum=get(t,v+v)+get(t,v+v+1);
	}
}

int get_sum(vector<tree> & t,int v,int l,int r,int sumadd=0){
	if (t[v].l>r || t[v].r<l) return 0;
	if (t[v].l>=l && t[v].r<=r) return get(t,v,sumadd);
	return get_sum(t,v+v,l,r,sumadd+t[v].add)+get_sum(t,v+v+1,l,r,sumadd+t[v].add);
}

inline void hldot(int v){
	int k=0;
	ways[++cw].pb(v);
	where[v]=cw;
	num[v]=k++;
	for(;v!=1;){
		int p=up[v][0];
		if (f[v]<=f[p]/2) break;
		ways[cw].pb(p);
		where[p]=cw;
		num[p]=k++;
		v=p;
	}
	RSQ[cw].resize(4*k);
	build(RSQ[cw],1,0,k-1);
}

inline int get_count(int a,int b){
	int lc=lca(a,b),v,ans=0;
	if (lc==b) swap(a,b);
	v=b;
	for(;v!=lc;){
		if (where[v]!=where[lc]){
			ans+=get_sum(RSQ[where[v]],1,num[v],ways[where[v]].size()-1);
			v=up[ways[where[v]].back()][0];
		} else {
			ans+=get_sum(RSQ[where[v]],1,num[v],num[lc]-1);
			break;
		}
	}
	if (lc!=a){
		swap(a,b);
		v=b;
		for(;v!=lc;){
			if (where[v]!=where[lc]){
				ans+=get_sum(RSQ[where[v]],1,num[v],ways[where[v]].size()-1);
				v=up[ways[where[v]].back()][0];
			} else {
				ans+=get_sum(RSQ[where[v]],1,num[v],num[lc]-1);
				break;
			}
		}
	}
	return ans;
}

inline void plaint(int a,int b) {
	int lc=lca(a,b),v;
	if (lc==b) swap(a,b);
	v=b;
	for (;v!=lc;){
		if (where[v]!=where[lc]){
			inc(RSQ[where[v]],1,num[v],ways[where[v]].size()-1);
			v=up[ways[where[v]].back()][0];
		} else {
			inc(RSQ[where[v]],1,num[v],num[lc]-1);
			break;
		}
	}
	if (lc!=a){
		swap(a,b);
		v=b;
		for (;v!=lc;){
			if (where[v]!=where[lc]){
				inc(RSQ[where[v]],1,num[v],ways[where[v]].size()-1);
				v=up[ways[where[v]].back()][0];
			} else {
				inc(RSQ[where[v]],1,num[v],num[lc]-1);
				break;
			}
		}
	}
}

int main(){
	rwopen("grassplant");
	scanf("%d%d\n",&n,&m);
	forn(i,n-1){
		int a,b;
		scanf("%d%d\n",&a,&b);
		add(a,b);
	}
	calc_up(1);
	forn(i,n) if (i!=1 && !b[i]) hldot(i);
	forn(i,m){
		char c;int a,b;
		scanf("%c %d %d\n",&c,&a,&b);
		if (c=='P') plaint(a,b);
		else printf("%d\n",get_count(a,b));
	}
	return 0;
}
