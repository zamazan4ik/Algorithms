#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long ll;

ll n,m,i,j,k;

inline ll getInt()
{
	ll res=0;
	bool ok=false;
	char s;
	do
	{
		s=getchar();
		if(s == '-')	ok=!ok;
	}
	while(s<'0' || s>'9');
	do
	{
		res=res*10+(s-'0');
		s=getchar();
	}
	while(s>='0' && s<='9');
	if(ok)	res=-res;
	return res;
}

void put(ll x)
{
	if(x)
	{	
		put(x/10);
		putchar(x%10+'0');
	}
}

inline void putInt(ll x)
{
	if(x)
	{
		if(x<0)	putchar('-');
		put(abs(x));
	}
	else	putchar('0');
}

int main()
{
	n=getInt();
	for(ll i=0;i<n;++i)
	{
		k=getInt();
		putInt(k+1);
		putchar('\n');
	}
	return 0;
}
