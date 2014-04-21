#include <cstdio>
#include <iostream>
#include <memory.h>
#include <queue>
#define maxn 111
#define maxm 2222
#define INF 1061109567

using namespace std;

int first[maxn],ev[maxm],next[maxm],es[maxm],d[maxn],ef[maxm],S,n,m,c;

void add(int x, int y, int z){
    next[++c]=first[x];
    first[x]=c;
    ef[c]=x;es[c]=y;ev[c]=z;
}

struct pairr{
	int x,y;
	bool operator <(const pairr& p) const{
		return y>p.y;
	}
};

priority_queue<pairr> q;

void dist(int s){
    d[s]=0;
    pairr t,w;
    t.x=s;t.y=0;
    q.push(t);
    while (!q.empty()){
	t=q.top();
        q.pop();
	if (d[t.x]<t.y) continue;
	for (int h=first[t.x];h;h=next[h])
		if (d[es[h]]>t.y+ev[h]){
			d[es[h]]=t.y+ev[h];
			w.x=es[h];w.y=d[w.x];
			q.push(w);
		}
	}       
}

void init(void){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);  
    cin>>n>>m>>S; 
    int i,x,y,z,j;
    for (i=1;i<=m;i++){
        cin>>x>>y>>z;
        add(x,y,z);
    }
    memset(d,63,sizeof(d));
}

void sol(void){
    dist(S);
    for (int i=1;i<=n;i++)
        cout<<d[i]<<" ";
}

int main(){
    init();
    sol();
    cin>>n;
    return 0;
}
