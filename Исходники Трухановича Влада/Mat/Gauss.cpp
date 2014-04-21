#include <iostream>
#include <algorithm>
#include <cmath>
#define forn(I,B) for (int I=1;I<=(B);I++)

using namespace std;

const int N=111;
const double eps=1e-9;

double a[N][N],ans[N];
int n,m,where[N],k=-1;

int main(){
	cin>>n>>m;
	forn(i,n) forn(j,m) cin>>a[i][j];
	forn(i,m-1) where[i]=-1;
	for (int col=1,row=1;col<m && row<=n;++col){
		int sel=row;
		for (int i=row+1;i<=n;i++) 
			if (abs(a[i][col])>abs(a[sel][col])) sel=i;
		if (abs(a[sel][col])<eps) continue;
		for (int i=col;i<=m;i++) swap(a[sel][i],a[row][i]);
		where[col]=row;
		for (int i=1;i<=n;i++) if (i!=row){
			double c=a[i][col]/a[row][col];
			for (int j=col;j<=m;j++) a[i][j]-=a[row][j]*c;
		}
		++row;
	}
	forn(i,m-1) if (where[i]!=-1) ans[i]=a[where[i]][m]/a[where[i]][i];
	forn(i,n) {
		double sum=0;
		forn(j,m-1) sum+=ans[j]*a[i][j];
		if (abs(sum-a[i][m])>eps) k=0;
	}
	if (k!=0){
		forn(i,m-1) if (where[i]==-1) k=2;
		if (k!=2) k=1;
	}
	cout<<k<<endl;
	forn(i,m-1) cout<<ans[i]<<" ";
}