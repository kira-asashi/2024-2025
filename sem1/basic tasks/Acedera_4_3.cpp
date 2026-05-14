#include <iostream>
#include <math.h>
using std::cout;
using std::cin;

int main()
{
    float a,b,c,angle_C;
    cout<<"Enter a: ";
    cin>>a;
    cout<<"Enter b: ";
    cin>>b;
    cout<<"Enter C: ";
    cin>>angle_C;
    c = sqrt(pow(a,2)+pow(b,2)-((2)*(a*b)*cos(angle_C)));
    cout<<"Value of c is: "<<c;
    return 0;
}