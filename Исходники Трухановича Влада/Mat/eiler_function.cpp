//O(N^0.5)
#include <iostream>
#include <cmath>

using namespace std;

int f(int n){
	int i,res=n,en=sqrt(n);
	for (i=2;i<=en;i++) if (n%i==0){
		while (n%i==0) n/=i;
            	res-=res/i;
        }	
	if (n>1) res-=res/n;
	return res;
}

int main(void){
	int x;
	while(cin>>x) cout<<f(x)<<endl;
	cin>>x;
	return 0;
}
