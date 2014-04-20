#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;


int arr[11]={0,1,2,3,4,5,6,7,8,9,10},t[4*11+1];

void build(int v,int tl,int tr)
{
    if(tl==tr)
        t[v]=arr[tl];
    else
    {
        int tm=tl+((tr-tl)>>1);
        build(v<<1,tl,tm);
        build((v<<1)+1,tm+1,tr);
        t[v]=t[v<<1]+t[(v<<1)+1];
    }
}

void update(int v,int tl,int tr,int pos,int val)
{
    if(tl==tr)
        t[v]=val;
    else
    {
        int tm=tl+((tr-tl)>>1);
        if(pos<=tm)
            update(v<<1,tl,tm,pos,val);
        else
            update((v<<1)+1,tm+1,tr,pos,val);
         t[v]=t[v<<1]+t[(v<<1)+1];    
    }
}

int sum(int v,int tl,int tr,int l,int r)
{
    if(l>r)
        return 0;
    if(l==tl&&r==tr)
        return t[v];
    int tm=tl+((tr-tl)>>1);
    return sum(v<<1,tl,tm,l,min(tm,r)) + sum((v<<1)+1,tm+1,tr,max(l,tm+1),r);
}


int main()
{
    build(1,1,10);
    cout<<sum(1,1,10,1,3)<<' '<<sum(1,1,10,9,10)<<endl;
    update(1,1,10,10,20);
    cout<<sum(1,1,10,1,3)<<' '<<sum(1,1,10,9,10)<<endl;
    system("pause");
}
