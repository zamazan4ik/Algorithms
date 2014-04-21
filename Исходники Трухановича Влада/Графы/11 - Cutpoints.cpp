//O(N+M)
#include <iostream>
#include <cstdio>
#define maxn 111
#define maxm 2222

using namespace std;

int ef[maxm],es[maxm],next[maxm],first[maxn],tin[maxn],fup[maxn],timer,c,n,m;
bool used[maxn];

void add(int v1,int v2)
{
    next[++c]=first[v1];
    first[v1]=c;
    ef[c]=v1;
    es[c]=v2;
}

void dfs(int v,int p=-1)
{
    used[v]=true;
    tin[v]=fup[v]=timer++;
    int children=0;
    for (int h=first[v];h;h=next[h])
    {
        if (es[h]==p)
            continue;
        if (used[es[h]])
            fup[v]=min(fup[v],tin[es[h]]);
        else
        {
            dfs(es[h],v);
            fup[v]=min(fup[v],fup[es[h]]);
            if (fup[es[h]]>=tin[v] && p!=-1)
                cout<<v<<endl;
            ++children;
        }
    }
    if (p==-1 && children>1)
        cout<<v<<endl;
}

void init(void)
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    m<<=1;
}

int main(void)
{
    init();
    dfs(1);
    cin>>n;
    return 0;
}
