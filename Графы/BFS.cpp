#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxe=100,maxv=100;
int ef[maxe],es[maxe],ev[maxe],next[maxe],first[maxv],last[maxv],i,x,y,z;
queue<int> s;
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

void bfs()
{
    s.push(1);
    used[1]=true;
    while(!s.empty())
    {
        int from=s.front();
        s.pop();
        for(int h=first[from];h;h=next[h])
            if(!used[es[h]])
            {
                used[es[h]]=true;
                s.push(es[h]);
            }
    }
}

int main()
{
    init();
    bfs();
    system("pause");
}
