#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <ctime>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;

struct kor
{
	ll key,prior,ls,rs;
};

const ll maxn=100000;
kor t[maxn];
ll n,i,j,root=0,kol=0;
queue<ll> fr,q,digit;
set<ll> pr;

void merge(ll &x,ll left,ll right)
{
	if(!left)	x=right;
	else if(!right)	x=left;
	else if(t[left].prior > t[right].prior)
	{
		merge(t[left].rs,t[left].rs,right);
		x=left;
	}
	else
	{
		merge(t[right].ls,left,t[right].ls);
		x=right;
	}
}

void split(ll x,ll key,ll &left,ll &right)
{
	if(!x)	left=right=0;
	else if(key < t[x].key)
	{
		split(t[x].ls,key,left,t[x].ls);
		right=x;
	}
	else
	{
		split(t[x].rs,key,t[x].rs,right);
		left=x;
	}
}


void insert(ll &x,ll item)
{
	if(!x)	x=item;
	else if(t[item].prior > t[x].prior)
	{
		split(x,t[item].key,t[item].ls,t[item].rs);
		x=item;
	}
	else if(t[item].key < t[x].key)	insert(t[x].ls,item);
	else	insert(t[x].rs,item);
}

void insert(ll key)
{
	ll ind=0,prior;
	if(!fr.empty())
	{
		ind=fr.front();fr.pop();
	}
	else
		ind=++kol;
	do
	{
		prior=rand()*rand();
	}
	while(pr.find(prior) != pr.end());
	pr.insert(prior);
	kor temp={key,prior,0,0};
	t[ind]=temp;
	if(!root)	root=ind;
	else	insert(root,ind);
}

void erase(ll &x,ll key)
{
	if(!x);
	else if(key == t[x].key)
	{
		fr.push(x);pr.erase(t[x].prior);
		merge(x,t[x].ls,t[x].rs);
	}
	else if(key < t[x].key)	erase(t[x].ls,key);
	else	erase(t[x].rs,key);
}

void ob(ll x)
{
	if(t[x].ls)	ob(t[x].ls);
	q.push(t[x].key);
	if(t[x].rs)	ob(t[x].rs);
}

void test()
{
	cin>>n;
	ll d;
	for(ll i=0;i<n;++i)
	{
		cin>>d;
		digit.push(d);
		insert(d);
	}
	while(!digit.empty())
	{
		ob(root);
		while(!q.empty())
		{
			cout<<q.front()<<endl;q.pop();
		}
		erase(root,digit.front());
		digit.pop();
	}
	
}

int main()
{
	srand(time(0));
	test();
	return 0;
}
