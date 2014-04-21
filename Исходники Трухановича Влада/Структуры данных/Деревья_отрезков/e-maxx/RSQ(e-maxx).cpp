#include <iostream>
#define maxn 11111

using namespace std;

int n,t[maxn],a[maxn];

void build(int v,int tl,int tr){
    if (tl==tr)t[v]=a[tl];
    else{
        int tm=(tl+tr)>>1;
        build(v<<1,tl,tm);
        build((v<<1)+1,tm+1,tr);
        t[v]=t[v<<1]+t[(v<<1)+1];
    }
}

int sum(int v,int tl,int tr,int l,int r){
    if (l>r) return 0;
    if (l==tl && r==tr) return t[v];
    int tm=(tl+tr)>>1;
    return sum(v<<1,tl,tm,l,min(r,tm))+sum((v<<1)+1,tm+1,tr,max(l,tm+1),r);
}

void update (int v, int tl, int tr, int pos, int new_val){
	if (tl==tr) t[v]=new_val;
	else{
		int tm=(tl+tr)>>1;
		if (pos<=tm) update(v<<1,tl,tm,pos,new_val);
		else update ((v<<1)+1,tm+1,tr,pos,new_val);
		t[v] = t[v<<1]+t[(v<<1)+1];
	}
}

int main(void){
    cin>>n;
    int i;
    for (i=1;i<=n;i++) a[i]=i;
    build(1,1,n);
    update(1,1,n,2,100);
    cout<<sum(1,1,n,2,3);
    cin>>n;
    return 0;
}
