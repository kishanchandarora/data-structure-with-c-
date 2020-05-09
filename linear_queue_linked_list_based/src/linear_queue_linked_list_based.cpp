//============================================================================
// Name        : linear_queue_linked_list_based.cpp
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


	void enQueue(int data) {
		if(head == NULL) {
			head = new Node(data);
			size++;
		}
		else {
			Node *trav = head, *temp = new Node(data);
			while(trav->next != NULL)
				trav = trav->next;
			trav->next = temp;
			size++;
		}
	}



	void printQueue() {
		if(head == NULL) {
			cout<<"Queue is underflow!"<<endl;
			return;
		}
		cout<<"Element of queue is : "<<endl;
		Node *trav = head;
		while(trav!=NULL) {
			cout<<trav->data<<" ";
			trav = trav->next;
		}
		cout<<endl;
	}



	void deQueue() {
		if(head == NULL) {
			cout<<"Queue is already empty!"<<endl;
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
	cout<<"1. Print Queue"<<endl;
	cout<<"2. enQueue"<<endl;
	cout<<"3. deQueue"<<endl;
	cout<<"Enter choice : ";
	cin>>choice;
	return choice;
}

int main() {
	int choice, ele;
	LinkedList qu;
	while((choice=menuList()) != 0) {
		switch(choice) {
		case 0:
			break;
		case 1:
			cout<<"Queue elements are : "<<endl;
			qu.printQueue();
			break;
		case 2:
			cout<<"Enter element : ";
			cin>>ele;
			qu.enQueue(ele);
			break;
		case 3:
			qu.deQueue();
			break;
		default:
			cout<<"Invalid choice!"<<endl;
		}
	}

	return 0;
}

