#include <cstdio>

int res;
char s;

inline int getInt(){
	res=0;
	do{
		s=getchar();
	} while (s<'0' || s>'9');
	do{
		res=res*10+s-'0';
		s=getchar();
	} while (s>='0' && s<='9');
	return res;
}

void put(int x){
	if (x){
		put(x/10);
		putchar(x%10+'0');
	}
}

inline void putInt(int x){
	if (x) put(x);
	else putchar('0');
	putchar('\n');
}           

int main(){
	int x=getInt();
	putInt(x+1);
	return 0;
}