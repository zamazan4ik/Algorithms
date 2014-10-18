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

#define mp make_pair
#define pb push_back
#define x first
#define y second
#define ins insert
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ld,ld> pii;

ll n,m,i,j,k;
vector<pii> a;

void test()
{
    cin>>n;
    a.resize(n);
    for(ll i=0;i<n;++i)
        cin>>a[i].x>>a[i].y;
    sort(a.begin(),a.end());
    ll cur=0,next;
    ld dx=-1,dy=0,ans=0,dcos=-2,dlen=0.0;
    do
    {
        for(ll i=0;i<n;++i)
        {
            ld sp=dx*(a[i].x-a[cur].x)+dy*(a[i].y-a[cur].y);
            ld tlen=sqrt(pow(a[i].x-a[cur].x,2.0)+pow(a[i].y-a[cur].y,2.0));
            ld tcos=sp/tlen;
            if(tcos >= dcos)
            {
                if(tcos == dcos)
                {
                    if(tlen > dlen)
                    {
                        next=i;
                        dlen=tlen;
                    }
                }
                else
                {
                    dcos=tcos;
                    dlen=tlen;
                    next=i;
                }
            }
        }
        ans+=dlen;
        dx=(a[next].x-a[cur].x)/dlen;
        dy=(a[next].y-a[cur].y)/dlen;
        cur=next;
        dcos=-2;
        dlen=0;
    }
    while(cur != 0);
    cout.setf(ios_base::fixed);
    cout.precision(1);
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    test();
    return 0;
}
