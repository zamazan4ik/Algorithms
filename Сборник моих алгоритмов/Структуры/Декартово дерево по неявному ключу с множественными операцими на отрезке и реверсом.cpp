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
	ll x, prior, ls, rs, size, add, sum;
	bool rev;
};

const ll maxn = 10000;
kor t[maxn];
set<ll> pr;
queue<ll> fr;
ll n, m, i, j, k, root = 0, kol = 0;

ll sizes(ll x)
{
	if (!x)	return 0;
	else	return t[x].size;
}

ll sum(ll x)
{
	if (!x)	return 0;
	else	return t[x].sum + t[x].add*t[x].size;
}

void recalc(ll x)
{
	t[x].size = sizes(t[x].ls) + sizes(t[x].rs) + 1;
	t[x].sum = sum(t[x].ls) + sum(t[x].rs) + t[x].x;
}

void push(ll x)
{
	if (x && t[x].rev)
	{
		t[x].rev = false;
		swap(t[x].ls, t[x].rs);
		t[t[x].ls].rev ^= true;
		t[t[x].rs].rev ^= true;
	}
	if (x && t[x].add)
	{
		t[x].x += t[x].add;
		t[t[x].ls].add += t[x].add;
		t[t[x].rs].add += t[x].add;
		t[x].add = 0;
	}

}

void merge(ll &x, ll left, ll right)
{
	push(left); push(right);
	if (!left) x = right;
	else if (!right)	x = left;
	else if (t[left].prior > t[right].prior)
	{
		merge(t[left].rs, t[left].rs, right);
		x = left;
	}
	else
	{
		merge(t[right].ls, left, t[right].ls);
		x = right;
	}
	recalc(x);
}

void split(ll x, ll key, ll &left, ll &right)
{
	push(x);
	if (!x)	left = right = 0;
	else if (key >= sizes(t[x].ls) + 1)
	{
		split(t[x].rs, key - sizes(t[x].ls) - 1, t[x].rs, right);
		left = x;
	}
	else
	{
		split(t[x].ls, key, left, t[x].ls);
		right = x;
	}
	recalc(x);
}

void erase(ll pos)
{
	ll left, mid, temp, right;
	split(root, pos - 1, left, temp);
	split(temp, 1, mid, right);
	merge(root, left, right);
}

void insert(ll ind, ll pos)
{
	ll left, mid, temp, right;
	split(root, pos, left, right);
	merge(temp, left, ind);
	merge(root, temp, right);
}

void add(ll l, ll r, ll val)
{
	ll left, right, temp, mid;
	split(root, r, temp, right);
	split(temp, l - 1, left, mid);
	t[mid].add += val;
	merge(temp, left, mid);
	merge(root, temp, right);
}

ll getsum(ll l, ll r)
{
	ll left, right, temp, mid, res = 0;
	split(root, r, temp, right);
	split(temp, l - 1, left, mid);
	res = t[mid].sum;
	merge(temp, left, mid);
	merge(root, temp, right);
	return res;
}

void rever(ll l, ll r)
{
	ll left, right, temp, mid;
	split(root, r, temp, right);
	split(temp, l - 1, left, mid);
	t[mid].rev = true;
	merge(temp, left, mid);
	merge(root, temp, right);
}

void insert(ll x)
{
	ll ind, prior;
	if (!fr.empty())
	{
		ind = fr.front(); fr.pop();
	}
	else
		ind = ++kol;
	do
	{
		prior = rand()*rand();
	} while (pr.find(prior) != pr.end());
	pr.insert(prior);
	kor temp;
	temp = { x, prior, 0, 0, 1, 0, x, false };
	t[ind] = temp;
	if (!root)	root = ind;
	else	insert(ind, kol);
}

void ob(ll x)
{
	push(x); recalc(x);
	if (t[x].ls)	ob(t[x].ls);
	cout << t[x].x << endl;
	if (t[x].rs)	ob(t[x].rs);

}

void test()
{
	cin >> n;
	for (ll i = 0; i<n; ++i)
	{
		ll temp;
		cin >> temp;
		insert(temp);
	}
	ob(root);
	cout << getsum(1, 4) << endl;
	erase(3);
	cout << getsum(1, 4) << endl;
	add(2, 2, 10);
	cout << getsum(1, 2) << endl;
	cout << endl; ob(root); cout << endl;
	rever(1, 4);
	cout << endl; ob(root); cout << endl;
	cout << getsum(3, 4) << endl;

}

int main()
{
	freopen("input.txt", "r", stdin);
	srand(time(0));
	test();
	return 0;
}
