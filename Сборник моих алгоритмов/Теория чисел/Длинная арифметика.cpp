//Длинная арифметика: только с положительными числами, недробная, нет деления длинного на длинное
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef vector<ll> lnum;
const ll base=1e9;

lnum a,b,c;

void read(lnum &a)
{
	string s;
	cin>>s;
	for(ll i=s.length();i>0;i-=9)
	{
		if(i<9)
			a.push_back(atoi(s.substr(0,i).c_str()));
		else
			a.push_back(atoi(s.substr(i-9,9).c_str()));
	}
	while(a.size() > 1 && a.back() == 0)
		a.pop_back();
}

void print(lnum &a)
{
	a.empty() ? cout<<0 : cout<<a.back();
	for(ll i=(ll)a.size()-2;i>=0;--i)
	{
		cout.width(9);
		cout.fill('0');
		cout<<a[i];
	}
	cout<<endl;
}

void getsum(lnum &a,lnum &b,lnum &c)
{
	ll carry=0;
	c=a;
	for(ll i=0;i<max(c.size(),b.size()) || carry;++i)
	{
		if(i == c.size())	c.push_back(0);
		c[i]+=carry + (i<b.size() ? b[i] : 0);
		carry=c[i]>=base;
		if(carry)	c[i]-=base;
	}
	while(c.size() > 1 && c.back() == 0)
		c.pop_back();
}

void getminus(lnum &a,lnum&b,lnum &c)
{
	ll carry=0;
	c=a;
	for(ll i=0;i<b.size() || carry;++i)
	{
		c[i]-=carry+(i<b.size() ? b[i] : 0);
		carry=c[i] < 0;
		if(carry)	c[i]+=base;
	}
	while(c.size() > 1 && c.back() == 0)
		c.pop_back();
}

void short_mult(lnum &a,lnum &c,ll x)
{
	ll carry=0;
	c=a;
	for(ll i=0;i<c.size() || carry;++i)
	{
		if(i == c.size())	c.push_back(0);
		c[i]=c[i]*x+carry;
		carry=c[i]/base;
		c[i]=c[i]%base;
	}
	while(c.size() > 1 && c.back() == 0)
		c.pop_back();
}

void long_mult(lnum &a,lnum &b,lnum &c)
{
	ll carry=0;
	c.resize(a.size() + b.size());
	for(ll i=0;i < a.size();++i)
	{
		for(ll j=0,carry=0;j<b.size() || carry;++j)
		{
			c[i+j]+=carry + a[i]*(j<b.size() ? b[j] : 0);
			carry=c[i+j]/base;
			c[i+j]%=base;
		}
	}
	while(c.size() > 1 && c.back() == 0)
		c.pop_back();
}

void short_divide(lnum &a,lnum &c,ll x)
{
	ll carry=0;
	c=a;
	for(ll i=c.size()-1;i>=0;--i)
	{
		long long cur=carry*base+c[i];
		c[i]=cur/x;
		carry=cur%x;
	}
	//cout<<carry<<endl;
	while(c.size() > 1 && c.back() == 0)
		c.pop_back();
}

void test()
{
	read(a);
	read(b);
	print(a);
	print(b);
	//long_mult(a,b,c);
	short_divide(a,c,7);
	print(c);
}


int main()
{
	//ios_base::sync_with_stdio(0);
	test();
	return 0;
}
