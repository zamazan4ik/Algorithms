#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

string s;
int i,size;
vector <int> digit;
vector<char> op;

bool prav(char op)
{
    return op=='^' ? true : false;
}

bool is_op(char c)
{
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='%' || c=='^';
}

bool is_unary()
{
    return i==0 || is_op(s[i-1]) || s[i-1] == '(';
}

int priority(char op)
{
    if(op<0)
        return 4;
    else
        return op=='+' || op=='-' ? 1 :
               op=='*' || op=='/' || op=='%' ? 2 :
               op=='^' ? 3 : -1; 
}

void process_op(char op)
{
    if(op<0)
    {
        int l=digit.back();
        digit.pop_back();
        switch(-op)
        {
            case '+': digit.push_back(l); break;
            case '-': digit.push_back(-l); break;
        }
    }
    else
    {
        int r=digit.back();
        digit.pop_back();
        int l=digit.back();
        digit.pop_back();
        switch(op)
        {
            case '+':digit.push_back(l+r);break;
            case '-':digit.push_back(l-r);break;
            case '*':digit.push_back(l*r);break;
            case '/':digit.push_back(l/r);break;
            case '%':digit.push_back(l%r);break;
            case '^':digit.push_back(int(pow(float(l),float(r))));break;
        }
    }
}

int calc()
{
    size=s.length();
    for(i=0;i<size;++i)
    {
        if(s[i] == '(')
            op.push_back('(');
        else if(s[i] == ')')
        {
            while(!op.empty() && op.back() != '(')
            {
                process_op(op.back());
                op.pop_back();
            }
            op.pop_back();
        }
        else if(is_op(s[i]))
        {
            char curop=s[i];
            if(is_unary())
                curop=-curop;
            while(!op.empty() && (!prav(op.back()) && curop >= 0 && priority(op.back()) >= priority(curop) || prav(op.back()) && priority(op.back()) > priority(curop) ))
            {
                process_op(op.back());
                op.pop_back();
            }
            op.push_back(curop);
        }
        else if(isdigit(s[i]))
        {
            string operand;
            while(i<size && isdigit(s[i]))
            {
                operand+=s[i];
                ++i;
            }
            --i;
            digit.push_back(atoi(operand.c_str()));
        }
    }
    while(!op.empty())
    {
        process_op(op.back());
        op.pop_back();
    }
    return digit.back();
}



int main()
{
    cin>>s;
    cout<<calc()<<endl;
    system("pause");
}











