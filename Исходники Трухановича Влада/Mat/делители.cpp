// O(N^0.5)
#include <iostream>

using namespace std;

int f(int x,int p=0){
    int c=0;
    for (int i=2;i*i<=x;i++){
        if (x%i==0){
            if (p) cout<<i<<" ";
            ++c;
            if (i*i!=x){
                ++c;
                if (p) cout<<x/i<<" ";
            }
        }
    }
    if (p) cout<<endl;
    return c;
}

int main(void){
    int x;
    while(cin>>x) f(x,1);
    return 0;
}
