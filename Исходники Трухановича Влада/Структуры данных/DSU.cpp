#include <iostream>
#include <cstdlib>
#define maxn 11111

using namespace std;

int p[maxn],n;

void init(void){
    for (int i=0;i<=n;i++) p[i]=i;
}

void makeset (int x){
	p[x]=x;
}

int findset (int x){
	if (x==p[x]) return x;
	return p[x]=findset(p[x]);
}

void unite(int x,int y){
	x=findset(x);
	y=findset(y);
	p[x]=y;
}

int main(void){
    cin>>n;
    init();
    unite(1,2);
    makeset(8);
    for (int i=1;i<=8;i++) cout<<findset(i)<<" ";
    cin>>n;
}
