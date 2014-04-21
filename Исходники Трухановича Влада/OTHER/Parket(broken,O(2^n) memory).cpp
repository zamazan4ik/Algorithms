#include <cstdio>
#define N 26
#define rep(I,B) for (int I=0;I<(B);I++) 

int f[2][1<<N+1],n,m,lim,c;

inline void go(int i,int pos,int msk){
	if (msk&(1<<pos)) return;
	if (pos!=m-1){
		if (msk&(1<<pos+1)) f[c^1][msk^(1<<pos+1)]+=f[c][msk];
		else {
			f[c^1][msk|(1<<pos)]+=f[c][msk];
			if (!(msk&(1<<pos+2))) f[c^1][msk|(1<<pos+2)]+=f[c][msk];
		}
	} else {		
		if (msk&(1<<m)) f[c^1][(msk^(1<<m))<<1]+=f[c][msk];
		else f[c^1][(msk|(1<<m-1))<<1]+=f[c][msk];
	}
}
	
int main(){
	scanf("%d%d",&n,&m);
	if (n<m){int t=n;n=m;m=t;}
	f[0][0]=1;
	lim=1<<m+1;
	rep(i,n) rep(j,m) {
			rep(msk,lim) f[c^1][msk]=0;
			rep(msk,lim) go(i,j,msk);
			c^=1;
	}
	printf("%d\n",f[c^1][1<<m]);
	return 0;
}
