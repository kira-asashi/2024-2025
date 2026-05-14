#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double sales, income;

   
    cout << "Enter the monthly sales: ";
    cin >> sales;

    if (sales >= 50000) {
        income = 575 + (0.16 * sales);
    } else if (sales >= 40000) {
        income = 550 + (0.14 * sales);
    } else if (sales >= 30000) {
        income = 525 + (0.12 * sales);
    } else if (sales >= 20000) {
        income = 500 + (0.09 * sales);
    } else if (sales >= 10000) {
        income = 450 + (0.05 * sales);
    } else {
        income = 400 + (0.03 * sales);
    }

    cout << fixed << setprecision(2); 
    cout << "The income based on monthly sales of Php " << sales << " is Php " << income << endl;

    return 0;
}
