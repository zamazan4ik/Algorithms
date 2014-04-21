#include <iostream>
#include <cstdio>
#define maxn 100

using namespace std;

int ef[maxn],es[maxn],ev[maxn],next[maxn],first[maxn],last[maxn],c,m,n;

void add(int v1, int v2, int v){
    next[++c]=first[v1];
    first[v1]=c;
    ef[c]=v1;es[c]=v2;ev[c]=v;
}

void init(void){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    cin>>n>>m; 
    c=0;   
    int i,x,y,z;
    for (i=1;i<=m;i++){
        cin>>x>>y>>z;
        add(x,y,z);
    }    
}

void sol(void){
    for (int i=1;i<=n;i++){
        for (int h=first[i];h;h=next[h]) cout<<es[h]<<" ";
        cout<<endl;
    }
}

int main(){
    init();
    sol();
    return 0;
}
