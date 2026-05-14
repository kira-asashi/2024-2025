#include<iostream>
using namespace std;

double getSum(double a, double b)
{
    return a + b;
}

double getDifference(double a, double b)
{
    return a - b;
}  

double getProduct(double a, double b)
{
    return a * b;
}

double getQuotient(double a, double b)
{
    return a / b;
}  

int getModulus(int a, int b)
{
    return a%b;
}

int main(){
int choice;
double a, b;
int x, y;
do{
cout << "====================" << endl;
cout << "MENU" << endl;
cout << "====================" << endl;
cout << "[1] - Add" << endl;
cout << "[2] - Subtract" << endl;
cout << "[3] - Multiply" << endl;
cout << "[4] - Divide" << endl;
cout << "[5] - Modulus" << endl;
cout << "[6] - Exit" << endl;
cout << "====================" << endl;
cout << "Enter your choice: ";
cin >> choice;

switch(choice)
{
    case 1:
        cout << "Enter two numbers: ";
        cin >> a >> b;
        cout << "The sum is " << getSum(a, b) << endl;
        break;
    case 2:
        cout << "Enter two numbers: ";
        cin >> a >> b;
        cout << "The difference is " << getDifference(a, b) << endl;
        break;
    case 3:   
        cout << "Enter two numbers: ";
        cin >> a >> b;
        cout << "The product is " << getProduct(a, b) << endl;
        break;
    case 4:
        cout << "Enter two numbers: ";
        cin >> a >> b;
        cout << "The quotient is " << getQuotient(a, b) << endl;
        break;
    case 5:
        cout << "Enter two integers: ";
        cin >> x >> y;
        cout << "The modulus is " << getModulus(x, y) << endl;
        break;
    case 6:
        cout << "Exiting program..." << endl;
        return 0;
        break;
    default:
        cout << "Error! Invalid input." << endl;
        break;
}
}while(true);

return 0;
}