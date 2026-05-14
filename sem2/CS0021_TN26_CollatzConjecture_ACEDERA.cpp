#include <iostream>
using namespace std;

int main(){
    int userInput, n = 0;
    cout << "Enter a positive integer: ";
    cin >> userInput;
    cout << userInput << " ";
    
    do{
        if (userInput % 2 == 0){
            userInput = userInput / 2;
            cout << userInput << " ";
        }
        else{
            userInput = 3 * userInput + 1;
            cout << userInput << " ";
        }
    n++;
    }while (userInput != 1);
    cout << "\nNumber of steps: " << n << endl;
    return 0;
}