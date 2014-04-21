#include <cstdio>
#include <cmath>
#define labs(x) ((x)>0?(x):-(x))

int main(){
	double x1,x2,y1,y2,a,b,c,e=1e-9,z;
	scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
	a=y1-y2;
	b=x2-x1;
	c=-a*x1-b*y1;
	z=sqrt(a*a+b*b);   //norm
	a/=z;b/=z;c/=z;   //norm
	if (a<-e || labs(a)<e && b<-e){ //norm
		a*=-1.0;b*=-1.0;c*=-1.0;//norm
	}
	printf("%lf %lf %lf",a,b,c);
	return 0;
}