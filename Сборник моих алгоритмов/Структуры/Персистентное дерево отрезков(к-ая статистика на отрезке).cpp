#pragma comment(linker, "/STACK:65777216")
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
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pdd;
typedef vector<ll> lnum;

const ll maxn = 1000, maxt = 1000000;

struct tree
{
	ll ls = 0, rs = 0, sum = 0;
};

ll n, m, i, j, k, c = 0, r = 0;
vector<ll> a(maxn), s(maxn), root(maxn);
vector<tree> t(maxt);

ll build(ll tl, ll tr)
{
	ll v = ++c;
	if (tl == tr);
	else
	{
		ll tm = (tl + tr) >> 1;
		t[v].ls = build(tl, tm);
		t[v].rs = build(tm + 1, tr);
	}
	return v;
}

ll getsum(ll v, ll l, ll r, ll tl, ll tr)
{
	if (tl>r || tr<l)	return 0;
	if (tl >= l && tr <= r)	return t[v].sum;
	ll tm = (tl + tr) >> 1;
	return getsum(t[v].ls, l, r, tl, tm) + getsum(t[v].rs, l, r, tm + 1, tr);
}

ll modify(ll v, ll pos, ll val, ll tl, ll tr)
{
	ll nv = ++c;
	if (tl == tr)	t[nv].sum = val;
	else
	{
		ll tm = (tl + tr) >> 1;
		if (pos <= tm)	t[nv].rs = t[v].rs, t[nv].ls = modify(t[v].ls, pos, val, tl, tm);
		else	t[nv].ls = t[v].ls, t[nv].rs = modify(t[v].rs, pos, val, tm + 1, tr);
		t[nv].sum = t[t[nv].ls].sum + t[t[nv].rs].sum;
	}
	return nv;
}

ll get_k(ll l, ll r, ll k, ll tl, ll tr)
{
	if (tl == tr)	return tl;
	ll tm = (tl + tr) >> 1;
	if (t[t[r].ls].sum - t[t[l].ls].sum >= k)	return get_k(t[l].ls, t[r].ls, k, tl, tm);
	else 	return get_k(t[l].rs, t[r].rs, k - (t[t[r].ls].sum - t[t[l].ls].sum), tm + 1, tr);
}

void test()
{
	scanf("%lld", &n);
	for (ll i = 1; i <= n; ++i)
	{
		scanf("%lld", &a[i]);
		s[i] = a[i];
	}
	sort(s.begin() + 1, s.begin() + n + 1);
	for (ll i = 1; i <= n; ++i)
	{
		a[i] = lower_bound(s.begin() + 1, s.begin() + n + 1, a[i]) - s.begin();
	}
	root[r++] = build(1, n);
	for (ll i = 1; i <= n; ++i)
	{
		ll val = getsum(root[r - 1], a[i], a[i], 1, n);
		root[r] = modify(root[r - 1], a[i], val + 1, 1, n);
		++r;
	}
	scanf("%lld", &m);
	ll left, right, kat;
	for (ll i = 1; i <= m; ++i)
	{
		scanf("%lld%lld%lld", &left, &right, &kat);
		printf("%lld\n", s[get_k(root[left - 1], root[right], kat, 1, n)]);
	}
}


int main()
{
	//srand(time(0));
	//ios_base::sync_with_stdio(0);
	test();
	return 0;
}




