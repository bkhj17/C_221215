#include "InventoryTest.h"
#include <iostream>
#include "ItemNode.h"
#include "Node.h"
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include <conio.h>

InventoryTest::InventoryTest()
{
    list = new DoublyLinkedList<Item>();
}

InventoryTest::~InventoryTest()
{
    delete list;
}

InventoryTest::InputType InventoryTest::GetInput()
{
    if (!requestInput)
        return InputType::NONE;
    requestInput = false;

    while (1) {
        if (_kbhit) {
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
    case InventoryTest::InputType::NONE:
        break;
    case InventoryTest::InputType::UP:
        cursor--;
        if (cursor < 0)
            cursor = 2;

        requestInput = true;
        requestRender = true;
        break;
    case InventoryTest::InputType::DOWN:
        cursor = (++cursor) % 3;

        requestInput = true;
        requestRender = true;
        break;
    case InventoryTest::InputType::YES:
        if (cursor == 3)
            gameState = GameState::EXIT;
        else
            requestInput = true;
        break;
    case InventoryTest::InputType::CANCEL:
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
    case InventoryTest::InputType::NONE:
        break;
    case InventoryTest::InputType::UP:
        cursor--;
        if (cursor < 0)
            cursor = list->GetSize();

        requestInput = true;
        requestRender = true;
        break;
    case InventoryTest::InputType::DOWN:
        cursor = (++cursor) % (list->GetSize() + 1);

        requestInput = true;
        requestRender = true;
        break;
    case InventoryTest::InputType::YES:
        if (cursor == list->GetSize()) {
            gameState = GameState::LOBBY;
            requestRender = true;
        }
        requestInput = true;
        break;
    case InventoryTest::InputType::CANCEL:
        gameState = GameState::LOBBY;
        requestRender = true;
        requestInput = true;
        break;
    default:
        break;
    }
}

void InventoryTest::RunShop()
{
}

void InventoryTest::Run()
{
    gameState = GameState::BAG;
    requestInput = true;
    requestRender = true;
    AddMoney(3000);
    AddItem(0, 4);
    AddItem(1, 1);
    AddItem(2, 1);
    AddItem(0, 1);

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
            break;
        case InventoryTest::GameState::EXIT:
            return;
        }
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
        cout << "\t상점" << endl;
        cout << "\t가방" << endl;
        cout << "\n==================================\n"
            << "위 : W, 아래 : S, Z: 확인 X: 종료\n";
	}
	break;

	case InventoryTest::GameState::BAG:
	{
		cout << "[가방]" << endl;
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
		cout << "[상점]" << endl;


        cout << "\n==================================\n"
            << "위 : W, 아래 : S, Z: 확인 X: 뒤로\n";
	}
	break;
	}

    //상황 표시 : 가게, 가방, 로비
    //상황별 
}

bool InventoryTest::UseMoney(int pay)
{
    if(!AblePay(pay))
        return false;

    money -= pay;
    return true;
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
