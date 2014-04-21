#include <string>
#include <map>
#include <iostream>
using namespace std;
#define N 111111

struct _SA{
	int link,len;
	map<char,int> next;
} st[N+N];

int sz,last;

void init(){
	last=0;
	sz=1;
	st[0].link=-1;
	st[0].len=0;
}

void ins(char c){
	int cur=sz++;
	st[cur].len=st[last].len+1;
	int p;
	for (p=last;p!=-1 && !st[p].next.count(c);p=st[p].link) st[p].next[c]=cur;
	if (p==-1) st[cur].link=0;
	else{
		int q=st[p].next[c];
		if (st[p].len+1==st[q].len) st[cur].link=q;
		else{
			int clone=sz++;
			st[clone]=st[q];
			st[clone].len=st[p].len+1;
			for(;p!=-1 && st[p].next[c]==q;p=st[p].link) st[p].next[c]=clone;
			st[q].link=st[cur].link=clone;
		}
	}
	last=cur;
}


int main(){
	string s;
	cin>>s;
	init();
	for (int i=0;i<s.length();i++) ins(s[i]);
	string t;
	cin>>t;
	int cur=0;
	for (int i=0;i<t.length();i++){
		if (!st[cur].next.count(t[i])){
			cout<<"NO";
			return 0;
		}else cur=st[cur].next[t[i]];
	}
	cout<<"YES";
}