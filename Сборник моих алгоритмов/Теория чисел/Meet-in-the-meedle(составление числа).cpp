#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <iterator>
#include <utility>
#include <cmath>
#include <ctime>

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

ll n,m,i,j,k,sum;
vector<ll> a;
map<ll,pii> q;

void test()
{
	cin>>n>>sum;
	a.resize(n);
	for(ll i=0;i<n;++i)
		cin>>a[i];
	for(ll i=0;i<n;++i)
		for(ll j=0;j<n;++j)
			q.ins(mp(a[i]+a[j],mp(a[i],a[j])));
	for(ll i=0;i<n;++i)
		for(ll j=0;j<n;++j)
			if(q.find(sum-a[i]-a[j]) != q.end())
			{
				cout<<a[i]<<' '<<a[j]<<' '<<q[sum-a[i]-a[j]].x<<' '<<q[sum-a[i]-a[j]].y;
				goto a;
			}
	a:;
}


int main()
{
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	test();
	return 0;
}





