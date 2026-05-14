#include <iostream>
#include <cmath>
using namespace std;


int addition (int a, int b){
    return a+b;
}

int subtraction (int a, int b){
    return a-b;
}

int multiplication (int a, int b){
    return a*b;
}

int division (int a, int b){
    return a/b;
}

int modulo (int a, int b){
    return a%b;
}

int power (int a, int b){
    return pow(a,b);
}

int menu (){
    int choice;
    do {
        cout << "CALCULATOR" << endl;
        cout << "********************" << endl;
        cout << "[1] - Addition " << endl;
        cout << "[2] - Subtraction " << endl;
        cout << "[3] - Multiplication " << endl;
        cout << "[4] - Division " << endl;
        cout << "[5] - Modulo " << endl;
        cout << "[6] - Power " << endl;
        cout << "[7] - Exit " << endl;
        cout << "********************" << endl;
        cin >> choice;
        if (choice !=1 && choice !=2 && choice !=3 && choice !=4 && choice !=5 && choice !=6 && choice !=7)
        cout << "ERROR!!! Invalid Input" << endl;
        else 
        return choice;
    } while(true);
    
}

int main(){
int num1,num2;
while (true) {
        int pick = menu();
        if (pick == 7) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }
//int pick = menu();

    cout << "Enter first integer: ";
    cin >> num1;
    cout << "Enter second integer: ";
    cin >> num2;

switch (pick){
case 1:
    cout << "--------------------" << endl;
    cout << "ADDITION:" << num1 << " + " << num2 << " = " << addition(num1,num2) << endl;
    cout << "--------------------" << endl;
    break;
case 2:
    cout << "--------------------" << endl;
    cout << "SUBTRACTION:" << num1 << " - " << num2 << " = " << subtraction(num1,num2) << endl;
    cout << "--------------------" << endl;
    break;
case 3:
    cout << "--------------------" << endl;
    cout << "MULTIPLICATION:" << num1 << " * " << num2 << " = " << multiplication(num1,num2) << endl;
    cout << "--------------------" << endl;
    break;
case 4:
    cout << "--------------------" << endl;
    cout << "DIVISION:" << num1 << " /" << num2 << " = " << division(num1,num2) << endl;
    cout << "--------------------" << endl;
    break;
case 5:
    cout << "--------------------" << endl;
    cout << "MODULO:" << num1 << " % " << num2 << " = " << modulo(num1,num2) << endl;
    cout << "--------------------" << endl;
    break;
case 6:
    cout << "--------------------" << endl;
    cout << "POWER:" << num1 << " raise to " << num2 << " = " << power(num1,num2) << endl;
    cout << "--------------------" << endl;
    break;}
}

return 0; }