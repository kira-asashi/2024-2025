#include <iostream>
#include <math.h>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    double a,b,c;

    cout<<"Enter the length of leg AC: ";
    cin>>a;
    cout<<"Enter the length of leg AB: ";
    cin>>b;
    c = pow(a,2) + pow(b,2);
    c = sqrt(c);
    cout<<"The hypotenus of the triangle is: "<<c;  

    return 0;

}   
