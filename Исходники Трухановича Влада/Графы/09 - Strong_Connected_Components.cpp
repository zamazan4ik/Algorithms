//O(N+M)
#include <iostream>
#include <cstdio>
#include <memory.h>
#define maxn 111
#define maxm 2222

using namespace std;

int ef[maxn],es[maxn],next[maxn],first[maxn],Tef[maxn],Tes[maxn],Tnext[maxn],Tfirst[maxn],c,Tc,n,m,k,Tk,order[maxn],comp[maxn];
bool used[maxn];

void add(int x,int y)
{
    next[++c]=first[x];first[x]=c;
    ef[c]=x;es[c]=y;
}

void Tadd(int x,int y)
{
    Tnext[++Tc]=Tfirst[x];Tfirst[x]=Tc;
    Tef[Tc]=x;Tes[Tc]=y;
}

void dfs(int v)
{
    used[v]=true;
    for (int h=first[v];h;h=next[h])
        if (!used[es[h]])
            dfs(es[h]);
    order[++k]=v;
}

void Tdfs(int v)
{
    used[v]=true;
    comp[++Tk]=v;
    for (int h=Tfirst[v];h;h=Tnext[h])
        if (!used[Tes[h]])
            Tdfs(Tes[h]);
}

void init(void)
{
//   freopen("input.txt","r",stdin);
//   freopen("output.txt","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        Tadd(y,x);
    }
}

void sol(void)
{
    int i;
    memset(used,0,sizeof(used));
    for (i=1;i<=n;i++)
        if (!used[i])
            dfs(i);
    memset(used,0,sizeof(used));
    for (i=1;i<=n;i++)
    {
        int v=order[n-i+1];
        if (!used[v])
            Tdfs(v);
        for (int j=1;j<=Tk;j++)
            cout<<comp[j]<<" ";
        if (Tk)
            cout<<endl;
        Tk=0;
    }
}
   
int main(void)
{
    init();
    sol();
    cin>>n;
    return 0;
}
