#include <iostream>
#include <algorithm>
#define N 11111
#define M 222222
using namespace std;

struct tree{
	int x,y,z;
	bool operator < (const tree & q) const{
		return z<q.z;
	}
} t[N];

int p[N],n,m;

int dsu_get(int x){
	return x==p[x]?x:p[x]=dsu_get(p[x]);
}

int dsu_unite(int a,int b,int w){
	a=dsu_get(a);
	b=dsu_get(b);
	if (a!=b){
		p[a]=b;
		cout<<a<<" "<<b<<" "<<w<<endl;
	}
}

int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++) p[i]=i;
	for (int i=1;i<=m;i++) cin>>t[i].x>>t[i].y>>t[i].z;
	sort(t+1,t+m+1);
	for (int i=1;i<=m;i++) dsu_unite(t[i].x,t[i].y,t[i].z);
	return 0;
}