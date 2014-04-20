/*Одна особенность: в функции get_min() при нахождении максимума нужно возвращать в первом условии -INF, а при нахождении
максимума INF.Пр нахождении суммы возвращать 0 */


#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

const int INF=10000;
int a[11]={0,1,2,3,4,5,6,7,8,9,10},t[4*11+1];

void build(int v,int tl,int tr)
{
    if(tl==tr)
        t[v]=a[tl];
    else
    {
        int tm=tl+((tr-tl)>>1);
        build(v<<1,tl,tm);
        build((v<<1)+1,tm+1,tr);
        t[v]=min(t[v<<1],t[(v<<1)+1]);
    }
}


int get_min(int v,int tl,int tr,int l,int r)
{
    if(l>r)
        return INF;
    if(l==tl && r==tr)
        return t[v];
    else
    {
        int tm=tl+((tr-tl)>>1);
        return min(get_min(v<<1,tl,tm,l,min(r,tm)),
               get_min((v<<1)+1,tm+1,tr,max(l,tm+1),r));
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
        t[v]=min(t[v<<1],t[(v<<1)+1]);
    }
}



int main()
{
    build(1,1,10);
    int n,m,pos,val;
    cin>>n>>m;
    cout<<get_min(1,1,10,n,m)<<endl;
    cin>>pos>>val;
    update(1,1,10,pos,val);
    cout<<get_min(1,1,10,n,m)<<endl;
    system("pause");
}
