#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define N 111111
#define INF 1111111111

using namespace std;

struct tree{
	int l,r;
	vector<int> v;
} t[4*N];
int n,r,a[N];

void build(int v,int l, int r){
	t[v].l=l;t[v].r=r;
	if (l==r) t[v].v=vector<int>(1,a[l]);
	else{
		build(v+v,l,(l+r)/2);
		build(v+v+1,(l+r)/2+1,r);
		merge(t[v+v].v.begin(),t[v+v].v.end(),t[v+v+1].v.begin(),t[v+v+1].v.end(),back_inserter(t[v].v));
	}
}

int ask1(int v,int l,int r,int x){
	if (l>t[v].r || r<t[v].l) return INF;
	if (t[v].l>=l && t[v].r<=r){
		vector<int>::iterator pos=lower_bound(t[v].v.begin(),t[v].v.end(),x);
		if (pos!=t[v].v.end()) return *pos;
		return INF;
	}
	return min(ask1(v+v,l,r,x),ask1(v+v+1,l,r,x));
}

int ask2(int v,int l,int r,int x){
	if (l>t[v].r || r<t[v].l) return -INF;
	if (t[v].l>=l && t[v].r<=r){
		vector<int>::iterator pos=lower_bound(t[v].v.begin(),t[v].v.end(),x);
		if (*pos==x) return *pos;
		if (pos==t[v].v.begin()) return -INF;
		--pos;
		return *pos;
	}
	return max(ask2(v+v,l,r,x),ask2(v+v+1,l,r,x));
}

void init(void){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>r;
	int i;
	for (int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
}

void sol(void){
	while (r--){
		int x,l,r;
		int f1,f2;
		cin>>l>>r>>x;
		f1=ask1(1,l,r,x);
		f2=ask2(1,l,r,x);
		if (f1==INF) cout<<f2;
		if (f2==-INF) cout<<f1;
		if (f1!=INF && f2!=-INF){
			if (abs(f1-x)<abs(f2-x)) cout<<f1;
			else cout<<f2;
		}
		cout<<endl;
	}
}

int main(void){
	init();
	sol();
	return 0;
}