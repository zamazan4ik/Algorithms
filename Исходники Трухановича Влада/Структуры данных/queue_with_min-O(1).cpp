#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

stack <pair<int,int> > s1,s2;

void push(int x){
	int minim=s1.empty()?x:min(x,s1.top().second);
	s1.push(make_pair(x,minim));
}

int getmin(void){
	if (s1.empty() || s2.empty()) return s1.empty()?s2.top().second:s1.top().second;
	return min(s1.top().second,s2.top().second);
}

int pop(void){
	if (s2.empty())
		while (!s1.empty()){
			int x=s1.top().first;
			s1.pop();
			int minim=s2.empty()?x:min(x,s2.top().second);
			s2.push(make_pair(x,minim));
		}
	int x=s2.top().first;
	s2.pop();
	return x;
}

bool empty(void){
	return s1.empty() && s2.empty();
}

int main(void){
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		int x;
		cin>>x;
		push(x);
	}
	for (int i=m+1;i<=n;i++){
		int x;
		cin>>x;
		cout<<getmin()<<endl;
		push(x);
		pop();
	}
	return 0;
}