#pragma once
#include <iostream>
#include <exception>
#include "AbstractData.h"

template <typename T>
class Queue : public AbstractData<T>
{
public:
	typedef AbstractData<T>::Item Item;
	Queue();
	~Queue();
	void Enqueue(T data);
	void Dequeue();
};

template<typename T>
Queue<T>::Queue()
{
	this->list = nullptr;
	this->size = 0;
}

template<typename T>
Queue<T>::~Queue()
{
	while (!this->IsEmpty())
		this->Dequeue();
}

template<typename T>
void Queue<T>::Enqueue(T data)
{
	Item* temp = new Item;
	temp->data = new T(data);

	if (this->list != nullptr) {
		Item* temp2 = this->list;
		while (temp2->next != nullptr)
			temp2 = temp2->next;
		temp2->next = temp;
	} else {
		this->list = temp;
	}
	this->size++;
}

template<typename T>
void Queue<T>::Dequeue()
{	
	if (this->IsEmpty()) throw std::exception("Queue underflow.");
	Item* temp = this->list;
	this->list = temp->next;
	delete temp;
	this->size--;
}