#include <string>
#include <iostream>
#define N 111111
using namespace std;

int z[N],n;
string s;

int main(){
	cin>>s;
	n=s.length();
	for (int i=1,l=0,r=0;i<n;i++){
		if (i<=r) z[i]=min(z[i-l],r-i+1);
		while (i+z[i]<n && s[z[i]]==s[i+z[i]]) ++z[i];
		if (i+z[i]-1>r){
			l=i;r=i+z[i]-1;
		}
	}
	for (int i=0;i<n;i++) cout<<z[i]<<" ";
	return 0;
}