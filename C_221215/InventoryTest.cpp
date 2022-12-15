#include "InventoryTest.h"
#include <iostream>
#include "ItemNode.h"
#include "Node.h"
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "Shop.h"
#include <conio.h>

InventoryTest::InventoryTest()
{
    list = new DoublyLinkedList<Item>();
    shop = new Shop();
}

InventoryTest::~InventoryTest()
{
    delete list;
    delete shop;
}

InputType InventoryTest::GetInput()
{
    if (!requestInput)
        return InputType::NONE;
    requestInput = false;

    while (1) {
        if (_kbhit) {
            requestRender = true;
            switch (_getch())
            {
            case 'w':
                return InputType::UP;
            case 's':
                return InputType::DOWN;
            case 'z':
                return InputType::YES;
            case 'x':
                return InputType::CANCEL;
            default:
                break;
            }
        }
    }
}

void InventoryTest::RunLobby()
{
    switch (input)
    {
    case InputType::NONE:
        break;
    case InputType::UP:
        cursor--;
        if (cursor < 0)
            cursor = 2;

        requestInput = true;
        break;
    case InputType::DOWN:
        cursor = (++cursor) % 3;

        requestInput = true;
        break;
    case InputType::YES:
        if (cursor == 0) {
            shop->Init(&money, list);
            gameState = GameState::SHOP;
        }
        else if (cursor == 1)
            gameState = GameState::BAG;
        else if (cursor == 2)
            gameState = GameState::EXIT;
        cursor = 0;
        requestInput = true;
        break;
    case InputType::CANCEL:
        gameState = GameState::EXIT;
        requestRender = false;
        requestInput = false;
        break;
    default:
        break;
    }
}

void InventoryTest::RunBag()
{
    switch (input)
    {
    case InputType::NONE:
        break;
    case InputType::UP:
        cursor--;
        if (cursor < 0)
            cursor = list->GetSize();

        requestInput = true;
        requestRender = true;
        break;
    case InputType::DOWN:
        cursor = (++cursor) % (list->GetSize() + 1);

        requestInput = true;
        requestRender = true;
        break;
    case InputType::YES:
        if (cursor == list->GetSize()) {
            gameState = GameState::LOBBY;
            cursor = 0;
            requestRender = true;
        }
        requestInput = true;
        break;
    case InputType::CANCEL:
        gameState = GameState::LOBBY;
        cursor = 0;
        requestRender = true;
        requestInput = true;

        break;
    default:
        break;
    }
}

void InventoryTest::RunShop()
{
    if (shop->Run(input))
        gameState = GameState::LOBBY;
    requestRender = true;
    requestInput = true;
}

void InventoryTest::Run()
{
    gameState = GameState::LOBBY;
    requestInput = true;
    requestRender = true;
    money += 3000;

    while (1) {
        Render();
        input = GetInput();
        switch (gameState)
        {
        case InventoryTest::GameState::LOBBY:
            RunLobby();
            break;
        case InventoryTest::GameState::BAG:
            RunBag();
            break;
        case InventoryTest::GameState::SHOP:
            RunShop();
            break;
        case InventoryTest::GameState::EXIT:
            break;
        }
        if (gameState == GameState::EXIT)
            break;
    }
}

void InventoryTest::Render()
{
    if (!requestRender)
        return;
    requestRender = false;

    system("cls");
	switch (gameState)
	{
	case InventoryTest::GameState::LOBBY:
	{
		cout << "[로비]" << endl;
        if (cursor == 0)
            cout << "->";
        cout << "\t상점" << endl;
        if (cursor == 1)
            cout << "->";
        cout << "\t가방" << endl;
        if(cursor == 2)
            cout << "->";
        cout << "\t종료" << endl;
        cout << "\n==================================\n"
            << "위 : W, 아래 : S, Z: 확인 X: 종료\n";
	}
	break;

	case InventoryTest::GameState::BAG:
	{
		cout << "[가방]\n";
        cout << "소지금 : " << money << "\n";
		int cnt = 0;
		for (auto node = list->GetFront(); node != nullptr; node = node->next, cnt++) {
			if (cursor == cnt)
				cout << "->";
			cout << "\t" << node->data.data.name << "\t"
				<< node->data.count << "개\n";
		}
		if (cursor == cnt) {
			cout << "->";
		}
		cout << "\t뒤로 가기";

        cout << "\n==================================\n"
            << "위 : W, 아래 : S, Z: 확인 X: 뒤로\n";
	}
	break;

	case InventoryTest::GameState::SHOP:
	{
        shop->Render();
	}
	break;
	}

    //상황 표시 : 가게, 가방, 로비
    //상황별 
}

void InventoryTest::OpenShop()
{
}

void InventoryTest::AddItem(int id, int cnt)
{
    for (auto* node = list->GetFront(); node != nullptr; node = node->next) {
        if (node->data.itemKey == id) {
            node->data.count += cnt;
            return;
        }
    }

    list->PushBack(Item(id, cnt));
}
