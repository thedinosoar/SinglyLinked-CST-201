//Code written by Keegan McGonigle

#pragma once
#include <iostream>


using namespace std;

template <class T>
class SinglyLinked
{

protected:
	//instance of node class
	class Node {
	public:
		T data;
		Node* next;

		Node(T val) {
			this->data = val;
			this->next = nullptr;
		}

		Node(T val, Node* nextNode) {
			this->data = val;
			this->next = nextNode;
		}

		Node copy() {
			return new Node(data, next);
		}

		//returns the data in the node
		T value() {
			return data;
		}

		void setNext(Node nextNode) {
			next = nextNode;
		}
	};
 
	Node * start;
	Node* tail;
	int listSize;
	bool lowToHigh = true;

private:
	Node *frontNode() {
		return start;
	}
	Node backNode() {
		Node curr = start;
		while (curr.nextNode() != nullptr) {
			curr = curr.nextNode();
		}
		return curr;
	}

public:

	//default constructor
	SinglyLinked<T>() {
		start = nullptr;
		tail = nullptr;
		listSize = 0;
	}

	//copy constructor
	SinglyLinked<T>(const SinglyLinked<T> &copy) {
		start = new Node(copy.start->data);
		listSize = copy.listSize;

		Node *curr = start;
		Node* copyCurr = copy.start;
		while (copyCurr->next != nullptr) {
			//inset(curr->value());
			curr->next = new Node(copyCurr->next->data);
			curr = curr->next;
			copyCurr = copyCurr->next;
			tail = curr;
		}
	}

	//returns the last object in list
	T front() {
		return start->value();
	}

	//returns the last object in list
	T back() {
		Node *curr = start;
		T item;
		while (curr != nullptr) {
			item = curr->value();
			curr = curr->next;
		}
		return item;
	}

	//adds a node to the end
	void add(T value) {
		Node* newNode = new Node(value);
		newNode->next = start;
		start = newNode;
		listSize++;
	}

	SinglyLinked<T> reverse() {
		SinglyLinked<T> output;
		Node* curr = start;
		while (curr != nullptr) {
			output.add(curr->data);
			curr = curr->next;
		}

		return output;
	}

	void merge(SinglyLinked<T> list) {
		Node *curr = list.frontNode();
		while (curr->next != nullptr) {
			insert(curr->data);
			curr = curr->next;
		}
	}

	//insets a value where it is in orxer
	void insert(T val) {
		listSize++;
		if (start == nullptr) {
			start = new Node(val);
			tail = start;
			return;
		}

		Node* nn = new Node(val);
		if (val < start->data) {
			nn->next = start;
			start = nn;
			tail = start->next;
			return;
		}
		
		Node* curr = start;
		while (curr->next != nullptr) {
			if (val < curr->next->data) {
				nn->next = curr->next;
				curr->next = nn;
				return;
			}
			curr = curr->next;
		}
		tail = nn;
		curr->next = nn;
	}

	//deletes the first node
	void popFront() {
		if (start != nullptr) {
			Node* oldStart = start;
			start = start->next;
			delete oldStart;
		}
	}

	//deletes the last node
	void popBack() {
		if (start != nullptr) {
			Node* curr = start;
			while (curr->next->next != nullptr) {
				curr = curr->next;
			}
			delete curr->next;
			curr->next = nullptr;
		}
		
	}

	//checks if the list is empty
	bool empty() {
		return start == nullptr;
	}
	
	//returns the list size
	int size() {
		return listSize;
	}

	friend ostream& operator<<(ostream& out, const SinglyLinked& list) {
		Node* curr = list.start;
		while (curr != nullptr) {
			out << curr->data << " ";
			curr = curr->next;
		}
		return out;
	}
};

