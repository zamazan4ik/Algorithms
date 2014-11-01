#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <queue>
#include <algorithm>
#include <utility>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>

#define mp make_pair
#define pb push_back
#define x first
#define y second
#define ins insert

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

ll gcd(ll a,ll b,ll &x,ll &y)
{
    if(a == 0)
    {
        x=0;
        y=1;
        return b;
    }
    ll x1,y1,d;
    d=gcd(b%a,a,x1,y1);
    y=x1;
    x=y1-(b/a)*x1;
    return d;
}

void test()
{
    //Diophant's: ax+by=c
    ll a,b,c,x,y,nod;
    cin>>a>>b>>c;
    nod=gcd(a,b,x,y);
    if(c%nod == 0)
    {
        ll mn=c/nod;
        cout<<a*mn<<"*"<<x<<"+"<<b*mn<<"*"<<y<<" = "<<c<<endl;
    }
    else
        cout<<"No solution"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    test();
    return 0;
}
