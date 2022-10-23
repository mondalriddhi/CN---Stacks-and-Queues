/*   Implement a Queue Data Structure specifically to store integer data using a Singly Linked List.
The data members should be private.
You need to implement the following public functions :
1. Constructor:
It initialises the data members as required.
2. enqueue(data) :
This function should take one argument of type integer. It enqueues the element into the queue and returns nothing.
3. dequeue() :
It dequeues/removes the element from the front of the queue and in turn, returns the element being dequeued or removed. In case the queue is empty, it returns -1.
4. front() :
It returns the element being kept at the front of the queue. In case the queue is empty, it returns -1.
5. getSize() :
It returns the size of the queue at any given instance of time.
6. isEmpty() :
It returns a boolean value indicating whether the queue is empty or not.

Sample Input 1:
7
1 17
1 23
1 11
2
2
2
2

Sample Output 1:
17
23
11
-1

*/


#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Queue {
	// Define the data members
    Node *head;
    Node *tail;
    int size;
        
   public:
    Queue() {
		// Implement the Constructor
        head = NULL;
        tail = NULL;
        size = 0;
	}
	
	/*----------------- Public Functions of Stack -----------------*/

	int getSize() {
		// Implement the getSize() function
        return size;
	}

    bool isEmpty() {
		// Implement the isEmpty() function
        return size==0;
    }

    void enqueue(int data) {
		// Implement the enqueue() function
        Node *newNode = new Node(data);
        if(head==NULL) {
            head = newNode;
            tail = newNode;
        }
        tail -> next = newNode;
        tail = tail -> next;
        size++;
	}

    int dequeue() {
        // Implement the dequeue() function
        if(size==0) {
            return -1;
        }
        int store = head -> data;
        Node *delNode = head;
        head = head -> next;
        delete delNode;
        size--;
        return store;
        
    }

    int front() {
        // Implement the front() function
        if(size==0) {
            return -1;
        }
        return head->data;
    }
};

int main() {
    Queue q;

    int t;
    cin >> t;

    while (t--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                q.enqueue(input);
                break;
            case 2:
                cout << q.dequeue() << "\n";
                break;
            case 3:
                cout << q.front() << "\n";
                break;
            case 4:
                cout << q.getSize() << "\n";
                break;
            default:
                cout << ((q.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}
