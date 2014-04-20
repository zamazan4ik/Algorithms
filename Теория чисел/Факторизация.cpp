#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

ll n,i,kor;
vector<ll> temp;

void faktor()
{
    kor=sqrt(n);
    for(i=2;i<=kor;++i)
        while(n%i == 0)
        {
            temp.push_back(i);
            n/=i;
        }
    if(n>1)
        temp.push_back(n);
}


int main()
{
    //ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n;
    faktor();
    output();
    system("pause");
    return 0;
}
