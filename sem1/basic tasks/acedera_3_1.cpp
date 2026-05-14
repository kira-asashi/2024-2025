#include <iostream>
#include <iomanip>  //for setw and align left
using namespace std;

int main()
{
cout<<left; //align left
cout<<setw(15)  <<"Day"       <<setw(15)  <<"Time"          <<setw(15)    <<"Course Code"  <<setw(15)   <<"Section"  <<"Room"   <<endl; 
cout<<setw(15)  <<"Friday"    <<setw(15)  <<"10:00-12:40"   <<setw(15)    <<"CCS0001"      <<setw(15)   <<"TB01"     <<"ONLINE" <<endl;
cout<<setw(15)  <<"Monday"    <<setw(15)  <<"10:00-12:50"   <<setw(15)    <<"CCS0001L"     <<setw(15)   <<"TB01"     <<"F1203"  <<endl;
cout<<setw(15)  <<"Tuesday"   <<setw(15)  <<"10:00-12:40"   <<setw(15)    <<"CCS0003"      <<setw(15)   <<"TB01"     <<"ONLINE" <<endl;
cout<<setw(15)  <<"Thursday"  <<setw(15)  <<"10:00-12:50"   <<setw(15)    <<"CCS0003L"     <<setw(15)   <<"TB01"     <<"F1203"  <<endl;
cout<<setw(15)  <<"M / TH"    <<setw(15)  <<"13:00-14:50"   <<setw(15)    <<"CS0001"       <<setw(15)   <<"TN28"     <<"F609"   <<endl;
cout<<setw(15)  <<"M / TH"    <<setw(15)  <<"07:00-08:50"   <<setw(15)    <<"GED0009"      <<setw(15)   <<"TB01"     <<"F611"   <<endl;
cout<<setw(15)  <<"F / T"     <<setw(15)  <<"13:00-14:50"   <<setw(15)    <<"GED0011"      <<setw(15)   <<"TB01"     <<"ONLINE" <<endl;



return 0;
} 


