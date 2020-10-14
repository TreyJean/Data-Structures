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
	int size;

public:
	Stack() { ptr = -1; size = 0; }

	void push(int n) { // Pushes a value onto the stack
		if(this -> isFull()) {
			throw "Stack is Full!";
		} else {
			array[++ptr] = n;
			size++;
		}
	}

	int pop() { // Pops a value off the stack
		if(this -> isEmpty()) {
			throw "Stack is Empty";
		} else {
			return array[ptr--];
			size--;
		}
	}

	int top() { // Returns the value on the top of the stack
		if(this -> isEmpty()) {
			throw "Stack is Empty";
		} else {
			return array[ptr];
		}
	}

	int height() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	bool isFull() {
		return size == MAX;
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

