// O(X^0.5)
#include <iostream>
#include <cmath>

using namespace std;

void fact(int n){
	int i,en=sqrt(n);
	for (i=2;i<=en;i++) if (n%i==0){
		while (n%i==0) n/=i;
            	cout<<i<<" ";
        }	
        if (n>1) cout<<n<<" ";
}

int main(void){
	int x;
	cin>>x;
	fact(x);
	cin>>x;
	return 0;
}