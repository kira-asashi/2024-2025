#include <iostream>
using namespace std;

int main(){
int num = 10;
int* ptr = &num;

cout << "Value of num before modification: " << num << endl;
cout << "Address of num(&num): " << &num << endl;
cout << "Value stored in ptr (address of num): " << ptr << endl;
cout << "Value accessed via ptr(*ptr): " << *ptr << endl;
*ptr = 20; //change value
cout << "\nAfter modification: \n" << endl;
cout << "Update value of num: " << num << endl;
cout << "Value accessed via ptr(*ptr): " << *ptr << endl;
    
    return 0;
}