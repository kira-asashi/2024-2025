#include <iostream>
using namespace std;

int main(){
int size;
cout << "Enter the size of the array: ";
cin >> size;
int* arr = new int[size];

cout << "Enter " << size << " integers:" << endl;
for (int i = 0; i < size; i++){
    cin >> arr[i];
}

cout << "Array elements and their memory address:" << endl;
for (int i = 0; i < size; i++){
    cout << "arr[" << i << "] = " << arr[i] << "(Address: " << &arr[i] << ")" << endl;
}

delete[] arr;
    return 0;
}