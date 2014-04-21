#include <iostream>
#define N 111111

using namespace std;

struct cell{
	int l,r,sum;
};

cell t[4*N];
int n,a[N];

void build(int v,int l,int r){
	t[v].l=l;t[v].r=r;
	if (l==r) t[v].sum=a[l];
	else{
		build(v<<1,l,(l+r)>>1);
		build((v<<1)+1,((l+r)>>1)+1,r);
		t[v].sum=t[v<<1].sum+t[(v<<1)+1].sum;
	}
}

void modify(int v,int pos,int val){
	if (t[v].l==t[v].r) t[v].sum=val;
	else{
		if (pos<=(t[v].l+t[v].r)>>1) modify(v<<1,pos,val);
		else modify((v<<1)+1,pos,val);
		t[v].sum=t[v<<1].sum+t[(v<<1)+1].sum;
	}
}

int get(int v,int l,int r){
	if (l>t[v].r || r<t[v].l) return 0;
	if (l==t[v].l && r==t[v].r) return t[v].sum;
	return get(v<<1,l,r)+get((v<<1)+1,l,r);
}

void init(void){
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
}

int main(void){
	init();
	int t,l,r;
	while (cin>>t){
		if (t==0) return 0;
	        cin>>l>>r;
		if (t==1) modify(1,l,r);
		if (t==2) cout<<get(1,l,r)<<endl;
	}
}