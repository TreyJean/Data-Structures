// Linked List (Singly Linked)

#include<iostream>
using namespace std;

// Each "link" in the linked list is represented by a node. The node contains 
// an integer value and a pointer to the next node.
typedef struct Node {
	int data;
	Node* next;
} Node;

// The LinkedList object contains a pointer to the beggining of the list (head)
// and the end of the list (tail). 
class LinkedList {
private:
	Node* head;
	Node* tail;

public:
	LinkedList() {
		head = NULL;
		tail = NULL;
	}

	// Appends a new node to the list which contains the integer d.
	void append(int d) {
		Node *temp = new Node;
		temp -> data = d;
		temp -> next = NULL;

		if(head == NULL) {
			head = temp; 
			tail = temp;
		} else {
			tail -> next = temp;
			tail = tail -> next;
		}
	}

	// Iterates through the list until a node containing the value d
	// is found, or until the end of the list is reached
	void deleteValue(int d) {
		Node* temp = head;
		bool deleted = false;

		while(not deleted) {
			deleted = temp == NULL;
			if(temp -> next -> data == d) {
				temp -> next = temp -> next -> next;
				deleted = true;
			} else {
				temp = temp -> next;
			}
		}
	}

	// Displayes the contents of the list
	void display() {
		Node* temp = head;

		if(temp == NULL) {
			cout << "List is Empty." << endl;
		} else {
			cout << "h";

			while(temp != NULL) {
				cout << " -> " << temp -> data;
				temp = temp -> next;
			}

			cout << " <- t" << endl;
		}
	}
};


int main() {
  LinkedList list; // Declare a new LinkedList object.

	// List contains the values 0 through 14
	for(int i = 0; i < 15; i++) {
		list.append(i);
	}

	list.display();

	// Delete the values 5, 6, and 10
	list.deleteValue(5);
	list.deleteValue(6);
	list.deleteValue(10);

	list.display();

	return 0;
}

