//Program 1
/*
#include<iostream>
using namespace std;
int main() {
int x, no, y, total = 0;
 cout << "How many stars? ";
 cin >> no;
for (x = no; x>=0; x--) {
 total += x;
 for ( y = x; y > 0; y--)
 cout << "*";
 cout << "\n";
 }
 cout << "Wow " << total << " stars in all!!!";
return 0;
}
*/

//Program 2
/*
#include<iostream>
using namespace std;

void printDivisibleby(int initial, int terminal){
cout << "Numbers in the range divisible by 5:\n";
    do  
    {
        if (initial%5 == 0)
        {
            cout << initial << " ";
        }
    initial++;
    } while (initial <= terminal);
}

int main() {
int initial, terminal;
cout << "Enter initial value:";
cin >> initial;
cout << "Enter terminal value:";
cin >> terminal;
if (initial<=terminal)
{ 
 printDivisibleby(initial,terminal);
}

else 
{
    cout << "Invalid entry.";
}

return 0;
} 
*/

//Program 3
/*
#include<iostream>
using namespace std;
int main() {
int x, no;
cout << "Enter number:";
cin >> no;
cout << "Multiplication Table of " << no <<
endl;
 x = 1;
while (x<=10) {
 cout << no << " x " << x << " =" <<no*x<<"\n";
 x++;
 }
return 0;
} 
*/