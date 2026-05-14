#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
int N;
cin >> N;
string S;
cin >> S;

if (N%2!=0){
    cout << "Pairs unmatched!";
    return 0;
}

cout << "Game start!" << endl;
stack<char> stk;
for (char c: S){
    if (c == '[' || c == '{' || c == '('){
    stk.push(c);
    } else { if (stk.empty())
        cout << "Pairs unmatched!";
        return 0;
    }
    if ((c == ']' && stk.top() == '[') ||
               (c == '}' && stk.top() == '{') ||
               (c == ')' && stk.top() == '('))
    stk.pop();
}

if (stk.empty()){
    cout << "Perfect pairs!";
} else {
    cout << "Pairs unmatched!";
}
return 0;
}