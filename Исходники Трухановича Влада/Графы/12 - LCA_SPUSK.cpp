//O(logN)+preproc(NlogN)
#include <iostream>
#include <cstdio>

using namespace std;

#define N 11111

int ef[N],es[N],first[N],next[N],n,k,c,tin[N],tout[N],timer,l=1,up[N][40];
bool b[N];

void add(int x,int y){
	next[++c]=first[x];first[x]=c;
	ef[c]=x;es[c]=y;
	next[++c]=first[y];first[y]=c;
	ef[c]=y;es[c]=x;
}

void dfs(int v,int p=1){
	b[v]=true;
	tin[v]=++timer;
	up[v][0]=p;
	for (int i=1;i<=l;i++) up[v][i]=up[up[v][i-1]][i-1];
	for (int h=first[v];h;h=next[h]) if (!b[es[h]]) dfs(es[h],v);
	tout[v]=++timer;
}

bool upper (int a, int b){
	return tin[a]<=tin[b] && tout[a]>=tout[b];
}

int lca (int a, int b) {
	if (upper(a,b)) return a;
	if (upper(b,a)) return b;
	for (int i=l;i>=0;i--) if (!upper(up[a][i],b)) a=up[a][i];
	return up[a][0];
}

void init(void){
	cin>>n>>k;
	int x,y;
	for (int i=1;i<n;i++){
		cin>>x>>y;
		add(x,y);
	}
	while ((1<<l)<=n) ++l;
	dfs(1);
}

void sol(void){
	int x,y;
	cin>>x>>y;
	cout<<lca(x,y)<<endl;
}

int main(void){
	init();
	while (k--) sol();
	return 0;
}