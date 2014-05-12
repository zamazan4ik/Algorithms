#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;

const ll maxn=10000;
ll t[maxn],a[maxn];
ll n,m,i,j,k;

void input()
{
	cin>>n;
	for(ll i=1;i<=n;++i)
		cin>>a[i];
}

ll next(ll x)
{
	return x|(x+1);
}

ll prev(ll x)
{
	return x&(x+1);
}

void add(ll pos,ll val)
{
	a[pos]+=val;
	while(pos<=n)
	{
		t[pos]+=val;
		pos=next(pos);
	}
}

void build()
{
	for(ll i=1;i<=n;++i)
		add(i,a[i]);
}

ll getsum(ll l,ll r)
{
	ll res=0;
	while(r>=0)
	{
		res+=t[r];
		r=prev(r)-1;
	}
	while(l>=0)
	{
		res-=t[l];
		l=prev(l)-1;
	}
	return res;
}

void test()
{
	input();
	build();
	ll temp;
	cin>>temp;
	for(ll i=0;i<temp;++i)
	{
		ll x,y;
		cin>>x>>y;
		cout<<getsum(x-1,y)<<endl;
	}
	add(3,20);
	cin>>temp;
	for(ll i=0;i<temp;++i)
	{
		ll x,y;
		cin>>x>>y;
		cout<<getsum(x-1,y)<<endl;
	}
	
}

int main()
{
	test();
	return 0;
}
