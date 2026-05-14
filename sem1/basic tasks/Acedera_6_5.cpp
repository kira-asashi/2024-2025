#include <iostream>
using std::cin;
using std::cout;

int main(){

int startNumber, lastNumber, sum=0;
cout<<"Enter starting number: ";
cin>>startNumber;
cout<<"Enter last number: ";
cin>>lastNumber;

if (startNumber<=lastNumber){
cout<<"The numbers are: ";
while (startNumber<=lastNumber){
cout<<startNumber;
startNumber++;
}
}
else cout <<"ERROR.Starting number must be less than or equal to last number";
return 0;
}