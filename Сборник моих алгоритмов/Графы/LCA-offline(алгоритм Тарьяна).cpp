#pragma comment(linker, "/STACK:65777216")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <cctype>
#include <ctime>
#include <utility>
#include <iomanip>
#include <string>
#include <cstring>

#define mp make_pair
#define pb push_back
#define x first
#define y second
#define ins insert

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pdd;
typedef vector<ll> lnum;


const ll maxv=500007,maxe=maxv*2;
ll n, m, i, j, k;
ll es[maxe],ef[maxe],nex[maxe],first[maxv],c=0;
vector<ll> sp;
vector<vector<pii> > zap(maxv);
vector<ll> d(maxv,-1),anc(maxv,-1);
vector<char> used(maxv,false);

void add(ll v1,ll v2)
{
	nex[++c]=first[v1];first[v1]=c;
	ef[c]=v1;es[c]=v2;
}

ll findroot(ll x)
{
	return d[x] == x ? x : d[x]=findroot(d[x]);
}

void union_set(ll v1,ll v2,ll newanc)
{
	ll q1=findroot(v1),q2=findroot(v2);
	if(q1 != q2)
	{
		if(rand() & 1)	swap(q1,q2);
		d[q1]=q2;	anc[q2]=newanc;
	}
}

void dfs(ll v)
{
	d[v]=v;anc[v]=v;used[v]=true;
	for(ll h=first[v];h;h=nex[h])
	{
		if(!used[es[h]])
		{
			dfs(es[h]);
			union_set(v,es[h],v);
		}
	}
	for(ll i=0;i<zap[v].size();++i)
	{
		if(used[zap[v][i].x])
		{
			sp[zap[v][i].y]=anc[findroot(zap[v][i].x)];
		}
	}
}

void test()
{
	cin>>n;
	string s;
	ll left,right;
	for(ll i=0;i<n;++i)
	{
		cin>>s>>left>>right;
		if(s == "ADD")
		{
			add(left,right);
			add(right,left);
		}
		else
		{
			sp.pb(0);
			zap[left].pb(mp(right,sp.size()-1));
			zap[right].pb(mp(left,sp.size()-1));
		}
	}
	dfs(1);
	for(ll i=0;i<sp.size();++i)
	{
		cout<<sp[i]<<'\n';
	}
}


int main()
{
	srand(time(0));
	ios_base::sync_with_stdio(0);
	test();
	return 0;
}




