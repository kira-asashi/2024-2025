#include <iostream>
#include <cmath>
using namespace std;

double area_square(double a){
    return pow(a,2);
}

double area_rectangle(double a, double b){
    return a*b;
}
double area_triangle(double a, double b){
    return (a*b/2);
}
double area_circle(double a){
    return(M_PI*a*a);
}

int main(){
int choice;
do {
    cout << "********************" << endl;
    cout << "MENU" << endl;
    cout << "********************" << endl;
    cout << "[1] - Area of square" <<endl;
    cout << "[2] - Area of rectangle" <<endl;
    cout << "[3] - Area of triangle" <<endl;
    cout << "[4] - Area of circle" <<endl;
    cout << "[5] - Exit" <<endl;
    cout << "--------------------" <<endl; 
    cout << "Enter your choice: ";
    cin >>choice;
    cout << "--------------------" <<endl; 

switch (choice)
{
double a,b,r; 
case 1:
    cout << "AREA OF SQUARE\n--------------------" <<endl;
    cout << "Enter side of the square: ";
    cin >> a;
    cout << "The area is " << area_square(a) << " sq. units" <<endl;
    break;
case 2:
    cout << "AREA OF RECTANGLE\n---------------------" <<endl;
    cout << "Enter the length and width of the rectangle: ";
    cin >> a >> b;
    cout << "The area is " << area_rectangle(a,b) << " sq.units" <<endl;
    break;
case 3:
    cout << "AREA OF TRIANGLE\n--------------------" <<endl;
    cout << "Enter the base and height of the triangle: ";
    cin >> a >> b;
    cout << "The area is " << area_triangle(a,b) << " sq.units" <<endl;
    break;
case 4:
    cout << "AREA OF CIRCLE\n--------------------" <<endl;
    cout << "Enter the radius of the circle: ";
    cin >> r;
    cout << "The area is " << area_circle(r) << "sq.units" <<endl;
    break;
case 5:
cout << "Exiting program";
break;
default:
cout << "ERROR!!Invalid Input..." <<endl;
break;
}
if (choice==5)
break;;
} while(true);
return 0;
}