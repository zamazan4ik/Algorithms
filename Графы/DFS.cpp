#include <iostream>
#include<vector>


using namespace std;

const int maxe=100,maxv=100;
int ef[maxe],es[maxe],ev[maxe],next[maxe],first[maxv],last[maxv],i,x,y,z;
vector<char> used(maxe);

void add(int v1,int v2,int value,int &count)
{
    ++count;
    ef[count]=v1;es[count]=v2;ev[count]=value;
    if(!first[v1])  first[v1]=count;
    if(last[v1])    next[last[v1]]=count;
    last[v1]=count;
}

void init()
{
    int count=0;
    for(i=0;i<5;++i)
    {
        cin>>x>>y>>z;
        add(x,y,z,count);
        add(y,x,z,count);
    }
}

void dfs(int from)
{
    used[from]=true;
    for(int h=first[from];h;h=next[h])
        if(!used[es[h]])
            dfs(es[h]);
}

int main()
{
    init();
    dfs(1);
    system("pause");
}
