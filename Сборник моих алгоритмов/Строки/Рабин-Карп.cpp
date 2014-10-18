#include <iostream>
#include <fstream>
#include <ostream>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <ctime>
#include <cmath>
#include <string>
#include <cstring>
#include <cctype>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pdd;

const ll p=53;
const ll maxn=10000;

ll n,m,i,j,k;
ll pp[maxn];
ll h[maxn];
string s;

ll get_hash(string &s)
{
	ll res=0;
	for(ll i=0;i<s.length();++i)
		res+=(s[i]-'a'+1)*pp[i];
	return res;
}

void test()
{
	cin>>s;
	cin>>n;
	pp[0]=1;
	for(ll i=1;i<s.length();++i)
		pp[i]=pp[i-1]*p;
	h[0]=s[0]-'a'+1;
	for(ll i=1;i<s.length();++i)	h[i]=h[i-1]+(s[i]-'a'+1)*pp[i];
	string t;
	for(ll i=0;i<n;++i)
	{
		cin>>t;
		ll h1=get_hash(t);
		if(t.length()>s.length())
		{
			cout<<"NO"<<endl;continue;
		}
		bool ok=true;
		for(ll j=0;j<s.length()-t.length()+1;++j)
		{
			ll h2=h[j+t.length()-1]-(j?h[j-1]:0);
			if(h2 == h1*pp[j])
			{
				cout<<"YES"<<endl;
				ok=false;
				break;
			}
		}
		if(ok)	cout<<"NO"<<endl;
	}
}


int main()
{
	//srand(time(0));
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	test();
	return 0;
}
