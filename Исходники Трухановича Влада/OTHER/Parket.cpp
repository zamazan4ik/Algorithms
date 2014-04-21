#include <iostream>
#define rep(I,B) for (int I=0;I<(B);I++) 
#define N 20
using namespace std;

long long f[N][1<<N];
int n,m;

void calc(int x,int y,int mask,int next_mask){
	if (y>=m) f[x+1][next_mask]+=f[x][mask];
	else {
		int cur=1<<y;
		if (mask&cur) calc(x,y+1,mask,next_mask);
		else {
			calc(x,y+1,mask,next_mask|cur);
			if (y<m-1 && !(mask&(cur<<1))) calc(x,y+2,mask,next_mask);
		}
	}
}

int main(){
	cin>>n>>m;
	int lim=1<<m;
	rep(i,lim) f[0][0]=1;
	rep(i,n) rep(msk,lim) calc(i,0,msk,0);
	cout<<f[n][0];
	return 0;
}