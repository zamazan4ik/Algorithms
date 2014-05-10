#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>


using namespace std;
typedef long long ll;

const ll maxn=10000;
ll a[maxn],b[maxn],c[maxn];
ll n,m,i,j,len;


void init()
{
	ll temp;
	cin>>n;
	len=sqrt(n);
	for(ll i=1;i<=n;++i)
	{
		cin>>temp;
		a[i]=temp;
		b[(i-1)/len+1]+=a[i];
	}
}

void add(ll pos,ll val)
{
	a[pos]+=val;
	b[(pos-1)/len+1]+=val;
}

void add_int(ll l,ll r,ll val)
{
	for(ll i=l;i<=r;)
	{
		if(i+len<=r && (i-1)%len==0)
		{
			c[(i-1)/len+1]+=val;
			b[(i-1)/len+1]+=val*len;
			i+=len;
		}
		else
		{
			a[i]+=val;
			b[(i-1)/len+1]+=val;
			++i;
		}
	}
}

ll sum(ll l,ll r)
{
	ll res=0;
	for(ll i=l;i<=r;)
	{
		if(i+len<=r && (i-1)%len==0)
		{
			res+=b[(i-1)/len+1];
			i+=len;
		}
		else
		{
			res+=a[i]+c[(i-1)/len+1];
			++i;
		}
	}
	return res;
}

void test()
{
	init();
	for(ll i=0;i<3;++i)
	{
		ll x,y;
		cin>>x>>y;
		cout<<sum(x,y)<<endl;
	}
	add(2,10);
	for(ll i=0;i<2;++i)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		add_int(x,y,z);
		cout<<sum(x,y)<<endl;
	}
}


int main()
{
	test();
	//system("pause");
	return 0;
}
