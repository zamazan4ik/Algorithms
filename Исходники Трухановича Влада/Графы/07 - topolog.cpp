// O(N+M)
#include <cstdio>
#include <iostream>
#include <memory.h>
#define maxn 111
#define maxm 2222

using namespace std;

int ef[maxm],es[maxm],next[maxm],first[maxn],top[maxn],c,m,n,ptr;
bool b[maxn];

void add(int v1, int v2)
{
    next[++c]=first[v1];
    first[v1]=c;
    ef[c]=v1;es[c]=v2;
}

void init(void)
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout); 
    cin>>n>>m;    
    int i,x,y;
    for (i=1;i<=m;i++)
    {
        cin>>x>>y;
        add(x,y);
    }
}    


void dfs(int v)
{
    b[v]=true;
    for (int h=first[v];h;h=next[h])
        if (!b[es[h]])
            dfs(es[h]);
    top[++ptr]=v;
}

void sol(void)
{
    int i;
    for (i=1;i<=n;i++)
    {
        if (!b[i])
            dfs(i);
    }
    for (i=ptr;i>=1;i--)
        cout<<top[i]<<" ";
}    

int main()
{   
    init();
    sol();
    cin>>n;
    return 0;
}
    
