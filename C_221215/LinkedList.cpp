#include "LinkedList.h"
#include "Node.h"
#include <iostream>
using namespace std;

void LinkedList::PushBack(int data)
{
	if (Empty()) {
		tail = head = new Node(data);
	}
	else {
		tail->next = new Node(data);
		tail = tail->next;
	}
	size++;
}

void LinkedList::PushFront(int data)
{
	if (Empty()) {
		tail = head = new Node(data);
	}
	else {
		Node* in = new Node(data);
		in->next = head;
		head = in;
	}
	size++;
}

void LinkedList::PopBack()
{
	if (Empty())
		return;

	if (head == tail) {
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node* node = head;
		while (node->next != tail) { 
			node = node->next; 
		}	//tail 바로 앞의 노드를 찾는다
		delete tail;
		tail = node;
		tail->next = nullptr;
	}
	size--;
}

void LinkedList::PopFront()
{
	if (Empty())
		return;

	Node* node = head->next;
	
	head->next = nullptr;
	delete head;

	head = node;
	size--;
}

void LinkedList::PrintData()
{
	if (Empty()) {
		cout << "Empty\n" << endl;
	}

	int count = 0;
	for (Node* node = head; node != nullptr; node = node->next) {
		cout << count++ << " : " << node->data << "\n";
	}
	cout << "\n";
}

int& LinkedList::Get(int i)
{
	int cnt = 0;
	Node* cur = head;
	while (cnt++ < i && cur->next != nullptr) {
		cur = cur->next;
	}

	return cur->data;
}
