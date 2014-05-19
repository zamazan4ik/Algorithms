#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;

const ll maxv = 1000, maxe = 10000, maxk = 15;
ll ef[maxe], es[maxe], nexti[maxe], first[maxe], c = 0;
ll n, m, i, j, k, timer = 0, ptr = 0;
vector<ll> tin1(maxv, 0), tin2(maxv, 0), refe(2 * maxv, 0), logn(maxv, 0);
ll t[maxv][maxk];

void add(ll v1, ll v2)
{
	nexti[++c] = first[v1]; first[v1] = c;
	ef[c] = v1; es[c] = v2;
}

void input()
{
	cin >> n >> m;
	for (ll i = 0; i<m; ++i)
	{
		ll x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
}

void dfs(ll v)
{
	tin1[v] = ++timer;
	tin2[timer] = v;
	bool ok = true;
	for (ll h = first[v]; h; h = nexti[h])
	{
		if (!tin1[es[h]])
		{
			dfs(es[h]);
			ok = false;
			t[++ptr][0] = tin1[v];
		}
	}
	if (ok)
		t[++ptr][0] = tin1[v];
}

void calc()
{
	for (ll i = 2; i <= ptr; ++i)
		logn[i] = logn[i >> 1] + 1;
}

void sparse()
{
	calc();
	for (ll j = 1; j <= logn[ptr]; ++j)
		for (ll i = 1; i + (1 << (j - 1)) <= ptr; ++i)
			t[i][j] = min(t[i][j - 1], t[i + (1 << (j - 1))][j - 1]);
}

ll getmin(ll l, ll r)
{
	ll k = logn[r - l + 1];
	return min(t[l][k], t[r - (1 << k) + 1][k]);
}

void lca_build()
{
	dfs(1);
	for (ll i = 1; i <= ptr; ++i)
		if (!refe[t[i][0]])
			refe[t[i][0]] = i;
	sparse();
}

ll lca_get(ll v1, ll v2)
{
	ll l = refe[tin1[v1]], r = refe[tin1[v2]];
	if (l>r)	swap(l, r);
	return tin2[getmin(l, r)];
}

void test()
{
	input();
	lca_build();
	ll temp;
	cin >> temp;
	for (ll i = 0; i<temp; ++i)
	{
		ll x, y;
		cin >> x >> y;
		cout << lca_get(x, y) << endl;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
	//ios_base::sync_with_stdio(0);
	test();
	return 0;
}