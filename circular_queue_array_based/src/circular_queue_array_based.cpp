//============================================================================
// Name        : circular_queue_array_based.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Queue {
	int *arr;
	int rear;
	int front;
	int size;
public:

	Queue() {
		arr = NULL;
		rear = front = -1;
		size = 0;
	}

	Queue(int *arr, int size) {
		this->arr = arr;
		this->size = size;
		rear = front = -1;

		for(int i=0; i<size; i++)
			arr[i] = -1;
	}

	bool isFull() {
		if((rear == size - 1 && front == -1) || (rear == front && rear != -1))
			return true;
		return false;
	}


	bool isEmpty() {
		if(rear == -1 && front == -1)
			return true;
		return false;
	}

	void enQueue(int data) {
		if(rear == size-1)
			rear = 0;
		else
			rear++;
		arr[rear] = data;
	}

	void deQueue() {
		if(front == size-1)
			front = 0;
		else
			front++;
		arr[front] = -1;

		if(front == rear)
			front = rear = -1;
	}


	int peek() {
		if(front == size-1)
			return arr[0];
		else
			return arr[front+1];
	}

	void printQueue() {
		if(rear>front) {
			for(int i = front+1; i<=rear; i++)
				cout<<arr[i]<<" ";
			cout<<endl;
		}
	}

};

int main() {
	int choice, ele;
	int arr[5];
	int size = sizeof(arr)/sizeof(int);
	Queue qu(arr, size);
	do {
		cout<<"0. Exit"<<endl;
		cout<<"1. Print Queue"<<endl;
		cout<<"2. Push in Queue"<<endl;
		cout<<"3. Pop from Queue"<<endl;
		cout<<"Enter your choice :";
		cin>>choice;
		switch(choice) {

		case 0:
			break;

		case 1:
			if(qu.isEmpty())
				cout<<"Queue is empty!"<<endl;
			else {
				cout<<"Queue elements is :"<<endl;
				qu.printQueue();
			}
			break;

		case 2:
			if(qu.isFull())
				cout<<"Queue is full!"<<endl;
			else {
				cout<<"Enter element :";
				cin>>ele;
				qu.enQueue(ele);
				cout<<"Element pushed successfully!"<<endl;
			}
			break;

		case 3:
			if(qu.isEmpty())
				cout<<"Queue is empty!"<<endl;
			else {
				ele = qu.peek();
				qu.deQueue();
				cout<<"Element popped successfully and its value is : "<<ele<<endl;
			}
			break;

		default:
			cout<<"Invalid choice!"<<endl;
		}
	} while(choice  != 0);

	return 0;
}
