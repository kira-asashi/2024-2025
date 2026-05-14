#include <iostream>
#include <cmath>

using namespace std;

int main() {
    char figure;
    double volume;

    cout << "Volume of Figures\n";
    cout << "[C] - Cube\n";
    cout << "[R] - Rectangular Prism\n";
    cout << "[S] - Sphere\n";
    cout << "Choose figure: ";
    cin >> figure;
    figure = tolower(figure);

    switch (figure) {
        case 'c': {
            double side;
            cout << "You have chosen Cube.\n";
            cout << "Enter side: ";
            cin >> side;
            volume = pow(side, 3); 
            cout << "The volume of the cube is: " << volume << endl;
            break;
        }
        case 'r': {
            double length, width, height;
            cout << "You have chosen Rectangular Prism.\n";
            cout << "Enter length, width, and height: ";
            cin >> length >> width >> height;
            volume = length * width * height;
            cout << "The volume of the rectangular prism is: " << volume << endl;
            break;
        }
        case 's': {
            double radius;
            cout << "You have chosen Sphere.\n";
            cout << "Enter radius: ";
            cin >> radius;
            volume = (4.0 / 3.0) * M_PI * pow(radius, 3); 
            cout << "The volume of the sphere is: " << volume << endl;
            break;
        }
        default:
            cout << "Invalid choice. Please choose C, R, or S." << endl;
    }

    return 0;
}
