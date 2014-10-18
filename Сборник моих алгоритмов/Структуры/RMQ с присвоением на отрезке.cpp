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
const ll maxi=100000000LL;
struct tree
{
    bool color=false;
    ll x=-maxi;
};

ll n,m,i,j,k;
tree t[4*maxn];
ll a[maxn];

void build(ll v,ll tl,ll tr)
{
    if(tl == tr)    t[v].x=a[tl];
    else
    {
       ll tm=(tl+tr)>>1;
       build(v<<1,tl,tm);
       build((v<<1)+1,tm+1,tr);
       t[v].x=max(t[v<<1].x,t[(v<<1)+1].x);
    }
}

void push(ll v)
{
    if(t[v].color)
    {
        t[v].color=false;
        t[v<<1].color=t[(v<<1)+1].color=true;
        t[v<<1].x=t[(v<<1)+1].x=t[v].x;
    }
}

ll getmax(ll v,ll tl,ll tr,ll l,ll r)
{
    if(l>r) return -maxi;
    if(tl == l && tr == r)  return t[v].x;
    push(v);
    ll tm=(tl+tr)>>1;
    return max(getmax(v<<1,tl,tm,l,min(tm,r)),getmax((v<<1)+1,tm+1,tr,max(l,tm+1),r));
}

void update(ll v,ll tl,ll tr,ll l,ll r,ll val)
{
    if(l>r)return;
    if(tl == l && tr == r)  t[v].x=val,t[v].color=true;
    else
    {
        push(v);
        ll tm=(tl+tr)>>1;
        update(v<<1,tl,tm,l,min(r,tm),val);
        update((v<<1)+1,tm+1,tr,max(l,tm+1),r,val);
        t[v].x=max(t[v<<1].x,t[(v<<1)+1].x);
    }
}

void test()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;++i)
        scanf("%lld",&a[i]);
    build(1,1,n);
    scanf("%lld",&k);
    for(ll i=0;i<k;++i)
    {
        ll left,right,c,val;
        scanf("%lld",&c);
        if(c == 1)
        {
            scanf("%lld%lld%lld",&left,&right,&val);
            update(1,1,n,left,right,val);
        }
        else
        {
            scanf("%lld%lld",&left,&right);
            printf("%lld",getmax(1,1,n,left,right));
        }
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
