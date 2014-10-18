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

struct tree
{
    ll len,link;
    map<char,ll> next;
};

ll n,m,i,j,sz=1,cur,last,p;
tree t[2*maxn+7];
string s;

void build_aut(string &s)
{
    last=0;
    for(ll i=0;i<s.length();++i)
    {
        cur=sz++;
        t[cur].len=t[last].len+1;
        char c=s[i];
        for(p=last;p!=-1 && !t[p].next.count(c);p=t[p].link)
            t[p].next[c]=cur;
        if(p == -1) t[cur].link=0;
        else
        {
            ll q=t[p].next[c];
            if(t[p].len+1 == t[q].len)
                t[cur].link=q;
            else
            {
                ll clone=sz++;
                t[clone].len=t[p].len+1;
                t[clone].link=t[q].link;
                t[clone].next=t[q].next;
                for(;p!=-1 && t[p].next[c] == q;p=t[p].link)
                    t[p].next[c]=clone;
                t[cur].link=t[q].link=clone;
            }
        }
        last=cur;
    }
}

bool check(string &s)
{
    ll v=0;
    for(ll i=0;i<s.length();++i)
    {
        if(!t[v].next.count(s[i]))  return false;
        else    v=t[v].next[s[i]];
    }
    return true;
}

void test()
{
    cin>>s;
    t[0].link=-1;t[0].len=0;
    build_aut(s);
    ll k;
    cin>>k;
    for(ll i=0;i<k;++i)
    {
        cin>>s;
        if(check(s))    cout<<"yes"<<endl;
        else    cout<<"no"<<endl;
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
