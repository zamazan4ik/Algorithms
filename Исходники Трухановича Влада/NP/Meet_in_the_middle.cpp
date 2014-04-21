#include <cstdio>
#include <algorithm>
#define N 22
using namespace std;

int a[N],b[N],c[N],n,s1[1111],s2[1111],m,k,ans=1111111111,sum;

void init(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	m=n/2,k=n-n/2;
	for (int i=1;i<=m;i++) b[i]=a[i];
	for (int i=1;i<=k;i++) c[i]=a[i+m];
}

int main(){
	init();
	for (int i=0;i<(1<<m);i++){
		int cur=0;
		for (int j=0;j<m;j++) if (i & (1<<j)) cur+=b[j+1];
		s1[i]=cur;
	}
	for (int i=0;i<(1<<k);i++){
		int cur=0;
		for (int j=0;j<k;j++) if (i & (1<<j)) cur+=c[j+1];
		s2[i]=cur;
	}
	sort(s1,s1+(1<<m));sort(s2,s2+(1<<k));
	for (int i=0;i<(1<<m);i++){
		int p=lower_bound(s2,s2+(1<<k),sum/2-s1[i])-s2;
		while (s2[p]>sum/2-s1[i] && p) --p;
		p=s2[p];
		ans=min(ans,abs(sum-s1[i]-s1[i]-p-p));
	}
	printf("%d\n",ans);
	return 0;
}
		