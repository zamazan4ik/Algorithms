#include <memory.h>

void resheto(bool prime[])
{
    for(i=3;(temp=i*i) <=n;i+=2)
        if(prime[i])
            for(j=temp;j<=n;j+=i)
                prime[j]=false;
}

int main()
{
    bool *prime=new bool[n+1];
    memset(prime,1,n+1);
    prime[0]=prime[1]=false;
    resheto(prime);
}
