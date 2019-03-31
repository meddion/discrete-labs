#include <iostream>
#include <exception>
#include "Stack.h"
#include "Queue.h"


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
		queue->Show();
		delete queue;

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cin.get();
	return 0;
}

