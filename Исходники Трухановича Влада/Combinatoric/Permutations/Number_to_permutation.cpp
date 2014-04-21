#include <cstdio>

int n;
long long f[21],k;
int a[21],b[21];

void init(){
	f[0]=1;
	for (int i=1;i<=20;i++) f[i]=f[i-1]*i;
	scanf("%d%I64d",&n,&k);--k;
}

int main(){
	init();
	for (int i=1;i<=n;i++){
		int q=k/f[n-i]+1;
		k%=f[n-i];
		int c=0;
		for (int j=1;j<=n;j++){
			if (!b[j]) ++c;
			if (c==q){
				b[j]=1;
				a[i]=j;
				break;
			}
		}
	}
	for (int i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;
}