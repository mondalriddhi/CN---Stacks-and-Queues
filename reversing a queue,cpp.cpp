/*  You have been given a queue that can store integers as the data. 
You are required to write a function that reverses the populated queue itself without using any other data structures.

Sample Input 1:
1
6
1 2 3 4 5 10
Note:
Here, 1 is at the front and 10 is at the rear of the queue.
Sample Output 1:
10 5 4 3 2 1

*/

#include <iostream>
using namespace std;

#include<queue>
void reverseQueue(queue<int> &input) {
	// Write your code here
    if(input.empty()){
        return;
    }
    int temp = input.front();
    input.pop();
    reverseQueue(input);
    input.push(temp);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++) {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}
