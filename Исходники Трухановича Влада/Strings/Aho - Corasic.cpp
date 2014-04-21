#include <memory.h>
#include <iostream>
#include <string>
#include <algorithm>
#define N 111111
#define K 26
using namespace std;

struct bor{
	int next[K],go[K];
	int link,p;
	bool leaf;
	char pch;
} t[N];
int sz;

void init(){
	sz=1;
	memset(t[0].next,255,sizeof(t[0].next));
	memset(t[0].go,255,sizeof(t[0].go));
	t[0].p=t[0].link=-1;
}

void add(string & s){
	int v=0,q=s.length();
	char c;
	for (int i=0;i<q;i++){
		c=s[i]-'a';
		if (t[v].next[c]==-1){
			memset(t[sz].next,255,sizeof(t[sz].next));
			memset(t[sz].go,255,sizeof(t[sz].go));
			t[sz].link=-1;
			t[sz].p=v;
			t[sz].pch=c;
			t[v].next[c]=sz++;
		}
		v=t[v].next[c];
	}
	t[v].leaf=1;
}

int go(int v,char c);

int get_link(int v){
	if (t[v].link==-1){
		if (v==0 || t[v].p==0) t[v].link=0;
		else t[v].link=go(get_link(t[v].p),t[v].pch);
	}
	return t[v].link;
}

int go(int v,char c){
	if (t[v].go[c]==-1){
		if (t[v].next[c]!=-1) t[v].go[c]=t[v].next[c];
		else t[v].go[c]=v==0?0:go(get_link(v),c);
	}
	return t[v].go[c];
}

int main(){}