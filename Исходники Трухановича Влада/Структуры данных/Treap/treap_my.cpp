#include <iostream>
#include <algorithm>
#define N 111111

using namespace std;

struct treap{
	int ls,rs,x,y;
} t[N];

int a[N],root,n,c;

void merge(int &x,int l,int r){
	if (!l || !r) x=l?l:r;
	else if (t[l].y>t[r].y) x=l,merge(t[x].rs,t[x].rs,r);
	else x=r,merge(t[x].ls,l,t[x].ls);
}

void split (int x,int key,int &l,int &r){
	if (!x) l=r=0;
	else if (t[x].x<=key) l=x,split(t[x].rs,key,t[x].rs,r);
	else r=x,split(t[x].ls,key,l,t[x].ls);
}

void insert(int & x,int num){
	if (!x) x=num;
	else if (t[x].y<t[num].y) split(x,t[num].x,t[num].ls,t[num].rs),x=num;
	else insert(t[x].x<t[num].x?t[x].rs:t[x].ls,num);
}

void erase(int & x,int key){
	if (!x) return;
	else if (t[x].x==key) merge(x,t[x].ls,t[x].rs);
	else erase(t[x].x<=key?t[x].rs:t[x].ls,key);
}

void print(int x){
	if (!x) return;
	print(t[x].ls);
	cout<<t[x].x<<" ";
	print(t[x].rs);
}

int main(){
	cin>>n;
	for (int i=0;i<n;i++) a[i]=i;
	random_shuffle(a,a+n);
	for (int i=0;i<n;i++){
		cin>>t[++c].x;
		t[c].y=a[i];
		insert(root,c);
	}
	print(root);
	cout<<endl;
	int x;
	cin>>x;
	erase(root,x);
	print(root);
}