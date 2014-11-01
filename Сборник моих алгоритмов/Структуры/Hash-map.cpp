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

const ll mod=1000003;
const ll maxn=mod;

ll n,m,i,j,k;

vector<pii> h[maxn];

void h_ins(ll key,ll zn)
{
	ll pos=key%mod;
	ll len=h[pos].size();
	bool ok=true;
	for(ll i=0;i<len;++i)
	{
		if(h[pos][i].x == key)
		{
			h[pos][i].y=zn;
			ok=false;
			break;
		}
	}
	if(ok)	h[pos].pb(mp(key,zn));
}

bool h_in(ll key)
{
	ll pos=key%mod;
	ll len=h[pos].size();
	for(ll i=0;i<len;++i)
		if(h[pos][i].x == key)
			return true;
	return false;
}

ll h_val(ll key)
{
	ll pos=key%mod;
	ll len=h[pos].size();
	for(ll i=0;i<len;++i)
	{
		if(h[pos][i].x == key)
			return h[pos][i].y;
	}
}

void h_del(ll key)
{
	ll pos=key%mod;
	ll len=h[pos].size();
	for(ll i=0;i<len;++i)
	{
		if(h[pos][i].x == key)
		{
			h[pos][i]=h[pos].back();
			h[pos].pop_back();
			break;
		}
	}
}

void test()
{
	cin>>n;
	ll l,r;
	for(ll i=0;i<n;++i)
	{
		cin>>l>>r;
		h_ins(l,r);
	}
	cin>>m;
	for(ll i=0;i<m;++i)
	{
		cin>>l;
		if(h_in(l))	cout<<h_val(l)<<endl;
		else	cout<<"No"<<endl;
		h_del(l);
		if(h_in(l))	cout<<h_val(l)<<endl;
		else	cout<<"No"<<endl;
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




