// SampleProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class ListNode
{
public:
	int value;
	ListNode* next = NULL;

	ListNode(int value) {
		this->value = value;
	}

	void print()
	{
		cout << value << " " << next << "\n";
	}
};

class LinkedListQueueStack
{
public:
	ListNode* first = NULL;
	ListNode* last = first;

	void enqueue(int value)
	{
		ListNode* node = new ListNode(value);
		if (first == NULL) {
			first = node;
			last = first;
		}
		else
		{
			last->next = node;
			last = node;
		}
	}

	void push(int value) {
		ListNode* node = new ListNode(value);
		node->next = first;
		first = node;
	}

	int dequeue() {
		if (first == NULL)return NULL;
		ListNode* ret = first;
		first = first->next;
		return ret->value;
	}

	int pop() {
		return dequeue();
	}

	void print() {
		if (first == NULL)return;
		for (ListNode* node = first; node != NULL; node = node->next) {
			node->print();
		}
	}
};

int main()
{
	/*std::cout << "Hello World!\n";
	cout << "Hello\n";
	ListNode root = ListNode(5);
	root.value = 5;
	root.next = NULL;
	root.print();*/
	LinkedListQueueStack list = LinkedListQueueStack();
	list.enqueue(5);
	list.enqueue(6);
	list.enqueue(7);
	list.print();
	cout << list.dequeue();
	cout << list.dequeue();
	cout << list.dequeue();
	cout << list.dequeue();
	cout << "\n";
	list.push(5);
	list.push(6);
	list.push(7);
	cout << list.pop();
	cout << list.pop();
	cout << list.pop();
	cout << list.pop();
}

