// a*b=1(mod m).
// b==a^(-1)-?  (обратный элемент в кольце по модулю m)
// only if gcd(a,m)=1.
// O(log)
#include <iostream>

using namespace std;

int a,m;

int gcd (int a, int b, int & x, int & y) {
	if (a==0){
		x=0; 
	        y=1;
		return b;
	}
	int x1,y1;
	int d=gcd(b%a,a,x1,y1);
	x=y1-(b/a)*x1;
	y=x1;
	return d;
}

int main(void){
	cin>>a>>m;
	int x,y,g=gcd(a,m,x,y);
	if (g!=1) cout<<"NO SOLUTION";
	else cout<<(x%m+m)%m;
	cin>>x;
	return 0;
}