// C_221215.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include "Node.h"
#include "LinkedList.h"
using namespace std;


int main() {
    LinkedList list;
    
    list.PushBack(1);
    list.PushBack(3);
    list.PushBack(5);
    list.PrintData();
    
    list.PushFront(2);
    list.PrintData();

    list.PopBack();
    list.PrintData();

    list.PopFront();
    list.PrintData();
    return 0;
}