#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;

struct kor
{
	ll sum,add,size;
};
const ll maxn=10000;
kor t[4*maxn+7];
ll a[maxn],n,m,i,j,k;

void init()
{
	cin>>n;
	for(ll i=1;i<=n;++i)
		cin>>a[i];
}

void build(ll v,ll tl,ll tr)
{
	if(tl == tr)
	{
		t[v].sum=a[tl];
		t[v].size=1;
	}
	else
	{
		ll tm=tl+((tr-tl)>>1);
		build(v<<1,tl,tm);
		build((v<<1)+1,tm+1,tr);
		t[v].sum=t[v<<1].sum+t[(v<<1)+1].sum;
		t[v].size=t[v<<1].size+t[(v<<1)+1].size;
	}
}

ll getsum(ll v,ll tl,ll tr,ll l,ll r,ll add)
{
	if(l>r)	return 0;
	if(tl == l && tr == r)
	{
		return t[v].sum+t[v].size*(add+t[v].add);
	}
	else
	{
		ll tm=tl+((tr-tl)>>1);
		return getsum(v<<1,tl,tm,l,min(tm,r),add+t[v].add)+getsum((v<<1)+1,tm+1,tr,max(tm+1,l),r,add+t[v].add);
	}
}

void update(ll v,ll tl,ll tr,ll l,ll r,ll val)
{
	if(l>r);
	else if(tl == l && tr == r)
	{
		t[v].add+=val;
	}
	else
	{
		ll tm=tl+((tr-tl)>>1);
		update(v<<1,tl,tm,l,min(tm,r),val);
		update((v<<1)+1,tm+1,tr,max(tm+1,l),r,val);
		t[v].sum=t[v<<1].sum+t[(v<<1)+1].sum+t[v<<1].size*t[v<<1].add+
		t[(v<<1)+1].size*t[(v<<1)+1].add;
	}
}

ll getnumb(ll v,ll tl,ll tr,ll pos,ll add)
{
	if(tl == tr)
	{
		return t[v].sum+t[v].add+add;
	}
	else
	{
		ll tm=tl+((tr-tl)>>1);
		if(pos<=tm)
			return getnumb(v<<1,tl,tm,pos,t[v].add+add);
		else
			return getnumb((v<<1)+1,tm+1,tr,pos,t[v].add+add);
	}
}

void test()
{
	init();
	build(1,1,n);
	ll temp;
	cin>>temp;
	for(ll i=0;i<temp;++i)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		cout<<getsum(1,1,n,x,y,0)<<endl;
		update(1,1,n,x,y,z);
		cout<<getsum(1,1,n,x,y,0)<<endl;
	}
	for(ll i=1;i<=5;++i)
	{
		cout<<getnumb(1,1,n,i,0)<<endl;
	}
}


int main()
{
	test();
	return 0;
}
