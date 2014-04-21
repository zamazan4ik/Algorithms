#include <cstdio>
#define N 19
#define rep(I,B) for (int I=0;I<(B);I++) 

int f[N][N][1<<N+1],n,m,lim;

inline void go(int i,int pos,int msk){
	if (msk&(1<<pos) || !f[i][pos][msk]) return;
	if (pos!=m-1){
		if (msk&(1<<pos+1)) f[i][pos+1][msk^(1<<pos+1)]+=f[i][pos][msk];
		else {
			f[i][pos+1][msk|(1<<pos)]+=f[i][pos][msk];
			if (!(msk&(1<<pos+2))) f[i][pos+1][msk|(1<<pos+2)]+=f[i][pos][msk];
		}
	} else if (i!=n-1){		
		if (msk&(1<<m)) f[i+1][0][(msk^(1<<m))<<1]+=f[i][pos][msk];
		else f[i+1][0][(msk|(1<<m-1))<<1]+=f[i][pos][msk];
	}
}
	
int main(){
	scanf("%d%d",&n,&m);
	f[0][0][0]=1;
	lim=1<<m+1;
	rep(i,n) rep(j,m) rep(msk,lim) go(i,j,msk);
	printf("%d\n",f[n-1][m-1][1<<m]);
	return 0;
}
