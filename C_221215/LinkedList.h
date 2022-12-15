#pragma once

struct Node;
class LinkedList
{
public:
	void PushBack(int data);
	void PushFront(int data);

	void PopBack();
	void PopFront();

	void PrintData();

	int& Get(int i);

	bool Empty() { return head == nullptr; }
private:
	int size = 0;
	Node* head = nullptr;
	Node* tail = nullptr;
};

