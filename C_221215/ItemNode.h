#pragma once
#include <iostream>
using namespace std;

#define ITEM_NUM 5

struct ItemData
{
	int key = 0;
	int price = 0;
	string name = "";
};

const ItemData ITEM_DATABASE[ITEM_NUM] = {
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
		data = ITEM_DATABASE[itemKey];
	}
};