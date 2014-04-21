#include <iostream>
#include <string>
#define P 31

using namespace std;

string s;
int i1,i2,len,n;
long long h[1111],p[1111];

int main(void){
	cin>>s>>i1>>i2>>len;
	n=s.length();
	p[0]=1;
	for (int i=1;i<n;i++) p[i]=p[i-1]*P;
	h[0]=s[0]-'a'+1;
	for (int i=1;i<n;i++) h[i]=h[i-1]+(s[i]-'a'+1)*p[i];
	long long h1=(h[i1+len-1]-(i1?h[i1-1]:0))*p[n-i1-len];
	long long h2=(h[i2+len-1]-(i2?h[i2-1]:0))*p[n-i2-len];
	if (h1==h2) cout<<1;
	else cout<<0;
	cin>>s;
	return 0;
}
