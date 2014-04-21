//O(NlogN)
#include <iostream>
#define maxn 1111
#define inf 1111111111

using namespace std;

int f[maxn],m[maxn],l[maxn],r[maxn],a[maxn],n;

int prev(int x){
    return (x&(x-1));
}

int next(int x){
    return ((x<<1)-prev(x));
}

void modify(int pos,int value){
    int p;
    for (p=pos;p<=n;p=next(p)) r[p]=max(r[p],value);
    m[pos]=max(m[pos],value);
    for (p=pos;p>0;p=prev(p)) l[p]=max(l[p],value);
}

int findmax(int ll, int rr){
    int res,p;
    res=-inf;
    for (p=ll;next(p)<=rr;p=next(p)) res=max(res,l[p]);
    res=max(res,m[p]);
    for (p=rr;prev(p)>=ll;p=prev(p)) res=max(res,r[p]);
    return res;
}

void init(void){
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
}

int main(void){
    init();
    for (int i=1;i<=n;i++){
        int mx=findmax(1,a[i]-1);
        f[a[i]]=max(f[a[i]],mx+1);
        modify(a[i],f[a[i]]);
    }
    for (int i=1;i<=n;i++) cout<<f[i]<<" ";
    cin>>n;
    return 0;
}
