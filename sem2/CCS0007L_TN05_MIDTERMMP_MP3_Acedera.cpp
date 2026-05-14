#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void toLowercase(char str[]){
for (int i = 0; i < strlen(str); i++)
    str[i] = tolower(str[i]);
}

void removeWhitespace(char str[]){
int j = 0;
for (int i = 0; i < strlen(str); i++){
    if (!isspace(str[i])){
    str[j++] = str[i];
    }
}
}

bool isPalindrome(char str[]){
int start = 0;
int end = strlen(str) - 1;
while (end > start){
    if (str[start++] != str[end--])
    return false;
}
return true;
}

int main(){
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);
    toLowercase(str);
    removeWhitespace(str);
    if(isPalindrome(str)){
        cout << "The string is a palindrome." << endl;
    }else{
        cout << "The string is not a palindrome." << endl;
    }
    return 0;
}