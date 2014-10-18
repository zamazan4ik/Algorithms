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
typedef int ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pdd;
typedef vector<ll> lnum;

const ll maxn=1001;
vector<vector<ll> > a(maxn,vector<ll>(maxn,0));
vector<vector<ll> > t(4*maxn,vector<ll>(maxn,0));

ll n,m,i,j,k;

void build_y(ll vx,ll lx,ll rx,ll vy,ll ly,ll ry)
{
	if(ly == ry)
	{
		if(lx == rx)	t[vx][vy]=a[lx][ly];
		else	t[vx][vy]=t[vx*2][vy]+t[vx*2+1][vy];
	}
	else
	{
		ll my=(ly+ry)>>1;
		build_y(vx,lx,rx,vy*2,ly,my);
		build_y(vx,lx,rx,vy*2+1,my+1,ry);
		t[vx][vy]=t[vx][vy*2]+t[vx][vy*2+1];
	}
}

void build_x(ll vx,ll lx,ll rx)
{
	if(lx != rx)
	{
		ll mx=(lx+rx)>>1;
		build_x(vx*2,lx,mx);
		build_x(vx*2+1,mx+1,rx);
	}
	build_y(vx,lx,rx,1,1,n);
}

void mod_y(ll vx,ll lx,ll rx,ll vy,ll ly,ll ry,ll x,ll y)
{
	if(ly == ry)
	{
		if(lx == rx)	t[vx][vy] = a[x][y];
		else	t[vx][vy]=t[vx*2][vy]+t[vx*2+1][vy];
	}
	else
	{
		ll my=(ly+ry)>>1;
		if(y <= my)	mod_y(vx,lx,rx,vy*2,ly,my,x,y);
		else	mod_y(vx,lx,rx,vy*2+1,my+1,ry,x,y);
		t[vx][vy]=t[vx][vy*2]+t[vx][vy*2+1];
	}
}

void mod_x(ll vx,ll lx,ll rx,ll x,ll y)
{
	if(lx != rx)
	{
		ll mx=(lx+rx)>>1;
		if(x<=mx)	mod_x(vx*2,lx,mx,x,y);
		else	mod_x(vx*2+1,mx+1,rx,x,y);
	}
	mod_y(vx,lx,rx,1,1,n,x,y);
}

ll get_y(ll vx,ll vy,ll ly,ll ry,ll yl,ll yr)
{
	if(yl>yr)	return 0;
	if(ly == yl && ry == yr)	return t[vx][vy];
	ll my=(ly+ry)>>1;
	return get_y(vx,vy*2,ly,my,yl,min(yr,my))+get_y(vx,vy*2+1,my+1,ry,max(yl,my+1),yr);
}

ll get_x(ll vx,ll lx,ll rx,ll xl,ll xr,ll yl,ll yr)
{
	if(xl>xr)	return 0;
	if(lx == xl && rx == xr)	return get_y(vx,1,1,n,yl,yr);
	ll mx=(lx+rx)>>1;
	return get_x(vx*2,lx,mx,xl,min(xr,mx),yl,yr)+get_x(vx*2+1,mx+1,rx,max(xl,mx+1),xr,yl,yr);
}

void test()
{
	cin>>n>>k;
	build_x(1,1,n);
	string s;
	for(ll i=0;i<k;++i)
	{
		cin>>s;
		if(s == "ADD")
		{
			ll x,y;
			cin>>x>>y;
			a[x][y]++;
			mod_x(1,1,n,x,y);
		}
		else
		{
			ll xl,xr,yl,yr;
			cin>>xl>>yl>>xr>>yr;
			if(xl>xr)	swap(xl,xr);
			if(yl>yr)	swap(yl,yr);
			cout<<get_x(1,1,n,xl,xr,yl,yr)<<'\n';
		}
	}
}


int main()
{
	//srand(time(0));
	ios_base::sync_with_stdio(0);
	test();
	return 0;
}




