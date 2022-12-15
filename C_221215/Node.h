#pragma once
struct Node
{
public:
	Node(int data) : data(data) {};
	~Node() { if(next) delete next; }

	int data = 0;
	Node* next = nullptr;
};

