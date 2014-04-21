// O(?)
#include <cstdio>
#include <iostream>
#include <memory.h>
#include <queue>
#define maxn 111
#define maxm 2222
#define INF 1061109567

using namespace std;

int first[maxn],next[maxm],es[maxm],ev[maxm],ef[maxm],scale,edge[maxn],from[maxn],n,m,c,S,T,ans;
bool b[maxn];

void add(int v1, int v2, int v){
    next[++c]=first[v1];first[v1]=c;
    ef[c]=v1;es[c]=v2;ev[c]=v;
}

int be(int x){
	if (x&1) return x+1;
	else return x-1;
}

void init(void){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);  
    cin>>n>>m>>S>>T; 
    int i,v1,v2,v;
    for (i=1;i<=m;i++){
        cin>>v1>>v2>>v;
        add(v1,v2,v);
        add(v2,v1,0);
        scale=max(scale,v);
    }
}

bool flow(){
	memset(b,0,sizeof(b));
	queue<int> q; 
	q.push(S);
	b[S]=true;
	while (!q.empty()){                      
		int x=q.front();q.pop();
		for (int h=first[x];h;h=next[h]) if (ev[h]>=scale && !b[es[h]]){
			edge[es[h]]=h;
                	from[es[h]]=x;
			q.push(es[h]);
	                b[es[h]]=true;
			if (es[h]==T) return 1;
		}
	}
	return 0;
}

void sol(void){
	int res=INF;
	while (scale){
		while (flow()){ 
			res=INF;
			for (int h=T;h!=S;h=from[h]) res=min(res,ev[edge[h]]);
			for (int h=T;h!=S;h=from[h]){
				ev[edge[h]]-=res;
				ev[be(edge[h])]+=res;
			}
			ans+=res;
		}
		scale>>=1;
	}    
	cout<<ans;
}

int main(){
    init();
    sol();
    cin>>n;
    return 0;
}
