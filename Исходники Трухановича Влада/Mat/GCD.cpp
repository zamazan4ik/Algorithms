//O(log)
#include <iostream>

using namespace std;

long long gcd(long long x,long long y){
    return y?gcd(y,x%y):x;
}

int main(void){
    long long a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
    cin>>a;
    return 0;
}
