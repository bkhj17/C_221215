#pragma once
template <typename T>
struct DoublyNode
{
	T data;
	DoublyNode<T> *prev = nullptr, * next = nullptr;

	DoublyNode(T data) : data(data) {}
	~DoublyNode() { if (next) delete next; }
};

