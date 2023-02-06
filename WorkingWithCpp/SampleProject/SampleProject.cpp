// SampleProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedListSample.cpp"
using namespace std;


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
	list.print();
	cout << list.pop();
	cout << list.pop();
	cout << list.pop();
	cout << list.pop();
}

