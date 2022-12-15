#pragma once

struct Item;

template <typename T>
struct DoublyNode;

template <typename T>
class DoublyLinkedList;

enum class InputType
{
	NONE, UP, DOWN, YES, CANCEL,
};

class InventoryTest
{
	bool requestInput = false;
	bool requestRender = true;
	InputType input = InputType::NONE;

	enum class GameState {
		LOBBY,
		BAG,
		SHOP,
		EXIT,
	};
	GameState gameState = GameState::LOBBY;

public:
	InventoryTest();
	~InventoryTest();

	InputType GetInput();
	void RunLobby();
	void RunBag();
	void RunShop();
	void Run();
	void Render();


	void OpenShop();
	void AddItem(int id, int cnt);

private:
	int money = 0;
	int cursor = 0;
	DoublyLinkedList<Item>* list;

	class Shop* shop = nullptr;
};

