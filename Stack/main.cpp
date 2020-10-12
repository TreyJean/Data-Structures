// Stack

#include<iostream>
using namespace std;

#define MAX 5000

// The Stack object contains a hidden array and an integer pointer
// to the top of the stack.
class Stack {
private:
	int ptr; // Points to the top of the stack
	int array[MAX];

public:
	Stack() { ptr = -1; }

	void push(int n) { // Pushes a value onto the stack
		array[++ptr] = n;
	}

	int pop() { // Pops a value off the stack
		return array[ptr--];
	}

	int top() { // Returns the value on the top of the stack
		return array[ptr];
	}

	void display() {
		for(int i = ptr; i >= 0; i--) {
			cout << "> " << array[i] << endl;
		}
	}
};


int main() {
	Stack stack; 

	for(int i = 0; i < 15; i++) {
		stack.push(i);
	}
	stack.display();

	for(int i = 0; i < 5; i++) {
		cout << "Popped: " << stack.pop() << endl;
	}
	stack.display();

	cout << "Top: " << stack.top() << endl;
	return 0;
}

