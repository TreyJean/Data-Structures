// Queue

#include<iostream>
using namespace std;

#define MAX 5000

// The Queue object contains a hidden array and two integer pointers
// to the front and end of the queue.
class Queue {
private:
	int front, end; // Pointers to the front and end of the queue
	int size; // Used to wrap the queue if needed
	int array[MAX];

public:
	Queue() { size = 0; front = 0; end = front + size; }

	void enqueue(int n) { // Pushes a value onto the end of the queue
		if(this -> isFull()) {
			throw "Queue is Full!";
		} else {
			size++;
			array[end] = n;
			end = (end + 1) % MAX;
		}
	}

	int dequeue() { // Pops a value off the front of the queue
		if(this -> isEmpty()) {	
			throw "Queue is empty!";
		} else {
			int temp = array[front];
			front = (front + 1) % MAX;
			size--;

			return temp;
		}
	}

	bool isFull() {
		return size == MAX;
	}

	bool isEmpty() {
		return size == 0;
	}

	void display() {
		int i = front;
		while(i != end) {
			cout << array[i % MAX] << " | "; i = (i + 1) % MAX;
		}

		cout << endl;
	}
};


int main() {
	Queue queue; 

	for(int i = 0; i < 15; i++) {
		queue.enqueue(i);
	}
	queue.display();

	for(int i = 0; i < 5; i++) {
		cout << "Dequeued: " << queue.dequeue() << endl;
	}
	queue.display();
	return 0;
}

