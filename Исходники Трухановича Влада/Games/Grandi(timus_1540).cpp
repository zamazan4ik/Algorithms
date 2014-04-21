#pragma comment(linker, "/STACK:65777216")
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define N 55

using namespace std;

int len[N],g[N][N+N][N+N],a[N][N],t[N],c;

inline int mex(){
	sort(t,t+c);
	if (t[0]!=0) return 0;
	for (int i=1;i<c;++i) if (t[i]-t[i-1]>1) return t[i-1]+1;
	return t[c-1]+1;
}

void calc(int num,int l,int r){
	for (int i=l;i<=r;++i){
		int go=a[num][i],pos;
		for (pos=l;a[num][pos]<=go && pos<=r;++pos);
		for (int j=pos;j<=r+1;++j)
			if (a[num][j]<=go || j==r+1){
				if (pos<=j-1 && g[num][pos][j-1]==-1) calc(num,pos,j-1);
				pos=j+1;
			}
	}
	c=0;
	for (int i=l;i<=r;++i){
		int go=a[num][i],pos,ans=0;
		for (pos=l;a[num][pos]<=go && pos<=r;++pos);
		for (int j=pos;j<=r+1;++j)
			if (a[num][j]<=go || j==r+1){
				if (pos<=j-1) ans^=g[num][pos][j-1];
				pos=j+1;
			}
		t[c++]=ans;
	}
	g[num][l][r]=mex();
}

inline bool good(int n,int num,int go){
	int ans=0;
	for (int i=1;i<=n;i++) if (i!=num) ans^=g[i][1][len[i]];
	int pos;
	for (pos=1;a[num][pos]<=go && pos<=len[num];++pos);
	for (int j=pos;j<=len[num]+1;++j)
		if (a[num][j]<=go || j==len[num]+1){
			if (pos<=j-1) ans^=g[num][pos][j-1];
			pos=j+1;
		}
	return ans==0;
}

int main(){
//	freopen("input.txt","r",stdin);
	int n,ans=0;
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&len[i]);
		for (int j=1;j<=len[i];++j) scanf("%d",&a[i][j]);
	}
	memset(g,255,sizeof(g));
	for (int i=1;i<=n;++i) for (int j=1;j<=len[i];++j) g[i][j][j]=1;
	for (int i=1;i<=n;++i) if (len[i]!=1) calc(i,1,len[i]);
	for (int i=1;i<=n;++i) ans^=g[i][1][len[i]];
	if (!ans) puts("S");
	else {
		puts("G");
		for (int i=1;i<=n;++i) for (int j=1;j<=len[i];++j)
			if (good(n,i,a[i][j])){
				printf("%d %d\n",i,j);
				return 0;
			}
	}
	return 0;
}
