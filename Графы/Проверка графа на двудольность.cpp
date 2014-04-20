#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;
typedef long long ll;

const ll maxn=100,maxm=10000;
ll ef[maxm],es[maxm],next[maxm],first[maxn],c=0;
ll i,j,n,m,x,y,z,h,v;
queue<ll> q;
bool used[maxn],ok=true;
char met[maxn];

void init(ll v1,ll v2)
{
    next[++c]=first[v1];first[v1]=c;
    ef[c]=v1;es[c]=v2;
}

void input()
{
    cin>>n>>m;
    for(i=0;i<m;++i)
    {
        cin>>x>>y;
        init(x,y);
        init(y,x);
    }
}

bool prov(ll k)
{
    used[k]=true;
    met[k]='1';
    q.push(k);
    while(!q.empty())
    {
        v=q.front();q.pop();
        used[v]=true;
        for(h=first[v];h;h=next[h])
        {
            if(!used[es[h]])
            {
                met[v] == '1' ? met[es[h]]='0' : met[es[h]]='1';
                q.push(es[h]);
            }
            else
            {
                if(met[v] == met[es[h]])
                    return false;
            }
        }
    }
    return true;
}

void sol()
{
    for(ll i=1;i<=n && ok;++i)
    {
        if(!used[i])
            ok=prov(i);
    }
}

int main()
{
    input();
    sol();
    for(i=1;i<=n;++i)
        cout<<met[i]<<' ';
    cout<<endl;
    cout<<ok<<endl;
    system("pause");
    return 0;
}
