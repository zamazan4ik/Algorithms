#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector <int> v;

int delit(int n)
{
    int j=(int)sqrt((double)n);
    for(int i=1;i<=j;++i)
    {
        if(n%i==0)
        {
            v.push_back(i);
            if(i*i != n)
                v.push_back(n/i);
        }
    }
}




int main()
{
    int n;
    cin>>n;
    delit(n);
    for(int i=0;i<v.size();++i)
        cout<<v[i]<<' ';
    cout<<endl;
    system("pause");
    return 0;
}
