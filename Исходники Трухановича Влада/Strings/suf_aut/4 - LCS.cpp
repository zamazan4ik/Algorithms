#include <iostream>
#include <string>
#include <map>
#include <memory.h>
#define N 222222
using namespace std;

struct _SA{
	int link,len;
	map<char,int> next;
} st[N];

int sz,last,n,bpos,blen;
string s,t;

void init(){
	cin>>n>>s>>t;
	sz=1;last=0;
	st[0].len=0;
	st[0].link=-1;
}

void add(char c){
	int cur=sz++,p;
	st[cur].len=st[last].len+1;
	for (p=last;p!=-1 && !st[p].next.count(c);p=st[p].link) st[p].next[c]=cur;
	if (p==-1) st[cur].link=0;
	else{
		int q=st[p].next[c];
		if (st[q].len==st[p].len+1) st[cur].link=q;
		else{
			int clone=sz++;
			st[clone].len=st[p].len+1;
			st[clone].next=st[q].next;
			st[clone].link=st[q].link;
			for(;p!=-1 && st[p].next[c]==q;p=st[p].link) st[p].next[c]=clone;
			st[q].link=st[cur].link=clone;
		}
	}
	last=cur;
}

int main(){
	ios_base::sync_with_stdio(0);
	init();
	for (int i=0;i<n;i++) add(s[i]);
	int v=0,l=0;
	for (int i=0;i<n;i++){
		while (v!=-1 && !st[v].next.count(t[i])){
			v=st[v].link;
			l=st[v].len;
		}
		if (v==-1) v=l=0;
		else{
			v=st[v].next[t[i]];
			++l;
		}
		if (l>blen){
			blen=l;
			bpos=i;
		}
	}
	for (int i=bpos-blen+1;i<=bpos;i++) cout<<t[i];
	cout<<endl;
	return 0;
}