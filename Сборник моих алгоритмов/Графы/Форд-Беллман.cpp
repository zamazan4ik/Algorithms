//Надо помнить, что если рёбра двунаправлены, то бежать по 2*m.
//И если нужно найти цикл, то просто делаем ещё 1 проход, и фиксируем булевой переменной
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;
typedef long long ll;

const ll maxv=100,maxe=10000;
ll ef[maxe],es[maxe],ev[maxe],first[maxv],next[maxe],c=0;
ll n,m,i,j,k,x,y,z,s;
vector<ll> d(maxv,100000000);
void init(ll v1,ll v2,ll val)
{
    next[++c]=first[v1];first[v1]=c;
    ef[c]=v1;es[c]=v2;ev[c]=val;
}

void ford()
{
    d[s]=0;
    for(i=1;i<n;++i)
    {
        for(j=1;j<=m;++j)
        {
            if(d[ef[j]]+ev[j]<d[es[j]])
                d[es[j]]=d[ef[j]]+ev[j];
        }
    }
}

void sol()
{
    cin>>n>>m>>s;
    for(i=0;i<m;++i)
    {
        cin>>x>>y>>z;
        init(x,y,z);
    }
    ford();
}

int main()
{
    sol();
    cout<<d[2]<<endl;
    system("pause");
    return 0;
}
