#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <iterator>
#include <utility>
#include <cmath>


#define x first
#define y second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ld> pdd;

ll n,m,i,j,k;

void test()
{
	ll kol;
	cin>>kol;
	vector<ll> a(kol);
	for(ll i=0;i<kol;++i)
		cin>>a[i];
	ll n=pow(2.0,kol);
	for(ll i=0;i<n;++i)
	{
		for(ll j=0;j<kol;++j)
			if(i&(1<<j))
				cout<<a[j]<<' ';
		cout<<endl;
	}
}


int main()
{
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	test();
	return 0;
}




