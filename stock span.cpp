/*  Afzal has been working with an organization called 'Money Traders' for the past few years. 
The organization is into the money trading business. 
His manager assigned him a task. For a given array/list of stock's prices for N days, find the stock's span for each day.
The span of the stock's price today is defined as the maximum number of consecutive days(starting from today and going backwards)
 for which the price of the stock was less than today's price.
For example, if the price of a stock over a period of 7 days are [100, 80, 60, 70, 60, 75, 85], then the stock spans will be [1, 1, 1, 2, 1, 4, 6].

Explanation:
On the sixth day when the price of the stock was 75, the span came out to be 4, because the last 4 prices(including the current price of 75) were less than the current or the sixth day's price.

Similarly, we can deduce the remaining results.

Sample Input 1:
4
10 10 10 10
Sample Output 1:
1 1 1 1 
********************************
Sample Input 2:
8
60 70 80 100 90 75 80 120
Sample Output 2:
1 2 3 4 1 1 2 8 

*/

#include <iostream>
using namespace std;

#include<stack>
int* stockSpan(int *price, int size)  {
	// Write your code here
    stack<int> span;
    int *output = new int[size];
    span.push(0);
    output[0]=1;
    for(int i=1;i<size;i++) {
        while(!span.empty()&&price[span.top()]<price[i]) {
            span.pop();
        }
        if(span.empty()) {
            output[i] = i+1;
        }
        else {
            output[i] = i-span.top();
        }
        span.push(i);
    }
    return output;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}
