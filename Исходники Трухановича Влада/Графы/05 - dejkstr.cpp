#include <iostream>
#include <cstdio>
#include <memory.h>
#define N 111
#define M 11111
#define INF 1111111111

using namespace std;

int ef[M],es[M],ev[M],next[M],first[M],d[N],s,c,n,m;
bool b[N];

void add(int x,int y, int z){
    next[++c]=first[x];first[x]=c;
    ef[c]=x;es[c]=y;ev[c]=z;
}

void init(void){
    cin>>n>>m>>s;
    int i,x,y,z;
    for (i=1;i<=m;i++){
        cin>>x>>y>>z;
        add(x,y,z);
    }
}

void dist(void){
    int i,u,mind,h,I;
    memset(d,63,sizeof(d));
    d[s]=0;
    for (I=1;I<=n;I++){
        mind=INF;          
        for (i=1;i<=n;i++)
            if (d[i]<mind && !b[i]){                      
                mind=d[i];         
                u=i;               
            }                      
        b[u]=true;
        for (h=first[u];h;h=next[h]) if (!b[es[h]]) d[es[h]]=min(d[es[h]],d[u]+ev[h]);
    }
}

int main(void){
    init();
    dist();
    for (int i=1;i<=n;i++) cout<<d[i]<<" ";
    cin>>n;
    return 0;
}
