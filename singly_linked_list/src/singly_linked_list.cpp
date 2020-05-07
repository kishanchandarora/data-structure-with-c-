//============================================================================
// Name        : singly_linked_list.cpp
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

	void addFirst(int data) {
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

	void addLast(int data) {
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

	void printList() {
		if(head == NULL) {
			cout<<"list is empty!"<<endl;
			return;
		}
		cout<<"Element of list is : "<<endl;
		Node *trav = head;
		while(trav!=NULL) {
			cout<<trav->data<<" -> ";
			trav = trav->next;
		}
		cout<<"NULL"<<endl;
	}

	void addPosition(int data, int pos) {
		if(pos<1 || pos>size+1){
			cout<<"Invalid position!"<<endl;
			return;
		}
		if(pos == 1)
			addFirst(data);
		else {
			Node *trav = head;
			int i = 1;
			while(i<pos-1) {
				trav= trav->next;
				i++;
			}
			if(trav->next == NULL || head->next == NULL) {
				addLast(data);
			}
			else {
				Node *temp = new Node(data);
				temp->next = trav->next;
				trav->next = temp;
				size++;
			}
		}

	}

	void delFirst() {
		if(head == NULL) {
			cout<<"List is already empty!"<<endl;
		}
		else {
			Node *temp = head;
			head = head->next;
			size--;
			delete temp;
		}
	}

	void delLast() {
		if(head == NULL)
			cout<<"List is already empty!"<<endl;
		else {
			if(head->next == NULL){
				head = head->next;
				size--;
				return;
			}
			Node *trav = head;
			while(trav->next->next != NULL)
				trav = trav->next;
			Node *temp = trav->next;
			trav->next = NULL;
			size--;
			delete temp;
		}
	}


	void delPosition(int pos) {
		if(head == NULL) {
			cout<<"List is already empty!"<<endl;
			return;
		}
		if(pos<1 || pos>size){
			cout<<"Invalid position!"<<endl;
			return;
		}
		if(pos == 1)
			delFirst();
		else if(pos == size)
			delLast();
		else {
			Node *trav = head;
			int i=1;
			while(i<pos-1) {
				trav = trav->next;
				i++;
			}
			Node *temp = trav->next;
			trav->next = trav->next->next;
			size--;
			delete temp;
		}
	}

};

int menuList() {
	int choice;
	cout<<"0. Exit"<<endl;
	cout<<"1. Print List"<<endl;
	cout<<"2. Add First"<<endl;
	cout<<"3. Add Last"<<endl;
	cout<<"4. Add Position"<<endl;
	cout<<"5. Delete First"<<endl;
	cout<<"6. Delete Last"<<endl;
	cout<<"7. Delete Position"<<endl;
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
			li.printList();
			break;
		case 2:
			cout<<"Enter element : ";
			cin>>ele;
			li.addFirst(ele);
			break;
		case 3:
			cout<<"Enter element : ";
			cin>>ele;
			li.addLast(ele);
			break;
		case 4:
			cout<<"Enter element : ";
			cin>>ele;
			cout<<"Enter position : ";
			cin>>pos;
			li.addPosition(ele, pos);
			break;
		case 5:
			li.delFirst();
			break;
		case 6:
			li.delLast();
			break;
		case 7:
			cout<<"Enter position : ";
			cin>>pos;
			li.delPosition(pos);
			break;
		default:
			cout<<"Invalid choice!"<<endl;
		}
	}

	return 0;
}
