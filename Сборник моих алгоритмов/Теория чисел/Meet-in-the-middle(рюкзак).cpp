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

ll n,m,i,j,k,max_w,ans=-1;
vector<pii> a,lefti,righti;
vector<pii> ml,mr;


void test()
{
	cin>>n>>max_w;
	a.resize(n);
	ll temp=n/2;
	for(ll i=0;i<n;++i)
	{
		cin>>a[i].x>>a[i].y;
		if(i<temp)	lefti.pb(a[i]);
		else	righti.pb(a[i]);
	}
	ll kol=pow(2.0,lefti.size());
	for(ll i=0;i<kol;++i)
	{
		ll w=0,p=0;
		for(ll j=0;j<lefti.size();++j)
		{
			if(i&(1<<j))
			{
				w+=lefti[j].x,p+=lefti[j].y;
			}
		}
		ml.pb(mp(w,p));
	}
	kol=pow(2.0,righti.size());
	for(ll i=0;i<kol;++i)
	{
		ll w=0,p=0;
		for(ll j=0;j<righti.size();++j)
		{
			if(i&(1<<j))
			{
				w+=righti[j].x,p+=righti[j].y;
			}
		}
		mr.pb(mp(w,p));
	}
	sort(ml.begin(),ml.end());
	lefti.clear();
	for(ll i=1;i<ml.size();++i)
		if(!(ml[i].x >= ml[i-1].x && ml[i].y<=ml[i-1].y))
			lefti.pb(ml[i]);
	for(ll i=0;i<mr.size();++i)
	{
		ll cur_w=mr[i].x,cur_p=mr[i].y;
		ll pos=upper_bound(lefti.begin(),lefti.end(),mp(max_w-cur_w+1,-1LL))-lefti.begin()-1;
		if(pos>=0)
		{
			ll temp=cur_p+lefti[pos].y;
			ans=max(ans,temp);
		}
	}
	cout<<ans;
}


int main()
{
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	test();
	return 0;
}





