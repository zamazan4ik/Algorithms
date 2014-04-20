#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;
typedef long long ll;

const ll maxn=100;
vector<ll> d(maxn,-1);

ll findroot(ll v)
{
    return d[v]==-1 ? v : d[v]=findroot(d[v]);
}

void union_set(ll a,ll b)
{
    ll q1,q2;
    q1=findroot(a);
    q2=findroot(b);
    if(q1 != q2)
    {
        r=rand() % 2;
        r==0 ? d[q1]=q2 : d[q2]=q1;
    }
}



int main()
{
    srand(time(0));    
    system("pause");
    return 0;
}
