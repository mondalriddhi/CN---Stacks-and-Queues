/*  You have been given two stacks that can store integers as the data.
 Out of the two given stacks, one is populated and the other one is empty. 
 You are required to write a function that reverses the populated stack using the one which is empty.
For Example:
Sample Input 1:
6
1 2 3 4 5 10
Note:
Here, 10 is at the top of the stack.
Sample Output 1:
1 2 3 4 5 10



*/

#include <iostream>
#include <stack>
using namespace std;

#include<stack>
void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    
    if(input.empty()) {
        return;
    }
    stack<int> onemore;
    while(!input.empty()) {
        int ele = input.top();
        extra.push(ele);
        input.pop();
    }
    while(!extra.empty()) {
        int ele = extra.top();
        onemore.push(ele);
        extra.pop();
    }
    while(!onemore.empty()) {
        int ele = onemore.top();
        input.push(ele);
        onemore.pop();
    }
}

int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}
