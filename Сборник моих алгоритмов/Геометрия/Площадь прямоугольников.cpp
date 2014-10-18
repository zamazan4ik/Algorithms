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
typedef pair<pair<ll,ll>,pair<ll,ll> > points;

ll n,m,i,j,k,ans=0;
set<ll> forx,fory;
vector<ll> ax,ay;
vector<points> arr;

bool check(ll dx,ll dy)
{
    for(ll i=0;i<n;++i)
        if(dx>=arr[i].x.x && dx<arr[i].y.x && dy>=arr[i].x.y && dy<arr[i].y.y)
            return true;
    return false;
}

void test()
{
    cin>>n;
    ll temp;
    arr.resize(n);
    ll dx1,dx2,dy1,dy2;
    for(ll i=0;i<n;++i)
    {
        cin>>dx1>>dy1>>dx2>>dy2;
        if(dx1>dx2) swap(dx1,dx2);
        if(dy1>dy2) swap(dy1,dy2);
        forx.ins(dx1);forx.ins(dx2);
        fory.ins(dy1);fory.ins(dy2);
        arr[i].x.x=dx1;arr[i].x.y=dy1;
        arr[i].y.x=dx2;arr[i].y.y=dy2;
    }
    for(set<ll>::iterator it=forx.begin();it !=forx.end();++it)
        ax.pb(*it);
    for(set<ll>::iterator it=fory.begin();it !=fory.end();++it)
        ay.pb(*it);
    sort(ax.begin(),ax.end());
    sort(ay.begin(),ay.end());
    for(ll i=0;i<ax.size()-1;++i)
    {
        for(ll j=0;j<ay.size()-1;++j)
        {
            if(check(ax[i],ay[j]))
            {
                ans+=(ax[i+1]-ax[i])*(ay[j+1]-ay[j]);
            }
        }
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    test();
    return 0;
}
