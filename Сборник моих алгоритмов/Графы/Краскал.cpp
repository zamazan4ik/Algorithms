#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;
typedef long long ll;

const ll maxn=100,maxm=200;
vector<ll> d(maxn,-1);
vector<pair<ll,pair<ll,ll> > > a(maxm),p;
ll i,j,k,z=0,temp,r,n,m;

ll findroot(ll v)
{
    return d[v]==-1 ? v : d[v]=findroot(d[v]);
}

bool union_set(ll a,ll b)
{
    ll q1,q2;
    q1=findroot(a);
    q2=findroot(b);
    if(q1 != q2)
    {
        r=rand() % 2;
        r==0 ? d[q1]=q2 : d[q2]=q1;
        return true;
    }
    return false;
}

void input()
{
    scanf("%I64d %I64d",&n,&m);
    for(i=0;i<m;++i)
    {
        scanf("%I64d %I64d %I64d",&a[i].second.first,&a[i].second.second,&a[i].first);
    }
}

void sol()
{
    sort(a.begin(),a.begin()+m);
    temp=n-1;
    for(i=0;i<m && z<temp;++i)
    {
        if(union_set(a[i].second.first,a[i].second.second))
        {
            ++z;
            p.push_back(a[i]);
        }
    }
}

void output()
{
    for(i=0;i<p.size();++i)
        printf("%I64d -> %I64d = %I64d\n",p[i].second.first,p[i].second.second,p[i].first);
}

int main()
{
    srand(time(0));
    input();
    sol();  
    output();  
    system("pause");
    return 0;
}
