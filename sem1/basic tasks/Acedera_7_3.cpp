#include <iostream>
using std::cin;
using std::cout;

int highestCommonFactor (int num1,int num2){
while (num2 != 0){
int remainder = num1 % num2;    
num1 = num2;
num2 = remainder;
}
return num1;
}

int main (){
int num1,num2;
cout<<"Enter two positive integers: ";
cin>>num1>>num2;

int hcf = highestCommonFactor(num1,num2);
cout<<"HCF of "<<num1<<" and "<<num2<<" is "<<hcf;

return 0;
}


