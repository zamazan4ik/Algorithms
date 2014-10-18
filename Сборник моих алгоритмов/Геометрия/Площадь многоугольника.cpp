#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <cmath>

#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef long double ld;

ll n,m,i,j,k;
vector<pair<ld,ld> > a;
ld ans=0.0;

void test()
{
    cin>>n;
    for(ll i=0;i<n;++i)
    {
        ld t1,t2;
        cin>>t1>>t2;
        a.pb(mp(t1,t2));
    }
    a.pb(mp(a[0].x,a[0].y));
    for(ll i=1;i<=n;++i)
    {
        ld h=a[i].x-a[i-1].x;
        ld ax=a[i-1].y,bx=a[i].y;
        ans+=(ax+bx)/2*h;
    }
    if(ans<0.0)
        ans=-ans;
    cout.setf(ios_base::fixed);
    cout.precision(1);
    ld b = ll(ans*10 + 0.5)/10.0;
    cout<<b;

}


int main()
{
    ios_base::sync_with_stdio(0);
    test();
    return 0;
}
