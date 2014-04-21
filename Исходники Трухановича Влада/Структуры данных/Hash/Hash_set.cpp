#include <iostream>
#include <cstdio>
#include <vector>
#define maxn 1000003
#define MOD 1000003

using namespace std;

vector<int> hash[maxn];

void hash_insert(int key)
{
    int pos=key%MOD,len=hash[pos].size(),i;
    bool b=true;
    for (i=0;i<len;i++)
        if (hash[pos][i]==key)
        {
            b=false;
            break;
        }
    if (b) hash[pos].push_back(key);
}

void hash_delete(int key)
{
    int pos=key%MOD,len=hash[pos].size(),i;
    for (i=0;i<len;i++)
        if (hash[pos][i]==key)
        {
            hash[pos][i]=hash[pos].back();
            hash[pos].pop_back();
            break;
        }
}

bool hash_in(int key)
{
    int pos=key%MOD,len=hash[pos].size(),i;
    for (i=0;i<len;i++)
        if (hash[pos][i]==key)
            return true;
    return false;
}

int main(void)
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int l,i=1;i<=n;i++)
    {
        cin>>l;
        hash_insert(l);
    }
    for (int l,i=1;i<=m;i++)
    {
        cin>>l;
        if (hash_in(l))
            cout<<"YES"<<endl;
        else cout<<"NONE"<<endl;
    }
    cin>>n;
    return 0;        
}
