#include <iostream>
using std::cin;
using std::cout;

int main()
{
    int userInput,i=1, star=1;
    cout<<"Enter a positive integer: ";
    cin>>userInput;
    if (userInput <= 0){
    cout<<"Invalid input. Please enter a positive number."<<std::endl;    
    } else{
    for (i=1;i<=userInput;i++){
    for (star=1;star<=i;star++){
    cout<<"*";
    }
    cout<<std::endl;
    }
    } 
    return 0;

}

