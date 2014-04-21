//для простого p. Иначе заменить phi=p-1 на phi=fi(p);
//O(ans*log fi(N)*logN)
#include <iostream>

using namespace std;

int powmod (int a,int b,int p){
	int res=1;
	while (b) 
		if (b&1){
			res=int(res*1ll*a%p);  
			--b;
		}
		else{ 
			a=int(a*1ll*a%p);
			b>>=1;
		}
	return res;
}
 
int generator (int p){
	int fact[100],j=0;
	int phi=p-1,n=phi;
	for (int i=2;i*i<=n;++i)
		if (n%i==0){
			fact[++j]=i;
			while (n%i==0) n/=i;
		}
	if (n>1) fact[++j]=n; 
	for (int res=2;res<=p;++res){
		bool ok=true;
		for (int i=1;i<=j && ok;i++) ok&=powmod(res,phi/fact[i],p)!=1;
		if (ok) return res;
	}
	return -1;
}