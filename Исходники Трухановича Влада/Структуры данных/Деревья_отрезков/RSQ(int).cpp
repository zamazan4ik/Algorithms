#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define N 111111
struct cell{
	int l,r,sum,add;
} a[4*N];

void build(int x,int l,int r){
	a[x].l=l;a[x].r=r;a[x].sum=a[x].add=0;
	if (a[x].l<a[x].r){
		build(x+x,l,(l+r)>>1);
		build(x+x+1,1+((l+r)>>1),r);
	}
}

int get_sum(int x,int sumadd=0){
	return a[x].sum+(a[x].r-a[x].l+1)*(a[x].add+sumadd);
}

void modify(int x,int l,int r,int val){
	if (!x || a[x].r < l || a[x].l > r) return;
	if (l<=a[x].l && r>=a[x].r){
		a[x].add+=val;
		return;
	}
	modify(x+x,l,r,val);
	modify(x+x+1,l,r,val);
	a[x].sum=get_sum(x+x)+get_sum(x+x+1);
}

int findsum(int x,int l,int r,int sumadd){
	if (!x || a[x].r<l || a[x].l>r) return 0;
	if (l<=a[x].l && r>=a[x].r) return get_sum(x,sumadd);
	return findsum(x+x,l,r,sumadd+a[x].add)+findsum(x+x+1,l,r,sumadd+a[x].add);
}

int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	
	int n,q;
	cin>>n>>q;
	
	build(1,1,n);
	while (q--){
		int t,l,r,val; cin >> t;
		if (t==1){
			cin>>l>>r>>val;
			modify(1,l,r,val);
		}else{
			cin>>l>>r;
			cout<<findsum(1,l,r,0)<<endl;
		}
	}
	
	return 0;
}