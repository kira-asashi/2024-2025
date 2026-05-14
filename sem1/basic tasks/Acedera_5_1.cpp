#include <iostream>
using std::cout;
using std::cin;
int main()
{
    float exam1, exam2, exam3, grade;

    cout<<"Input score for first Exam: ";
    cin>>exam1;
    cout<<"Input score for second Exam: ";
    cin>>exam2;
    cout<<"Input score for third Exam: ";
    cin>>exam3;
    grade = (exam1+exam2+exam3)/3;

    if (grade >= 70)
    cout<<"Your average grade is: "<<grade<<" :-)";
    else
    cout<<"Your average grade is: "<<grade<<" :-(";
   
    return 0;
}