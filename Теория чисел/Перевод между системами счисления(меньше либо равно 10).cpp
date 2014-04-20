#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll n,from,to,i;

ll from_to_dec(ll digit)
{
    ll ans=0;
    vector<ll> cifr,p;
    while(digit)
    {
        cifr.push_back(digit%10);
        digit/=10;
    }
    
    p.push_back(1);
    
    for(i=1;i<cifr.size();++i)
        p.push_back(p[i-1]*from);
    
    for(i=0;i<cifr.size();++i)
        ans+=cifr[i]*p[i];
    return ans;
}

void dec_to_to(ll digit)
{
    vector<ll> ans;
    while(1)
    {
        if(digit<to)
        {
            ans.push_back(digit);
            break;
        }
        else
        {
            ans.push_back(digit%to);
            digit/=to;
        }
    }
    for(i=ans.size()-1;i>=0;--i)
        cout<<ans[i];
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n>>from>>to;
    dec_to_to(from_to_dec(n));
    system("pause");
    return 0;
}

