#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include <cstdio>
using namespace std;
typedef long long  ll;

ll n, m, i, j, k;


#define putcx _putchar_nolock
#define getcx _getchar_nolock

inline void inp(ll &n)
{
	n = 0;
	ll ch = getcx(); ll sign = 1;
	while (ch < '0' || ch > '9')
	{ 
		if (ch == '-')
			sign = -1; 
		ch = getcx(); 
	}
	while (ch >= '0' && ch <= '9')
		n = (n << 3) + (n << 1) + ch - '0', ch = getcx();
	n = n*sign;
	//(n<<3)+(n<<1) + ch - '0'== n*10 + ch-'0'
}

inline ll ab(ll &x)
{
	return x>0 ? x : -x;
}

void put(ll x)
{
	if(x)
	{
		put(x/10);
		putcx(x%10+'0');
	}
}

inline void out(ll x)
{
	if(x)
	{
		if(x<0)	putcx('-');
		put(ab(x));
	}
	else
		putcx('0');
}

int main()
{
	//freopen("input.txt","r",stdin);
	n = 10;
	ll x;
	for (ll i = 0; i<n; ++i)
	{
		inp(x);
		out(x+1);
	}
	return 0;
}

