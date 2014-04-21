//O(N+M)
#include <iostream>
#include <memory.h>
#include <cstdio>
#define maxn 100

using namespace std;

int ef[maxn],es[maxn],ev[maxn],next[maxn],first[maxn],c,m,n;
bool b[maxn];

void add(int v1, int v2, int v)
{
    next[++c]=first[v1];
    first[v1]=c;
    ef[c]=v1;es[c]=v2;ev[c]=v;
}

void init(void)
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);    
    cin>>n>>m;   
    int i,x,y,z;
    for (i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        add(x,y,z);
    }
}    

void dfs(int v)
{
    cout<<v<<" ";
    b[v]=true;
    for (int h=first[v];h;h=next[h]) if (!b[es[h]]) dfs(es[h]);
}

int main()
{   
    init();
    dfs(1);
    return 0;
}
