#include <iostream> //use while
using std::cin;
using std::cout;

int main()
{
    double num1,num2,product=0;

    cout<<"Enter first number: ";
    cin>>num1;
    cout<<"Enter second number: ";
    cin>>num2;
    int i=1;
    while (i <= num2)
    {
    i++;
    product += num1;
    }
    cout<<"The product is: "<<product;
    
    return 0;
}
