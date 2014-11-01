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
ld eps=1e-7;


ld f(ld x)
{
	return x*2+4*x+15.0/x;
}

// search max of function
//ternary search
void test()
{
	ld r=1000000000.0,l=-1000000000.0;
	while(r-l>eps)
	{
		ld m1=l+(r-l)/3.0,m2=r-(r-l)/3.0;
		if(f(m1) < f(m2))	l=m1;
		else	r=m2;	
	}
	cout<<l;
}


int main()
{
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	test();
	return 0;
}




