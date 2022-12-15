#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
struct SinglyNode;

template <typename T>
class LinkedList
{
public:
	void PushBack(T data);
	void PushFront(T data);

	void PopBack();
	void PopFront();

	void PrintData();

	void Insert(T data, int pos);
	T* Find(int i);

	T* Front();
	T* Back();

	bool Empty() { return head == nullptr; }
private:
	int size = 0;
	SinglyNode<T>* head = nullptr;
	SinglyNode<T>* tail = nullptr;
};


template <typename T>
inline void LinkedList<T>::PushBack(T data)
{
	if (Empty()) {
		tail = head = new SinglyNode<T>(data);
	}
	else {
		tail->next = new SinglyNode<T>(data);
		tail = tail->next;
	}
	size++;
}

template <typename T>
inline void LinkedList<T>::PushFront(T data)
{
	if (Empty()) {
		tail = head = new SinglyNode<T>(data);
	}
	else {
		SinglyNode<T>* in = new SinglyNode<T>(data);
		in->next = head;
		head = in;
	}
	size++;
}

template <typename T>
inline void LinkedList<T>::PopBack()
{
	if (Empty())
		return;

	if (head == tail) {
		delete tail;
		head = nullptr;
		tail = nullptr;
	}
	else {
		SinglyNode<T>* node = head;
		while (node->next != tail) {
			node = node->next;
		}	//tail 바로 앞의 노드를 찾는다
		delete tail;
		tail = node;
		tail->next = nullptr;
	}
	size--;
}

template <typename T>
inline void LinkedList<T>::PopFront()
{
	if (Empty())
		return;

	SinglyNode<T>* node = head->next;
	head->next = nullptr;	//소멸자에서 연쇄적으로 삭제되게 했기 때문에 끊어놔야 한다
	delete head;

	head = node;
	size--;
}

template <typename T>
inline void LinkedList<T>::PrintData()
{
	if (Empty()) {
		cout << "Empty\n" << endl;
	}

	int count = 0;
	for (SinglyNode<T>* node = head; node != nullptr; node = node->next) {
		cout << count++ << " : " << node->data << "\n";
	}
	cout << "\n";
}

template <typename T>
inline void LinkedList<T>::Insert(T data, int pos)
{
	if (pos < 0 || pos >= size)
		return;

	if (pos == 0) {
		PushFront(data);
		return;
	}
	else if (pos == size) {
		PushBack(data);
		return;
	}

	int cnt = 0;
	SinglyNode<T>* cur = head;
	while (cnt < pos - 1 && cur->next != nullptr) {
		cur = cur->next;
		cnt++;
	}
	SinglyNode<T>* insert = new SinglyNode<T>(data);
	if (cur->next != nullptr)
		insert->next = cur->next;
	cur->next = insert;
}

template <typename T>
inline T* LinkedList<T>::Find(int i)
{
	if (i < 0 || i >= size)
		return nullptr;

	int cnt = 0;
	SinglyNode<T>* cur = head;
	while (cnt++ < i && cur->next != nullptr) {
		cur = cur->next;
	}

	return &(cur->data);
}

template <typename T>
inline T* LinkedList<T>::Front()
{
	if (head == nullptr)
		return nullptr;
	return &(head->data);
}

template <typename T>
inline T* LinkedList<T>::Back()
{
	if (tail == nullptr)
		return nullptr;
	return &(tail->data);
}
