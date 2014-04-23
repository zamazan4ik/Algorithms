#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
#include <ctime>

using namespace std;
typedef long long ll;

struct kor
{
	ll key,prior,ls,rs,add,size,sum;
};

const ll maxn=10000;
kor t[maxn];
ll n,m,s,i,j,root=0,kol=0;
queue<ll> fr,q,mem;
set<ll> pr;

ll sizes(ll x)
{
	if(!x)	return 0;
	else	return t[x].size;
}

ll summa(ll x)
{
	if(!x)	return 0;
	else	return t[x].sum+t[x].size*t[x].add;
}

void recalc(ll x)
{
	t[x].size=sizes(t[x].ls) + sizes(t[x].rs) +1;
	t[x].sum=summa(t[x].ls)+summa(t[x].rs)+t[x].key;
}

void push(ll x)
{
	if(x && t[x].add)
	{
		t[x].key+=t[x].add;
		t[t[x].ls].add+=t[x].add;
		t[t[x].rs].add+=t[x].add;
		t[x].add=0;
	}
}

void merge(ll &x,ll left,ll right)
{
	push(left);
	push(right);
	if(!left)	x=right;
	else if(!right)	x=left;
	else if(t[left].prior > t[right].prior)
	{
		merge(t[x].rs,t[x].rs,right);
		x=left;
	}
	else 
	{
		merge(t[x].ls,left,t[x].ls);
		x=right;
	}
	recalc(x);
}

void split(ll x, ll key,ll &left,ll &right)
{
	push(x);
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
	recalc(x);
}

void erase(ll &x,ll key)
{
	if(!x);
	else if(t[x].key == key)
	{
		fr.push(x);pr.erase(t[x].prior);
		merge(x,t[x].ls,t[x].rs);
	}
	else if(key <t[x].key)	erase(t[x].ls,key);
	else	erase(t[x].rs,key);
	recalc(x);
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
	recalc(x);
}

void insert(ll key)
{
	ll ind,prior;
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
	kor temp={key,prior,0,0,0,1,key};
	t[ind]=temp;
	if(!root)	root=ind;
	else	insert(root,ind);
}

ll get_sum(ll l,ll r)
{
	ll left,right,mid,temp,res;
	split(root,r,temp,right);
	split(temp,l-1,left,mid);
	res=t[mid].sum;
	merge(temp,left,mid);
	merge(root,temp,right);
	return res;
}

void add(ll l,ll r,ll val)
{
	ll left,right,mid,temp;
	split(root,r,temp,right);
	split(temp,l-1,left,mid);
	t[mid].add+=val;
	merge(temp,left,mid);
	merge(root,temp,right);
}

void ob(ll x)
{
	if(t[x].add)	push(x);
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
		insert(d);
		mem.push(d);
	}
	while(!mem.empty())
	{
		ob(root);
		while(!q.empty())
		{
			cout<<q.front()<<endl;q.pop();
		}
		erase(root,mem.front());
		mem.pop();
	}
	insert(35);
	insert(-20);
	cout<<get_sum(-100,100)<<endl;
	add(-100,100,100);
	cout<<get_sum(-100,200)<<endl<<endl;
	ob(root);
	while(!q.empty())
	{
		cout<<q.front()<<endl;q.pop();
	}
}

int main()
{
	srand(time(0));
	test();
	return 0;
}
