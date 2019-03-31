#include <iostream>
#include <exception>
#include "Stack.h"
#include "Queue.h"
/*typedef int datatype;
unsigned int k = 0;

struct Item 
{
	unsigned int id;
	datatype data;
	Item* next = nullptr;
	Item* prev = nullptr;
};

Item* CreateItem(Item* prevItem = nullptr)
{
	Item* item = new Item;
	item->next = nullptr;
	item->id = k++;

	if (prevItem != nullptr)
		item->prev = prevItem;
	else
		item->prev = nullptr;

	return item;
}

void AddNewItem(Item* item)
{
	item = item->next = CreateItem(item);
}

void SetData(Item* item, datatype data)
{
	item->data = data;
}

datatype GetData(Item* item)
{
	return item->data;
}
/*Item* item;

	item = CreateItem();

	std::cout << "Item #1: " << item << std::endl;
	AddNewItem(item);
	std::cout << "Item #2: " << item << std::endl;
	AddNewItem(item);
	std::cout << "Item #3: " << item << std::endl;

	SetData(item, 255);
	std::cout << item->data << std::endl;
*/

int main()
{
	try {
		/*Stack<int>* stack = new Stack<int>;
		stack->Push(1);
		stack->Push(2);
		stack->Push(3);
		stack->Push(4);
		stack->Pop();
		std::cout << stack->Peek() << std::endl;
		delete stack;*/

		Queue<int>* queue = new Queue<int>;
		queue->Enqueue(1);
		queue->Enqueue(2);
		queue->Enqueue(3);
		std::cout << queue->Peek() << std::endl;
		queue->Dequeue();
		std::cout << queue->Peek() << std::endl;
		delete queue;

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cin.get();
	return 0;
}

