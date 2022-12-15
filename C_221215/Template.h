#pragma once
#include <iostream>
using namespace std;

template<typename T>
void Swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

//template <class T>�� �� �� �ִ�. ���� ����
template <typename T>	
class AddOperator {
public:
	AddOperator(T x, T y) : x(x), y(y) {}

	void Print() {
		cout << (x + y) << endl;
	}
private:
	T x, y;
};
