#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cstring>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ld> pdd;

const ll maxn=100;

ll n,m,i,j,k;
ll t[maxn][maxn];

ll prev(ll x)
{
    return (x&(x+1))-1;
}

ll next(ll x)
{
    return x|(x+1);
}

ll sum(ll x,ll y)
{
    ll res=0;
    for(ll i=x;i>0;i=prev(i))
    {
        for(ll j=y;j>0;j=prev(j))
        {
            res+=t[i][j];
        }
    }
    return res;
}

ll getsum(ll xl,ll xr,ll yl,ll yr)
{
    return sum(xr,yr)-sum(xr,yl-1)-sum(xl-1,yr)+sum(xl-1,yl-1);
}

void update(ll x,ll y,ll val)
{
    for(ll i=x;i<=n;i=next(i))
    {
        for(ll j=y;j<=m;j=next(j))
        {
            t[i][j]+=val;
        }
    }
}

void test()
{
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;++i)
    {
        for(ll j=1;j<=m;++j)
        {
            scanf("%lld",&k);
            update(i,j,k);
        }
    }
    scanf("%lld",&k);
    for(ll i=0;i<k;++i)
    {
        ll xl,xr,yl,yr;
        scanf("%lld%lld%lld%lld",&xl,&yl,&xr,&yr);
        printf("%lld\n",getsum(xl,xr,yl,yr));
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    test();
    return 0;
}
