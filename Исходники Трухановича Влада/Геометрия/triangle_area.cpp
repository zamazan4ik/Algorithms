#include <cstdio>
#define labs(x) ((x>0)?(x):-(x))

double x1,x2,x3,y1,y2,y3;

double _area(double x1, double y1, double x2, double y2, double x3, double y3){
	return (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2.0;
}

double area(double x1, double y1, double x2, double y2, double x3, double y3){
	return labs(_area(x1,y1,x2,y2,x3,y3));
}

bool clockwise(double x1, double y1, double x2, double y2, double x3, double y3){
	return _area(x1,y1,x2,y2,x3,y3)<0.0;
}

bool counterclockwise(double x1, double y1, double x2, double y2, double x3, double y3){
	return _area(x1,y1,x2,y2,x3,y3)>0.0;
}


int main(){
	scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);
	printf("%lf %d",area(x1,y1,x2,y2,x3,y3),clockwise(x1,y1,x2,y2,x3,y3));
	return 0;
}