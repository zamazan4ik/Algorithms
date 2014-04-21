#include <iostream>
#include <string>

using namespace std;

int main(){
	string s,t;
	cin>>s>>t;
	s=t+"$"+s;  
	int n=s.length(),p[n],i,j=0;  
	p[0]=0;                        
	for (i=1;i<n;i++){
		while (j>0 && s[i]!=s[j]) j=p[j-1];
		if (s[i]==s[j]) ++j;
		p[i]=j;
	}
	for (i=t.length();i<n;i++)
		if (p[i]==t.length()){
			cout<<"YES";
			return 0;
		}
	cout<<"NO";
	return 0;
}
