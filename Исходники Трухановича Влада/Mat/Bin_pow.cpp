//O(logY)
#include <iostream>
using namespace std;

long long binpow(long long x,long long y){
	long long ans=1;
	while (y){
		if (y&1) ans*=x;
		x*=x;
		y>>=1;
    	}
	return ans;
}

int main(void){
    long long x,y,ans;
    cin>>x>>y;
    cout<<binpow(x,y);
    cin>>ans;
}
