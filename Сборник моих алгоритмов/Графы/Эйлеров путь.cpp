#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>

using namespace std;
typedef long long ll;

const ll maxv=1000,maxe=10000;
ll ef[maxe],es[maxe],first[maxv],next[maxe],c=0;
ll n,m,i,j,k;
vector<ll> step(maxv,0);
stack<ll> res;

void add(ll v1,ll v2)
{
	next[++c]=first[v1];first[v1]=c;
	ef[c]=v1;es[c]=v2;
}

void input()
{
	cin>>n>>m;
	for(ll i=0;i<m;++i)
	{
		ll x,y;
		cin>>x>>y;
		add(x,y);
		//add(y,x);
	}
}

bool check_or(ll &from)
{
	ll kf=0,kto=0;
	bool ok=true;
	for(ll i=1;i<=m;++i)
	{
		step[ef[i]]++;
		step[es[i]]--;
	}
	for(ll i=1;i<=n;++i)
	{
		if(step[i] <=-2 || step[i] >=2)
		{
			ok=false;
			break;
		}
		else if(step[i]==1)
		{
			from=i;
			kf++;		
		}
		else if(step[i] == -1)
		{
			kto++;
		}
	}
	if(((kf==0 && kto==0)||(kf==1 && kto==1))&&ok)
		return true;
	else
		return false;
}

bool check_neor(ll &from)
{
	ll kn=0;
	bool ok=true;
	for(ll i=1;i<=2*m;++i)
		step[ef[i]]++;
	for(ll i=1;i<=n;++i)
	{
		if(step[i]&1)
		{
			from=i;
			kn++;
		}
	}
	if(kn==0 || kn==2)
		return true;
	else 
		return false;
}

void print()
{
	while(!res.empty())
	{
		cout<<res.top()<<' ';
		res.pop();
	}
	cout<<endl;
}

ll be(ll x)
{
	if(x&1)	return x+1;
	else	return x-1;
}

void eiler(ll from)
{
	vector<char> used(maxe,0);
	stack<ll> q;
	q.push(from);
	while(!q.empty())
	{
		ll v=q.top();
		bool ok=true;
		for(ll h=first[v];h;h=next[h])
		{
			if(!used[h])
			{
				ok=false;
				used[h]=true;
				//used[be(h)]=true;
				q.push(es[h]);
				break;
			}
		}
		if(ok)
		{
			q.pop();
			res.push(v);
		}
	}
}

void test()
{
	input();
	ll from=1;
	if(check_or(from))
	{
		eiler(from);
		print();
	}
	else
		cout<<"Impossible"<<endl;
}


int main()
{
	test();
	return 0;
}
