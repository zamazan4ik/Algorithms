#include <cstdio>
#include <iostream>
#define maxn 111
#define maxm 2222

using namespace std;

int ef[maxm],es[maxm],next[maxm],first[maxn],ei[maxn],c,m,n,ptr;


void add(int v1, int v2){
    next[++c]=first[v1];first[v1]=c;
    ef[c]=v1;es[c]=v2;
}

int be(int x){
    if (x&1) return x+1;
    else return x-1;
}

void init(void){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout); 
    cin>>n>>m;
    int i,x,y;
    for (i=1;i<=m;i++){
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    m<<=1;
}    


void eiler(int v){
    for (int h=first[v];h;h=next[h]){
        int e=es[h];
        ef[h]=es[h]=ef[be(h)]=es[be(h)]=0;
        eiler(e);
    }
    if (v!=0)ei[++ptr]=v;
}

void sol(void){
    eiler(1);
    for (int i=ptr;i>=1;i--)
        cout<<ei[i]<<" ";
}

int main(){   
    init();
    sol();
    cin>>n;
    return 0;
}
    
