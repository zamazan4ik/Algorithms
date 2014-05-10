//Топологическая сортировка графа
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
typedef long long ll;


const ll maxv=10000,maxe=200000;
ll ef[maxe],es[maxe],ev[maxe],nexti[maxe],first[maxv],c=0;
ll n,m,s,t,i,j,k;
vector<char> used;
stack<ll> ans;

void add(ll v1,ll v2,ll val=3)
{
	nexti[++c]=first[v1];first[v1]=c;
	ef[c]=v1;es[c]=v2;ev[c]=val;
}

void input()
{
	cin>>n>>m;
	ll x,y;
	for(ll i=0;i<m;++i)
	{
		cin>>x>>y;
		add(x,y);
	}
}

void dfs(ll v)
{
	used[v]=true;
	for(ll h=first[v];h;h=nexti[h])
		if(!used[es[h]])
			dfs(es[h]);
	ans.push(v);
}

void top_sort()
{
	used.resize(n+2);
	for(ll i=1;i<=n;++i)
		if(!used[i])
			dfs(i);
	ll s=1;
	while(!ans.empty())
	{
		cout<<ans.top()<<"=>"<<s++<<endl;
		ans.pop();
	}
}


int main()
{
	input();
	top_sort();
	system("pause");
	return 0;
}
