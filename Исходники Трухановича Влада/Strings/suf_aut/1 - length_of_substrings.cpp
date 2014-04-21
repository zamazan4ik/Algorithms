#include <string>
#include <map>
#include <iostream>
#include <memory.h>
using namespace std;
#define N 111111

struct _SA{
	int link,len;
	map<char,int> next;
} st[N+N];
int sz,last,d[N+N],ans[N+N];

void init(){
	last=0;
	sz=1;
	st[0].link=-1;
	st[0].len=0;
	memset(d,255,sizeof(d));
	memset(ans,255,sizeof(ans));
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

int f(int v){
	if (d[v]!=-1) return d[v];                                                   
	int anss=1;
	for (map<char,int>::iterator it=st[v].next.begin();it!=st[v].next.end();it++) anss+=f(it->second);
	d[v]=anss;
	return anss;
}

int F(int v){
	if (ans[v]!=-1) return ans[v];
	int anss=0;
	for (map<char,int>::iterator it=st[v].next.begin();it!=st[v].next.end();it++) anss+=F(it->second)+f(it->second);
	ans[v]=anss;
	return anss;
}

int main(){
	string s;cin>>s;
	init();
	for (int i=0;i<s.length();i++) ins(s[i]);
	d[last]=1;f(0);
	ans[last]=0;
	cout<<F(0);
}