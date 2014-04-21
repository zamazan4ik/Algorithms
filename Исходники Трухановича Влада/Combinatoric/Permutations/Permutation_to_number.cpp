#include <cstdio>

int n;
long long f[21],k;
int a[21],b[21];

void init(){
	f[0]=1;
	for (int i=1;i<=20;i++) f[i]=f[i-1]*i;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
}

int main(){
	init(); 
	for (int i=1;i<=n;i++){
		int c=0;
		for (int j=1;j<a[i];j++) if (!b[j]) ++c;
		k+=f[n-i]*c;
		b[a[i]]=1;
	}
	printf("%I64d\n",k+1);
	return 0;
}