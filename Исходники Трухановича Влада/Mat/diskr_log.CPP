// a^x=b (mod m)
// работает только когда gcd(a,m)=1 
// O(M^0.5*logM);
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int powmod(int x,int y,int mod){
	int res=1;
	while (y){
		if (y&1) res=(res*1ll*x)%mod;
		x=(x*1ll*x)%mod;
		y>>=1;
	}
	return res;
}

int discr_log(int a,int b,int m){
	int n=(int)(sqrt(m+.0))+1,an=1;
	map<int,int> vals;
	an=powmod(a,n,m);
	for (int i=1,cur=an;i<=n;i++){
		if (!vals.count(cur)) vals[cur]=i;
		cur=(cur*1ll*an)%m;
	}
	for (int i=0,cur=b;i<=n;i++){
		if (vals.count(cur)){
			int ans=n*vals[cur]-i;	
			if (ans<m) return ans;
		}
		cur=(cur*1ll*a)%m;
	}
	return -1;
}

int main(void){
	int a,b,m;
	cin>>a>>b>>m;
	cout<<discr_log(a,b,m)<<endl;
	cin>>a;
	return 0;
}