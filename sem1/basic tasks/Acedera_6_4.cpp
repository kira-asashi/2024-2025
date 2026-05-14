#include <iostream>
using std::cin;
using std::cout;

int main(){

int userInput,sum=0;
cout<<"Enter a number: ";
cin>>userInput;
for (int i = 1;i<=userInput;i++)
sum += i;
cout<<"The sum from 1 to "<<userInput<<" is: "<<sum;

return 0;
}