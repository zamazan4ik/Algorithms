#include <cstdio>
#include <iostream>
#include <memory.h>
#define maxn 111
#define maxm 2222

using namespace std;

int ef[maxn],es[maxn],ev[maxn],next[maxn],first[maxn],a[maxn],c,m,n,s;
bool cicle;

void add(int v1, int v2, int v){
    next[++c]=first[v1];first[v1]=c;
    ef[c]=v1;es[c]=v2;ev[c]=v;
}

void init(void){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);  
    cin>>n>>m>>s; 
    int i,x,y,z,j;
    for (i=1;i<=m;i++){
        cin>>x>>y>>z;
        add(x,y,z);
    }
    memset(a,63,sizeof(a));
}

void ford(int vv){
    int i,j;
    a[vv]=0;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
                if (a[es[j]]>a[ef[j]]+ev[j])
                    a[es[j]]=a[ef[j]]+ev[j];
    cicle=false;
    for (j=1;j<=m;j++)
        if (a[es[j]]>a[ef[j]]+ev[j]){        
            cicle=true;
            break;
        }
}

void sol(void){
    int i,j;
    ford(s);
    for (i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<endl;
    cout<<cicle;
}

int main(){
    init();
    sol();
    cin>>n;
    return 0;
}
    
