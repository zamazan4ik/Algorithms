#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <memory.h>
#define memo(A) memset(A,0,sizeof(A))
#define rep(I,B) for (int I=0;I<(B);I++) 
#define N 1111

using namespace std;


int n,a[N],g[N],ba[N],ans,dsum[N],ddif[N];

inline double get_rand(){
	return ((rand()*1ll*rand()*rand())%1000000001)/1000000000.0;
}

inline void get_next(int k) {
	int p[N],r[N];
	rep(i,n) p[i]=r[i]=i;
	rep(i,k) swap(p[i],p[n-1-rand()%(n-i)]);
	for (int i=k-1;i>0;i--) swap(r[i],r[rand()%(i+1)]);
	rep(i,n) g[i]=a[i];
	rep(i,k) g[p[i]]=a[p[r[i]]];
}

inline int eval(){
	int res=0;
	memo(dsum);memo(ddif);
	rep(i,n){
		res+=dsum[i+g[i]];
		++dsum[i+g[i]];
		res+=ddif[i-g[i]+n];
		++ddif[i-g[i]+n];
	}
	return res;
}

inline double prob(int cur,int nw,double t){
	int delta=nw-cur;
	if (delta<0) return 1.0;
	else return exp(-delta/t);
}

int main(){
	srand(time(NULL));
	scanf("%d",&n);
	int cure;
	rep(i,n) g[i]=i;
	random_shuffle(g,g+n);
	rep(i,n) a[i]=ba[i]=g[i];
	cure=ans=eval();
	double mxt=20.0;
	for (double t=mxt;ans;t*=0.98){
		int k=max(2,(int)(t/mxt*n));
		get_next(k);
		int ne=eval();
		if (prob(cure,ne,t)>=get_rand()){
			cure=ne;
			rep(i,n) a[i]=g[i];
		}
		if (cure<ans){
			ans=cure;
			rep(i,n) ba[i]=a[i];
		}
	}
	rep(i,n) printf("%d ",ba[i]+1);
	return 0;
}
