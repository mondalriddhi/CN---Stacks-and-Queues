/*  For a given expression in the form of a string, find the minimum number of brackets that can be reversed 
in order to make the expression balanced. 
The expression will only contain curly brackets.
If the expression can't be balanced, return -1.
Example:
Expression: {{{{
If we reverse the second and the fourth opening brackets, the whole expression will get balanced. 
Since we have to reverse two brackets to make the expression balanced, the expected output will be 2.

Expression: {{{
In this example, even if we reverse the last opening bracket, we would be left with
 the first opening bracket and hence will not be able to make the expression balanced and the output will be -1.

Sample Input 1:
{{{
Sample Output 1:
-1
****************************
Sample Input 2:
{{{{}}
Sample Output 2:
1
*/

#include <iostream>
#include <string>
using namespace std;

#include<stack>
int countBracketReversals(string input) {
	// Write your code here
    int lens = input.length();
    
    if(lens==0) {
        return 0;
    }
    if(lens%2!=0) {
        return -1;
    }
    stack<int> op;
    for(int i=0;i<lens;i++) {
        if(input[i]=='}') {
            if(!op.empty()&&op.top()=='{') {
                op.pop();
            }
            else {
                op.push(input[i]);
            }
        }
        else {
            op.push(input[i]);
        }
    }
    
    int count = 0;
    
    while(!op.empty()) {
        char c1 = op.top();
        op.pop();
        char c2 = op.top();
        op.pop();
        
        if(c1!=c2) {
            count=count+2;
        }
        else {
            count++;
        }
    }
    
    return count;
    
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}


