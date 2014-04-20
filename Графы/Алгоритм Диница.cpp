#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;

const ll maxv=10000,maxe=200000;
ll ef[maxe],es[maxe],ev[maxe],nexti[maxe],first[maxv],c=0;
ll n,m,s,t,i,k,j;
vector<char> good;
vector<ll> level;
queue<ll> q;

void add(ll v1,ll v2,ll val)
{
	nexti[++c]=first[v1];first[v1]=c;
	ef[c]=v1;es[c]=v2;ev[c]=val;
}

void input()
{
	cin>>n>>m;
	s=1;t=n;
	ll x,y,z;
	for(ll i=0;i<m;++i)
	{
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,0);
	}
}

void bfs()
{
	level[s]=1;
	q.push(s);
	while(!q.empty())
	{
		ll v=q.front();q.pop();
		for(ll h=first[v];h;h=nexti[h])
		{
			if(ev[h]>0 && level[es[h]] == 0)
			{
				level[es[h]]=level[v]+1;
				q.push(es[h]);
			}
		}
	}
}

ll be(ll x)
{
	if(x & 1)	return x+1;
	else	return x-1;
}

ll dfs(ll v,ll flow)
{
	if(v == t)	return flow;
	ll temp=0,res=0;
	for(ll h=first[v];h && flow>0;h=nexti[h])
	{
		if(ev[h]>0 && level[es[h]] == level[v]+1 && !good[es[h]])
		{
			temp=dfs(es[h],min(flow,ev[h]));
			if(temp == 0)
				good[es[h]]=true;
			res+=temp;
			flow-=temp;
			ev[h]-=temp;
			ev[be(h)]+=temp;
		}
	}
	return res;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt",W',stdout);
	//ios_base::sync_with_stdio(0);
	input();
	ll flow=0,ans=0;
	do
	{
		level.clear();
		level.resize(n+3);
		good.clear();
		good.resize(m*2+7);
		bfs();
		ans=dfs(s,999999999LL);
		flow+=ans;
	}
	while(ans);
	cout<<flow;
	//system("pause");
	return 0;
}
