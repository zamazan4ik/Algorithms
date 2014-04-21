#include <cstdio>
#include <cmath>
#define labs(x) ((x)>0?(x):-(x))
#define eps 1e-5

bool parallel(double a1, double b1, double c1, double a2, double b2, double c2){
	return labs(a1*b2-a2*b1)<eps;
}

bool eq(double a1, double b1, double c1, double a2, double b2, double c2){
	return labs(a1-a2)<eps && labs(b1-b2)<eps && labs(c1-c2)<eps;
}

bool intersect(double a1, double b1, double c1, double a2, double b2, double c2, double &x, double &y){
	if (parallel(a1,b1,c1,a2,b2,c2)) return 1^eq(a1,b1,c1,a2,b2,c2);
	x=(c2*b1-c1*b2)/(a1*b2-a2*b1);
	y=(c1*a2-c2*a1)/(a1*b2-a2*b1);
	return true;
}	

int main(){
	double a1,a2,b1,b2,c1,c2;
	