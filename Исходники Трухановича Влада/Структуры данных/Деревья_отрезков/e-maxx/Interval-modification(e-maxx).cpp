#include <iostream>
#define maxn 11111

using namespace std;

int n,t[maxn],a[maxn];

void build(int v,int tl,int tr)
{
    if (tl==tr)
        t[v]=a[tl];
    else
    {
        int tm=(tl+tr)>>1;
        build(v<<1,tl,tm);
        build((v<<1)+1,tm+1,tr);
    }
}

int get(int v,int tl,int tr,int pos)
{
    if (tl==tr) return t[v];
    int tm=(tl+tr)>>1;
    if (pos<=tm) return t[v]+get(v<<1,tl,tm,pos);
    else return t[v]+get((v<<1)+1,tm+1,tr,pos);
}

void update (int v, int tl, int tr, int l, int r, int add) 
{
	if (l>r) return;
    if (l==tl && r==tr) t[v]+=add;
	else 
    {
		int tm=(tl+tr)>>1;
        update(v<<1,tl,tm,l,min(r,tm),add);
		update ((v<<1)+1,tm+1,tr,max(l,tm+1),r,add);
	}
}

int main(void)
{
    cin>>n;
    int i;
    for (i=1;i<=n;i++)
        a[i]=i;
    build(1,1,n);
    update(1,1,n,5,8,100);
    for (i=1;i<=n;i++)
        cout<<get(1,1,n,i)<<" ";
    cin>>i;
}
