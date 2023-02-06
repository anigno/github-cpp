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
		cout << this << " " << value << " " << next << "\n";
	}
};

class LinkedListQueueStack
{
public:
	ListNode* first = NULL;
	ListNode* last = first;

	void enqueue(int value)
	{
		//add node to end
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
		//add node to begining
		ListNode* node = new ListNode(value);
		node->next = first;
		first = node;
	}

	int dequeue() {
		//take node from begining
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
