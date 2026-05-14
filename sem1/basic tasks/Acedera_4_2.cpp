#include <iostream>
#include <iomanip>
#include <string>
#
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::string;

int main()
{
    string payrollPeriod, employeeName;
    double monthlySalary,monthlyLate;
    int employeeID;

    cout<<"Enter Payroll period(date): ";
    getline(cin,payrollPeriod);
    cout<<"Enter Employee ID: ";
    cin>>employeeID;
    cout<<"Enter Employee Name: ";
    cin.ignore();
    getline(cin,employeeName);
    cout<<"Enter monthly salary: ";
    cin>>monthlySalary;
    cout<<"Enter lates and absences(in minutes): ";
    cin>>monthlyLate;

    double lateFee, totalDeduction, totalEarnings, netPay, tax, hourlyRate;
    const int Philhealth = 1000, PagIbig = 800, SSS = 1200;
    hourlyRate = (monthlySalary/30)/8; 
    lateFee = (monthlyLate/60)*hourlyRate;
    tax = monthlySalary * .12;
    totalEarnings = monthlySalary;
    totalDeduction = lateFee + Philhealth + PagIbig + SSS + tax;
    netPay = totalEarnings - totalDeduction;

    cout.setf(std::ios::fixed);    
    cout<<setw(60)<<"FEU - Institue of Technology"<<endl;
    cout<<std::left;
    cout<<"Employee ID: "<<setw(40)<<employeeID             <<"Payroll Period: "<<payrollPeriod<<"\n";
    cout<<"Employee Name: "<<employeeName<<endl;
    cout<<setw(54)<<"\nINCOME"                              <<"DEDUCTIONS"<<endl;
    cout<<std::fixed<<std::setprecision(2);
    cout<<"Monthly Salary Php"<<monthlySalary;       
    cout<<std::right;
                                                        cout<<setw(47)<<"Lates and absences\t("<<lateFee<<")"<<endl;
                                                        cout<<setw(65)<<"Philhealth\t("<<Philhealth<<")"<<endl;
                                                        cout<<setw(63)<<"Pag-ibig\t("<<PagIbig<<")"<<endl;
                                                        cout<<setw(58)<<"SSS\t("<<SSS<<")"<<endl;
                                                        cout<<setw(70)<<"Withholding tax\t("<<tax<<")"<<endl;
                                                            
    cout<<"Total Earnings: Php"<<totalEarnings<<endl;
    cout<<"Total Deductions: Php"<<totalDeduction<<endl;
    cout<<"Net Pay: "<<netPay<<endl;
    return 0;
}