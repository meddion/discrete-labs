/* This file was only created for test porposes*/
#include <iostream>
#include <exception>
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"

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

		/*Queue<int>* queue = new Queue<int>;
		queue->Enqueue(1);
		queue->Enqueue(2);
		queue->Enqueue(3);
		std::cout << queue->Peek() << std::endl;
		queue->Dequeue();
		std::cout << queue->Peek() << std::endl;
		queue->Show();
		delete queue;*/
		
		/*Deque<int>* deque = new Deque<int>;
		deque->AddToHead(1);
		deque->AddToHead(2);
		deque->AddToHead(3);
		deque->AddAfter(255, 0);
		deque->DelElementById(1);
		deque->Show();
		delete deque;*/
		
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cin.get();
	return 0;
}

