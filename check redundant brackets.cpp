/*  For a given expression in the form of a string, find if there exist any redundant brackets or not. 
It is given that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.
A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.
Example:
Expression: (a+b)+c
Since there are no needless brackets, hence, the output must be 'false'.

Expression: ((a+b))
The expression can be reduced to (a+b). Hence the expression has redundant brackets and the output will be 'true'.


Sample Input 1:
a+(b)+c 
Sample Output 1:
true
Explanation:
The expression can be reduced to a+b+c. Hence, the brackets are redundant.

Sample Input 2:
(a+b)
Sample Output 2:
false
*/

#include <iostream>
#include <string>
using namespace std;

#include<stack>

bool checkRedundantBrackets(string expression) {
	// Write your code here
    stack<char> brackets;
    for(int i=0;i<expression.size();i++) {
        if(brackets.empty()) {
            brackets.push(expression[i]);
        }
        
        else if(expression[i]==')'&&brackets.top()=='(') {
            return true;
        }
        else if(expression[i]==')') {
            int count=0;
            while(brackets.top()!='(') {
                count++;
                brackets.pop();
            }
            if(count>1) {
                brackets.pop();
            }
            else {
                return true;
            }
        }
        else {
            brackets.push(expression[i]);
        }
    }
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}
