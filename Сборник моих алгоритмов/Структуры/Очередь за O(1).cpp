#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <stack>

using namespace std;
typedef long long ll;

ll n,m,i,j,k;
stack<pair<ll,ll> > s1,s2;

void push(ll x)
{
	s1.empty() ? s1.push(make_pair(x,x)) : s1.push(make_pair(x,min(x,s1.top().second)));
}

void copy()
{
	while(!s1.empty())
	{
		ll x,minim;
		x=s1.top().first;
		s1.pop();
		minim=s2.empty() ? x : min(x,s2.top().second);
		s2.push(make_pair(x,minim));
	}
}

bool empty()
{
	return s1.empty() && s2.empty();
}

ll pop()
{
	if(s2.empty())	copy();
	if(s2.empty())	cout<<"LOL"<<endl;
	else
	{
		ll res=s2.top().first;
		s2.pop();
		return res;
	}
}

ll getmin()
{
	if(empty())	cout<<"LOL"<<endl;
	else
	{
		ll minim;
		if(s1.empty())	minim=s2.top().second;
		else	minim=s2.empty() ? s1.top().second : min(s1.top().second,s2.top().second);
		return minim;	
	}
}

void test()
{
	cin>>n;
	for(ll i=0;i<n;++i)
	{
		ll temp;
		cin>>temp;
		push(temp);
		cout<<getmin()<<endl;
	}
	pop();
	cout<<getmin()<<endl;
	push(-1);
	cout<<getmin()<<endl;
}


int main()
{
	test();
	return 0;
}
