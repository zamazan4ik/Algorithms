#include <iostream>
#include <algorithm>
#include <queue>
#define INF (1<<30)
#define M 222222
#define N 1111
using namespace std;

int ef[M],es[M],ev[M],next[M],first[N],c,n,m,d[N],s,t,ans,l[N],last[N];

void add(int x,int y,int z){
	next[++c]=first[x];first[x]=c;
	ef[c]=x;es[c]=y;ev[c]=z;
}

int be(int x){
	if (x&1) return x+1;
	return x-1;
}

void bfs(void){
	queue<int> q;q.push(s);
	memset(l,63,sizeof(l));
	l[s]=0;
	while (!q.empty()){
		int v=q.front();q.pop();
		for (int h=first[v];h;h=next[h])
			if (l[es[h]]>l[v]+1 && ev[h]>0){
				l[es[h]]=l[v]+1;
				q.push(es[h]);
			}
	}
}

int dfs(int v,int f=INF){
	if (v==t) return f;
	int res=0;
	if (last[v]==-1) last[v]=first[v];
	else last[v]=next[last[v]];
	for (;last[v];last[v]=next[last[v]]){
		int h=last[v];
		if (ev[h]>0 && l[es[h]]==l[v]+1){
			int ans=dfs(es[h],min(ev[h],f));
			ev[h]-=ans;
			ev[be(h)]+=ans;
			res+=ans;
			f-=ans;
			if (f==0) break;
		}
	}
	return res;
}

void init(void){
	cin>>n>>m>>s>>t; 
	for (int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,0);
	}                       
}

int main(void){
	init();
	int cur;
	do{                   
		bfs();
		for (int i=1;i<=n;i++) last[i]=-1;
		cur=dfs(s);		
		ans+=cur;
	}while (cur);
	cout<<ans;
	return 0;
}