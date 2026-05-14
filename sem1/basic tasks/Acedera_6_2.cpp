#include <iostream>
using std::cin;
using std::cout;
int main()
{
    int num, i=1;
    long int factorial=1;

    cout<<"Enter an integer number: ";
    cin>>num;
    
    do{
    factorial *= i;
    i++; }
    while (i<=num);
    
    cout<<"The factorial of "<<num<<" is: "<<factorial;

    return 0;
}
