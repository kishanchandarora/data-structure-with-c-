//============================================================================
// Name        : stack_array_based.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Stack {
	int *arr;
	int top;
	int size;
public:
	Stack() {
		arr = NULL;
		size = 0;
		top = -1;
	}

	Stack(int *arr, int size) {
		this->arr = arr;
		top = -1;
		this->size = size;
	}

	int countElements() {
		int cnt = 0;
		for(int i=0;i<=top; i++)
			cnt++;
		return cnt;
	}

	void printStack() {
		if(isEmpty()) {
			cout<<"Stack is underflow!"<<endl;
		} else {
			cout<<"Elements of stack : "<<endl;
			for(int i=top;i>=0; i--)
				cout<<arr[i]<<endl;
			cout<<endl;
		}
	}

	bool isFull() {
		if(top == size-1)
			return true;
		return false;
	}

	void push(int data) {
		if(isFull()) {
			cout<<"Stack is overflow!"<<endl;
		} else {
			arr[++top] = data;
			cout<<"Element pushed successfully!"<<endl;
		}
	}


	bool isEmpty() {
		if(top == -1)
			return true;
		return false;
	}

	int pop() {
		if(isEmpty()) {
			cout<<"Stack is underflow!"<<endl;
		} else {
			cout<<"Element popped successfully!"<<endl;
			return arr[top--];
		}
	}

	int peek() {
		if(isEmpty()) {
			cout<<"Stack is underflow!"<<endl;
			return 0;
		} else {
			return arr[top];
		}
	}

};


int menuList() {
	int choice;
	cout<<"0. Exit"<<endl;
	cout<<"1. Print stack"<<endl;
	cout<<"2. Push"<<endl;
	cout<<"3. Pop"<<endl;
	cout<<"4. Number of elements"<<endl;
	cout<<"5. Peek"<<endl;
	cout<<"Enter choice : ";
	cin>>choice;
	return choice;
}

int main() {
	int choice, ele;
	int arr[10];
	Stack st(arr, 10);
	while((choice=menuList()) != 0) {
		switch(choice) {
		case 0:
			break;
		case 1:
			st.printStack();
			break;
		case 2:
			cout<<"Enter element : ";
			cin>>ele;
			st.push(ele);
			break;
		case 3:
			st.pop();
			break;
		case 4:
			cout<<"Size of stack is : "<<st.countElements()<<endl;
			break;
		case 5:
			ele = st.peek();
			cout<<"Peek element is : "<<ele<<endl;
			break;
		default:
			cout<<"Invalid choice!"<<endl;
		}
	}

	return 0;
}

