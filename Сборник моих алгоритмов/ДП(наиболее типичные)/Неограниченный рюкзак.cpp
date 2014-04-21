#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const ll size=100;
ll a[size],i,j,p[size],w[size],s,n;

void input()
{
    cin>>n>>s;
    for(i=1;i<=s;++i)
    {
        cin>>p[i]>>w[i];
    }
}

void sol()
{
    a[0]=0;
    for(i=1;i<=n;++i)
        for(j=1;j<=s;++j)
            if(i >= w[j])
            {
                a[i]=max(a[i],a[i-w[j]]+p[j]);
            }
}

void pred()
{
    while(i>0)
    {
        for(j=1;j<=s;++j)
        {
            if(i>=w[j] && a[i-w[j]] == a[i]-p[j])
            {
                cout<<j<<endl;
                i-=w[j];
            }
            else
                --i;
        }
    }
}

void output()
{
    cout<<a[n]<<endl;
}

int main()
{
    input();
    sol();
    output();
    system("pause");
    return 0;
}
