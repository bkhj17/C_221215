#pragma once
#include <iostream>
using namespace std;

#define ITEM_TYPE 5

struct ItemData
{
	int key = 0;
	int price = 0;
	string name = "";
};

const ItemData ItemDatabase[ITEM_TYPE] = {
	{0, 100, "���"},
	{1, 2000, "��"},
	{2, 2000, "����"},
	{3, 200, "ȶ��"},
	{4, 500, "����"}
};

struct Item {
	int itemKey = -1, count = 0;
	ItemData data;

	Item(int itemKey, int count = 1) : itemKey(itemKey), count(count) {
		data = ItemDatabase[itemKey];
	}
};