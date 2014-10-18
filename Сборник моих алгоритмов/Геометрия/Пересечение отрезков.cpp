#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>


#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

ll n,m,i,j,k,xt,yt;
pair<ll,ll> t1,t2,t3,t4;

bool bounding_box(ll x1,ll x2,ll x3,ll x4)
{
    if(x1>x2)   swap(x1,x2);
    if(x3>x4)   swap(x3,x4);
    if((x1 <= x4 && x4<=x2) || (x1 <= x3 && x3 <= x2) || (x3<=x1 && x1<=x4) || (x3<=x2 && x2<=x4))
        return true;
    else
        return false;
}

bool peresec(pii x1,pii x2,pii x3,pii x4)
{
    ll lenx=x1.x-x2.x,leny=x1.y-x2.y;
    ll temp1x=x1.x-x3.x,temp1y=x1.y-x3.y;
    ll temp2x=x1.x-x4.x,temp2y=x1.y-x4.y;
    ll znak1=lenx*temp1y-temp1x*leny,znak2=lenx*temp2y-temp2x*leny;
    if(znak1 == 0 || znak2 == 0 || (znak1 < 0 && znak2>0) || (znak1>0 && znak2<0))
        return true;
    else
        return false;
}

void test()
{
    cin>>t1.x>>t1.y>>t2.x>>t2.y>>t3.x>>t3.y>>t4.x>>t4.y;
    if(bounding_box(t1.x,t2.x,t3.x,t4.x) && bounding_box(t1.y,t2.y,t3.y,t4.y))
    {
        if(peresec(t1,t2,t3,t4) && peresec(t3,t4,t1,t2))
            cout<<"Yes";
        else
            cout<<"No";
    }
    else
        cout<<"No";
}


int main()
{
    ios_base::sync_with_stdio(0);
    test();
    return 0;
}
