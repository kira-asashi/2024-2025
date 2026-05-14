#include <iostream>
#include <iomanip> 
using namespace std;

int main()
{
int Number = 10;
char Letter = 'a';
bool Result = true;
float Float = 3.14;

    cout <<left;
    cout <<setw(15)<<"Variable name" <<setw(15) <<"Data Type" <<"Initial value" <<endl;
    cout <<setw(15)<<"Number"        <<setw(15) <<"integer"   << Number         <<endl;
    cout <<setw(15)<<"Letter"        <<setw(15) <<"character" << Letter         <<endl;
    cout <<setw(15)<<"Result"        <<setw(15) <<"boolean"   << Result         <<endl;
    cout <<setw(15)<<"Float"         <<setw(15) <<"float"     << Float          <<endl;

return 0;
}