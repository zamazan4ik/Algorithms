#include <iostream>
#include <cstdio>
#include <memory.h>
#define maxn 10000
#define inf 1000000000

using namespace std;

int m[maxn],n,l[maxn],r[maxn];

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
    int p;
    for (p=pos;p<=n;p=next(p)) r[p]=max(r[p],value);
    m[pos]=max(m[pos],value);
    for (p=pos;p>0;p=prev(p)) l[p]=max(l[p],value);
}

int findmax(int ll,int rr)
{
    int res,p;
    res=-inf;
    for (p=ll;next(p)<=rr;p=next(p)) res=max(res,l[p]);
    res=max(res,m[p]);
    for (p=rr;prev(p)>=ll;p=prev(p)) res=max(res,r[p]);
    return res;
}

void init(void)
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    cin>>n;
    int x,i;
    for (i=1;i<=n;i++)
        m[i]=r[i]=l[i]=-inf;
    for (i=1;i<=n;i++)
    {
        cin>>x;
        modify(i,x);
    }
}

void sol(void)
{
    int i,j;
    for (i=1;i<=n;i++,cout<<endl)
        for (j=i;j<=n;j++)
            cout<<findmax(i,j)<<" ";
}

int main(void)
{
    init();
    sol();
    cin>>n;
    return 0;
}
