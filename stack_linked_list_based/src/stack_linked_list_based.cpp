//============================================================================
// Name        : stack_linked_list_based.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class LinkedList;

class Node {
	int data;
	Node *next;
public:
	Node() {
		data = 0;
		next = NULL;
	}

	Node(int data) {
		this->data = data;
		next = NULL;
	}

	friend class LinkedList;
};


class LinkedList {
	Node *head;
	int size;
public:
	LinkedList() {
		head = NULL;
		size = 0;
	}

	void push(int data) {
		if(head == NULL) {
			head = new Node(data);
			size++;
		}
		else {
			Node *temp = new Node(data);
			temp->next = head;
			head = temp;
			size++;
		}
	}


	void printStack() {
		if(head == NULL) {
			cout<<"Stack is underflow!"<<endl;
			return;
		}
		cout<<"Element of stack is : "<<endl;
		Node *trav = head;
		while(trav!=NULL) {
			cout<<trav->data<<endl;
			trav = trav->next;
		}
	}



	void pop() {
		if(head == NULL) {
			cout<<"Stack is already empty!"<<endl;
		}
		else {
			Node *temp = head;
			head = head->next;
			size--;
			delete temp;
		}
	}


};

int menuList() {
	int choice;
	cout<<"0. Exit"<<endl;
	cout<<"1. Print Stack"<<endl;
	cout<<"2. Push"<<endl;
	cout<<"3. Pop"<<endl;
	cout<<"Enter choice : ";
	cin>>choice;
	return choice;
}

int main() {
	int choice, ele, pos;
	LinkedList li;
	while((choice=menuList()) != 0) {
		switch(choice) {
		case 0:
			break;
		case 1:
			li.printStack();
			break;
		case 2:
			cout<<"Enter element : ";
			cin>>ele;
			li.push(ele);
			break;
		case 3:
			li.pop();
			break;
		default:
			cout<<"Invalid choice!"<<endl;
		}
	}

	return 0;
}
