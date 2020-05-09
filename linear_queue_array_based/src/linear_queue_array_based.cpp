//============================================================================
// Name        : linear_queue_array_based.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-quyle
//============================================================================

#include <iostream>
using namespace std;

class Queue {
	int *arr;
	int size;
	int rear;
	int front;
public:
	Queue() {
		arr = NULL;
		size = 0;
		rear = front = -1;
	}

	Queue(int *arr, int size) {
		this->arr = arr;
		this->size = size;
		rear = front = -1;
	}


	bool isFull() {
		if(rear == size-1)
			return true;
		return false;
	}

	bool isEmpty() {
		if(front == rear)
			return true;
		return false;
	}

	void enQueue(int data) {
		if(isFull())
			cout<<"Queue is overflow!"<<endl;
		else {
			arr[++rear] = data;
			cout<<"Element inserted successfully!"<<endl;
		}
	}


	void deQueue() {
		if(isEmpty())
			cout<<"Queue is underflow!"<<endl;
		else {
			arr[++front] = -1;
			cout<<"Element deleted successfully!"<<endl;
			if(front == rear)
				front = rear = -1;
		}
	}


	int peek() {
		if(isEmpty())
			return -1;
		else
			return arr[front+1];
	}

	void printQueue() {
		if(isEmpty())
			cout<<"Queue is underflow!"<<endl;
		else {
			for(int i=front+1; i<=rear; i++) {
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
	}


	int countElements() {
		int cnt;
		if(isEmpty())
			return 0;
		else {
			for(int i=front+1; i<=rear; i++) {
				cnt++;
			}
			return cnt;
		}
	}
};


int menuList() {
	int choice;
	cout<<"0. Exit"<<endl;
	cout<<"1. Print Queue"<<endl;
	cout<<"2. enQueue"<<endl;
	cout<<"3. deQueue"<<endl;
	cout<<"4. Number of elements"<<endl;
	cout<<"5. Peek"<<endl;
	cout<<"Enter choice : ";
	cin>>choice;
	return choice;
}

int main() {
	int choice, ele;
	int arr[5];
	Queue qu(arr, 5);
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
		case 4:
			cout<<"Size of queue is : "<<qu.countElements()<<endl;
			break;
		case 5:
			ele = qu.peek();
			cout<<"Peek element is : "<<ele<<endl;
			break;
		default:
			cout<<"Invalid choice!"<<endl;
		}
	}

	return 0;
}

