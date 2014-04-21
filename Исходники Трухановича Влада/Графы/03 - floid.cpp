#include <cstdio>
#include <iostream>
#include <memory.h>
#define N 111
#define M 2222

using namespace std;

int c,n,m,a[N][N];

void init(void){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);    
    cin>>n>>m;
    int i,x,y,z;
    memset(a,63,sizeof(a));
    for (i=1;i<=m;i++){
        cin>>x>>y>>z;
        a[x][y]=z;
    }
    for (i=1;i<=n;i++)
        a[i][i]=0;
}

void floid(void){
    int i,j,k;
    for (k=1;k<=n;k++)
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
                if (a[i][j]>a[i][k]+a[k][j]) a[i][j]=a[i][k]+a[k][j];
}

void sol(void){
    int i,j;
    floid();
    for (i=1;i<=n;i++,cout<<endl)
        for (j=1;j<=n;j++,cout<<" ")
            if (a[i][j]<1000000000) cout<<a[i][j];
            else cout<<"INF";
}

int main(){   
    init();
    sol();
    cin>>n;
    return 0;
}
