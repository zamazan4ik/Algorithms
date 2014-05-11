#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;

const ll maxn=10000,maxk=14;
ll n,m,i,j,k;
ll t[maxn][maxk],a[maxn],logn[maxn];

void calc()
{
	for(ll i=2;i<=n;++i)
		logn[i]=logn[i>>1]+1;
}

void build()
{
	for(ll i=1;i<=n;++i)
		t[i][0]=a[i];
	for(ll j=1;j<=logn[n];++j)
		for(ll i=1;i+(1<<(j-1))<=n;++i)
			t[i][j]=min(t[i][j-1],t[i+(1<<(j-1))][j-1]);
}

ll getmin(ll l,ll r)
{
	ll k=logn[r-l+1];
	return min(t[l][k],t[r-(1<<k)+1][k]);
}

void test()
{
	cin>>n;
	for(ll i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	calc();
	build();
	ll temp;
	cin>>temp;
	for(ll i=0;i<temp;++i)
	{
		ll x,y;
		cin>>x>>y;
		cout<<getmin(x,y)<<endl;
	}
}

int main()
{
	test();
	return 0;
}
