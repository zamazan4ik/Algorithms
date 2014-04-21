#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

ll n,s,t,k;
ll p[3]={2,7,61};

ll mulmod(ll x,ll y,ll n)
{
    ll res=0;
    while(y)
    {
        if(y&1) res=(res+x)%n;
        x=(x+x)%n;
        y>>=1;
    }
    return res;
}

ll powmod(ll x,ll y,ll n)
{
    ll res=1;
    while(y)
    {
        if(y&1) res=mulmod(res,x,n);
        x=mulmod(x,x,n);
        y>>=1;
    }
    return res;
}


bool miller(ll s,ll t,ll a)
{
    ll x=powmod(a,t,n);
    if(x==1 || x==n-1)  return true;
    for(ll j=1;j<s;++j)
    {
        x=mulmod(x,x,n);
        if(x==1)    return false;
        if(x==n-1)  return true;
    }
    return false;
}

bool del()
{
    ll temp=sqrt(n);
    for(ll i=2;i<=temp;++i)
        if(n%i==0)
            return false;
    return true;
}

bool check()
{
    if(n<=1)    return false;
    if(n==2)    return true;
    if(n<=100)  return del();
    t=n-1;
    while(!(t&1))
    {
        ++s;
        t>>=1;
    }
    bool ok=true;
    for(ll j=0;j<3 && ok;++j)
        ok=miller(s,t,p[j]);
    return ok;
}


int main()
{
    cin>>n;
    cout<<check()<<endl;
    system("pause");
    return 0;
}
