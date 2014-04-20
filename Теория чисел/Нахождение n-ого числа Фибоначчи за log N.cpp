#include <iostream>

using namespace std;

int fib(int n)
{
    int a=1,b=1,
        c=1,d=0,
        rc=0,rd=1,
        ta,tb,tc,td;
    while(n)
    {
        if(n & 1)
        {
            tc=rc*a+rd*c;
            td=rc*b+rd*d;
            rc=tc;rd=td;
        }
        ta=a*a+b*c;
        tb=a*b+b*d;
        tc=c*a+d*c;
        td=c*b+d*d;
        a=ta;b=tb;c=tc;d=td;
        n>>=1;
    }
    return rc;
}

int main()
{
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    system("pause");
    return 0;
}

