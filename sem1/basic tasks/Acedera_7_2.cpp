#include <iostream>
#include <cmath>
#include <iomanip>
using std::cin;
using std::cout;
using std::string;

string line = "*************************************************************************************************************************";

double cubeVolume (double c){ 
    return pow(c,3);
}

double sphereVolume (double s){
    return M_PI*4/3*pow(s,3);
}

double pipedVolume (double w, double h, double l){
    return  w*h*l;
}


char displayMenu() {
    char choice;
    do {
        cout<<line<<std::endl;
        cout<<std::setw(70)<<"Volume of Shapes"<<std::endl;
        cout<<line<<std::endl;
        cout <<std::setw(65)<< "[C] - Cube\n";
        cout <<std::setw(67)<< "[S] - Sphere\n";
        cout <<std::setw(85)<< "[R] - Rectangular Parallepiped\n";
        cout <<std::setw(65)<< "[X] - EXIT\n";
        cout <<line;
        cout << "\nChoose your option: ";
        cin >> choice;
        choice = tolower(choice);
        if (choice == 'c' || choice == 's' || choice == 'r' || choice == 'x') {
            return choice;
        } else {
            cout << "Invalid input. Please enter C, S, R, or X." << std::endl;
        }
    } while (true);
}

int main(){

char menu;
while (menu != 'x'){
menu = displayMenu();
cout <<std::fixed<<std::setprecision(2);
switch (menu){
case 'c':
    double side;
    cout<<"You choose to solve the volume of the Cube!"<<std::endl;
    cout<<"Enter side: ";
    cin>>side;
    cout<<"Volume of cube is: "<<cubeVolume(side)<<std::endl;
    break;
case 's':
    double radius;
    cout<<"You choose to solve the volume of the Sphere!"<<std::endl;
    cout<<"Enter radius: ";
    cin>>radius;
    cout<<"Volume of sphere is: "<<sphereVolume(radius)<<std::endl;
    break;
case 'r':
    double l,w,h;
    cout<<"You choose to solve the volume of the Rectangular Parallelepiped!"<<std::endl;
    cout<<"Enter length: ";
    cin>>l;
    cout<<"Enter width: ";
    cin>>w;
    cout<<"Enter height: ";
    cin>>h;
    cout<<"Volume of Rectangular Parallelepiped is: "<<pipedVolume(l,w,h)<<std::endl;
    break;
case 'x':
    cout<<"Exiting program..."<<std::endl;
    break;
}
}
return 0;
}