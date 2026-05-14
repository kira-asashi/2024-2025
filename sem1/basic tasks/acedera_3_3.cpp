#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
float a,b,sum,difference,product,quotient = 0;
int c,d,remainder;


    cout << "Enter two numbers:";
    cin >> a >> b;
    c = a, d = b;
    sum = a+b;
    difference = a-b;
    product = a*b;
    quotient = a/b;
    remainder = c % d;
    cout <<left;
    cout <<setw(15)<<"SUM"  <<setw(15) <<"DIFFERENCE" <<setw(15)    <<"PRODUCT" <<setw(15) <<"QUOTIENT" <<"REMAINDER" <<endl;
    cout <<setw(15)<<sum    <<setw(15) <<difference   <<setw(15)    <<product   <<setw(15) <<quotient   <<remainder   <<endl;

return 0;
}