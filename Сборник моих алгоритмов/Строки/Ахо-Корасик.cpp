#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cstring>

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

const ll maxn=10000;
const ll k=53;

struct tree
{
    ll next[k],go[k],p,link,good;
    bool leaf;
    char pch;
    vector<ll> pat;
};

ll n,m,i,j,sz=1;
tree t[maxn];
vector<string> str;
vector<char> used;
string s;

ll go(ll v,ll c);
ll getlink(ll v);

void init(ll v)
{
    memset(t[v].next,255,sizeof(t[v].next));
    memset(t[v].go,255,sizeof(t[v].go));
    t[v].link=t[v].good=t[v].p=-1;
    t[v].leaf=false;
}

void add_bor(string &s,ll kol)
{
    ll v=0;
    for(ll i=0;i<s.length();++i)
    {
        ll c=s[i]-'a';
        if(t[v].next[c] == -1)
        {
            init(sz);
            t[sz].p=v;
            t[sz].pch=c;
            t[v].next[c]=sz++;
        }
        v=t[v].next[c];
    }
    t[v].leaf=true;
    t[v].pat.pb(kol);
}

ll getlink(ll v)
{
    if(t[v].link == -1)
    {
        if(v == 0 || t[v].p == 0)
            t[v].link=0;
        else
            t[v].link=go(getlink(t[v].p),t[v].pch);
    }
    return t[v].link;
}

ll go(ll v,ll c)
{
    if(t[v].go[c] == -1)
    {
        if(t[v].next[c] != -1)
            t[v].go[c]=t[v].next[c];
        else
        {
            if(v == 0)
                t[v].go[c]=0;
            else
                t[v].go[c]=go(getlink(v),c);
        }
    }
    return t[v].go[c];
}

ll getgood(ll v)
{
    if(t[v].good == -1)
    {
        ll u=getlink(v);
        if(u == 0)
            t[v].good=0;
        else
            t[v].good=t[u].leaf ? u : getgood(u);
    }
    return t[v].good;
}

void check(ll v)
{
    for(ll i=v;i != 0;i=getgood(i))
        if(t[i].leaf)
            for(ll j=0;j<t[i].pat.size();++j)
                used[t[i].pat[j]]=true;
}

void finding(string &s)
{
    ll v=0;
    for(ll i=0;i<s.length();++i)
    {
        v=go(v,s[i]-'a');
        check(v);
    }
}

void test()
{
    cin>>n;
    str.resize(n);
    used.resize(n);
    init(0);
    t[0].link=t[0].good=t[0].p=0;
    for(ll i=0;i<n;++i)
    {
        cin>>str[i];
        add_bor(str[i],i);
    }
    cin>>s;
    finding(s);
    for(ll i=0;i<n;++i)
    {
        if(used[i])
            cout<<str[i]<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    test();
    return 0;
}
