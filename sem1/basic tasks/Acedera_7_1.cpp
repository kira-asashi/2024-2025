#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::string;

double celciusToFahrenheit (double c){ 
    return (c*9/5 + 32);
}

double fahrenheitToCelcius (double f){
    return (f - 32) * 5/9;
}

double celciusToKelvin (double c){
    return  (c+273.15);
}


int displayMenu() {
    int choice;
    do {
        cout << "[1] - Celcius to Fahrenheit\n";
        cout << "[2] - Fahrenheit to Celcius\n";
        cout << "[3] - Celcius to Kelvin\n";
        cout << "\nChoose your option: ";
        cin >> choice;
        if (choice == 1 || choice == 2 || choice == 3) {
            return choice;
        } else {
            cout << "Invalid input. Please enter 1, 2, or 3." << std::endl;
        }
    } while (true);
}

int main(){

string line = "*************************************************************************************************************************";
cout<<line<<std::endl;
cout<<std::setw(70)<<"TEMPERATURE CONVERTER"<<std::endl;
cout<<line<<std::endl;

while(true) {
int menu = displayMenu();

double temp;
switch (menu)
{
case 1:
    cout<<"Enter temperature in Celcius: ";
    cin>>temp;
    cout<<"Temperature in Fahrenheit is: "<<celciusToFahrenheit(temp)<<std::endl;
    break;
case 2:
    cout<<"Enter temperature in Fahrenheit: ";
    cin>>temp;
    cout<<"Temperature in Celcius is: "<<fahrenheitToCelcius(temp)<<std::endl;
    break;
case 3:
    cout<<"Enter temperature in Celcius: ";
    cin>>temp;
    cout<<"Temperature in Kelvin is: "<<celciusToKelvin(temp)<<std::endl;
    break;
}
char continueOption;
cout<<"Do you want to continue[Y/N]? ";
cin>>continueOption;
if (tolower(continueOption)!='y') {
    break;
}
}
return 0;
}