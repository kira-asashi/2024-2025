#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
int main() {
    char input[100];
    cin>>input;
    int len = strlen(input);
    bool isPalindrome = true;
    for(int i=0;i<len;i++){
    if(tolower(input[i]) != tolower(input[len-i-1])){
        isPalindrome = false;
        break;}
    }
    if (isPalindrome){
        cout << "Sorry";
    }else {
        if (isupper(input[0])){
        input[len-1] = toupper(input[len-1]);
        input[0] = tolower(input[0]);
        }
        for (int j=len-1;j>=0;j--){
            cout << input[j];
        }
    }
    return 0;
}