#include <iostream>
#include <cstdio>
#define maxn 100
#define inf 10000

using namespace std;

int m[maxn],n;

int prev(int x)
{
    return (x&(x-1));
}

int next(int x)
{
    return ((x<<1)-prev(x));
}

void modify(int pos, int value)
{
    for (int p=pos;p<=n;p=next(p)) m[p]=max(m[p],value);
}

int findmax(int last)
{
    int res=-inf;
    for(;last>0;last=prev(last)) res=max(res,m[last]);
    return res;
}

void init(void)
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        m[i]=-inf;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        modify(i,x);
    }
}

void sol(void)
{
    for (int i=1;i<=n;i++) cout<<findmax(i)<<" ";
}

int main(void)
{
    init();
    sol();
    cin>>n;
    return 0;
}
