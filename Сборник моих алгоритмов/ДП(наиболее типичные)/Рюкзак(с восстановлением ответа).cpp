#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const ll size=100;
ll a[size][size],i,j,p[size],w[size],s,n;

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
    for(j=1;j<=s;++j)
        for(i=1;i<=n;++i)
        {
            a[i][j]=a[i][j-1];
            if(i>=w[j] && a[i][j] < a[i-w[j]][j-1]+p[j])
                a[i][j] = a[i-w[j]][j-1]+p[j];
        }   
}

void pred(ll i,ll j)
{
    if(i > 0 && j > 0)
    {
        if(j > 0 && i>=w[j] && a[i-w[j]][j-1] == a[i][j]-p[j])
        {
            cout<<j<<endl;
            pred(i-w[j],j-1);
        }
        else
            pred(i,j-1);
    }
}

void output()
{
    cout<<a[n][s]<<endl;
}

int main()
{
    input();
    sol();
    output();
    pred(n,s);
    system("pause");
    return 0;
}
