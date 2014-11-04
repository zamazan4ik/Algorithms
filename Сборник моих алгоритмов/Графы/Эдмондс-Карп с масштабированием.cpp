#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <cctype>
#include <ctime>
#include <iterator>


#define x first
#define y second
#define pb pus_back
#define mp make_pair
#define ins insert

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ld> pdd;

const ll maxv=1000,maxe=maxv*maxv*2+7;
const ll inf=1e9;

ll n,m,i,j,k,c=0,s,t,scale=-inf,ans=0;
ll es[maxe],first[maxv],nexti[maxe],from[maxv],edge[maxv],flow[maxe];
vector<char> used;

void add(ll v1,ll v2,ll val)
{
	nexti[++c]=first[v1];first[v1]=c;
	es[c]=v2;flow[c]=val;
}

ll be(ll x)
{
	if(x&1)	return x+1;
	else	return x-1;
}

void input()
{
	cin>>n>>m;
	s=1;t=n;
	used.resize(n+7);
	ll x,y,z;
	for(ll i=0;i<m;++i)
	{
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,0);
		scale=max(scale,z);
	}
}

bool path()
{
	fill(used.begin(),used.end(),0);
	queue<ll> q;
	q.push(s);
	used[s]=true;
	while(!q.empty())
	{	
		ll v=q.front();q.pop();
		for(ll h=first[v];h;h=nexti[h])
		{
			if(flow[h]>=scale && !used[es[h]])
			{
				used[es[h]]=true;
				q.push(es[h]);
				from[es[h]]=v;
				edge[es[h]]=h;
				if(es[h] == t)	return true;
			}
		}
	}
	return false;
}

void test()
{
	input();
	while(scale)
	{
		while(path())
		{
			ll res=inf;
			for(ll x=t;x!=s;x=from[x])	res=min(res,flow[edge[x]]);
			for(ll x=t;x!=s;x=from[x])
			{
				flow[edge[x]]-=res;
				flow[be(edge[x])]+=res;
			}
			ans+=res;
		}
		scale>>=1;
	}
	cout<<ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	test();
	return 0;
}
