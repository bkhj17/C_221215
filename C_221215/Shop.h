#pragma once

struct Item;

template <typename T>
struct DoublyNode;

template <typename T>
class DoublyLinkedList;

class Shop {
	enum class ShopState {
		MENU_SELECT,
		BUY,
		SELL,
		OUT
	};
	ShopState shopState = ShopState::MENU_SELECT;

public:
	Shop();
	~Shop();

	void Init(int* money, DoublyLinkedList<Item>* list);

	bool MenuSelect(const InputType& input);
	void BuyRun(const InputType& input);
	void SellRun(const InputType& input);

	void AddMoney(int gain) { *playerMoney += gain; }
	bool AblePay(int pay) { return *playerMoney >= pay; }
	bool UseMoney(int pay);

	bool Run(const InputType& input);
	void Render();

	Item* GetPlayerData(int key);

private:
	int cursor = 0;
	bool noMoney = false;;

	int* playerMoney = nullptr;
	DoublyLinkedList<Item>* playerList = nullptr;
	DoublyLinkedList<Item>* sellList = nullptr;
};