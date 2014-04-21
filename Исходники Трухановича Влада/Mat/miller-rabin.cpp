#include <iostream>
#include <cstdlib>
#include <ctime>
#define ll long long

using namespace std;

inline ll mulmod(ll x,ll y,ll m){
	ll ans=0;
	while (y){
		if (y&1) ans=(ans+x)%m;
		x=(x+x)%m;
		y>>=1;
    	}
	return ans;
}

inline ll powmod(ll x,ll y,ll m){
	ll ans=1;
	while (y){
		if (y&1) ans=mulmod(ans,x,m);
		x=mulmod(x,x,m);
		y>>=1;
    	}
	return ans;
}


inline bool check(int m){
	int  s=0,t=m-1,x,a=((rand()*rand())%(m-3))+2;
	while (!(t&1)){
		++s;
		t>>=1;
	}
	x=powmod(a,t,m);
	if (x==1 || x==m-1) return true;
	while(--s){
		x=mulmod(x,x,m);
		if (x==1) return false;
		if (x==m-1) return true;
	}
	return false;
}

inline bool test(ll x,int r){
	if (x==2 || x==3) return true;
	if (x==1 || !(x&1)) return false;
	if (x<=100){
		if (x%3==0) return 0;
		for (ll i=5;i*i<=x;i+=6){
			if (x%i==0) return 0;
			if (x%(i+2)==0) return 0;
		}
		return 1;
	}
	bool ok=true;
	while (r-- && ok) ok&=check(x);
	return ok;
}

int main(){
	srand(time(NULL));
	ll f;
	cin>>f;
	cout<<test(f,100);
	return 0;
}