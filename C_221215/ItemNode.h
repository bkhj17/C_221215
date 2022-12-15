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
	{0, 100, "사과"},
	{1, 2000, "검"},
	{2, 2000, "방패"},
	{3, 200, "횃불"},
	{4, 500, "포션"}
};

struct Item {
	int itemKey = -1, count = 0;
	ItemData data;

	Item(int itemKey, int count = 1) : itemKey(itemKey), count(count) {
		data = ITEM_DATABASE[itemKey];
	}
};