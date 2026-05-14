#include<iostream>
#include<iomanip>
using namespace std;

int main()
{

double pesos,usd,euro,yuan,koruna,krone,sheqel,dinar;
cout<<left;
cout<<"Enter Philippine peso: ";
cin>>pesos;


    usd = pesos / 43.33089;
    euro = usd * 0.734719;
    yuan = usd * 6.346934;
    koruna = usd * 18.77263;
    krone = usd * 5.449007;
    sheqel = usd * 3.726334;
    dinar = usd * 0.274588;
    
cout<<"\nThe amount's equivalent to:"<<endl;
cout<<fixed<<setprecision(3);
cout<<setw(15)<<"US Dollar is"<<setw(5)<<":"<<usd<<endl;
cout<<fixed<<setprecision(6);
cout<<setw(15)<<"Euro"<<setw(5)<<":"<<euro<<endl;
cout<<setw(15)<<"Yuan"<<setw(5)<<":"<<yuan<<endl;
cout<<setw(15)<<"Koruna"<<setw(5)<<":"<<koruna<<endl;
cout<<setw(15)<<"Krone"<<setw(5)<<":"<<krone<<endl;
cout<<setw(15)<<"Sheqel"<<setw(5)<<":"<<sheqel<<endl;
cout<<setw(15)<<"Dinar"<<setw(5)<<":"<<dinar<<endl;
return 0;
}