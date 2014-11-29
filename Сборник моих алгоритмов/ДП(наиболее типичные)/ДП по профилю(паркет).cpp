#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <ctime>
#include <cmath>
#include <cctype>
#include <iterator>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pdd;

ll n, m, i, j, k;
ll f[10][1000000];

void calc(ll x,ll y,ll mask,ll next_mask)
{
    if(y>=m)    f[x+1][next_mask]+=f[x][mask];
    else
    {
        ll cur=1<<y;
        if(mask&cur)    calc(x,y+1,mask,next_mask);
        else
        {
            calc(x,y+1,mask,next_mask|cur);
            if(y+1<m && !(mask&(cur<<1)))   calc(x,y+2,mask,next_mask);
        }
    }
}

void test()
{
    cin>>n>>m;
    f[0][0]=1;
    for(ll i=0;i<n;++i)
        for(ll j=0;j<(1<<m);++j)
            calc(i,0,j,0);
    cout<<f[n][0];
}


int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	test();
	system("pause");
	return 0;
}
