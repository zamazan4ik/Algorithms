#include <iostream>
#include <cstdio>

using namespace std;

int s[100],n;

int prev(int x)
{
    return (x&(x-1));
}

int next(int x)
{
    return ((x<<1) - prev(x));
}

void modify(int pos, int value)
{
    for (;pos<=n;pos=next(pos)) s[pos]+=value;
}

int findsum(int l, int r)
{
    int res=0,p;
    for (p=r;p>0;p=prev(p)) res+=s[p];
    for (p=l-1;p>0;p=prev(p)) res-=s[p];
    return res;
}

void init(void)
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    cin>>n;
    int i,c;
    for (i=1;i<=n;i++)
        s[i]=0;
    for (i=1;i<=n;i++)
    {
        cin>>c;
        modify(i,c);
    }
}

void sol(void)
{
    int i,j;
    for (i=1;i<=n;i++,cout<<endl)
        for (j=i;j<=n;j++)
            cout<<findsum(i,j)<<" ";
        
}

int main()
{
    init();
    sol();
    cin>>n;
    return 0;
}
