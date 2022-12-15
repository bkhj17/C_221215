#pragma once
template <typename T>
struct SinglyNode
{
public:
	SinglyNode(int data) : data(data) {};
	~SinglyNode() { if(next) delete next; }

	int data = 0;
	SinglyNode* next = nullptr;
};

