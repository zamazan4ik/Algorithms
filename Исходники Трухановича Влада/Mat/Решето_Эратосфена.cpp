//O(N log log N)
#include <cstdio>
#define maxn 300000

int n,i,j;
bool b[maxn];

int main(void){
    scanf("%d",&n);
    freopen("out.out","w",stdout);
    b[0]=b[1]=true;
    for (i=2;i*i<=n;i++)
        if (!b[i]) for (j=i*i;j<=n;j+=i) b[j]=true;
    for (i=1;i<=n;i++) if (!b[i]) printf("%d ",i);
    return 0;
}

