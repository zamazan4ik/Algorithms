#include <iostream>
#include <cstdio>
#include <cmath>
#define maxn 11111

using namespace std;

int a[maxn],b[maxn],n,len;

void init(void){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    cin>>n;
    len=(int)(sqrt(n));
    for (int i=1;i<=n;i++){
        a[i]=i;
        b[(i-1)/len+1]+=a[i];
    }
}

void modify(int pos,int add){
    a[pos]+=add;
    b[(pos-1)/len+1]+=add;
}

int sum(int l,int r){
    int s=0;
    for (int i=l;i<=r;)
        if ((i-1)%len==0){
            if (i+len<=r){
                i+=len;
                s+=b[i/len];
            }else{
                s+=a[i];
                ++i;
            }
        }else{
            s+=a[i];
            ++i;
        }
    return s;
}

void sol(void){
    int m;
    cin>>m;
    while (m--){
        int pos,add;
        cin>>pos>>add;
        modify(pos,add);
    }
    cin>>m;
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<sum(l,r)<<endl;
    }
}

int main(void)
{
    init();
    for (int i=1;i<=len;i++)
        cout<<b[i]<<" ";
    cout<<endl;
    sol();
    cin>>n;
    return 0;
}
