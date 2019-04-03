#pragma once
#include <iostream>
#include <exception>
#include "AbstractData.h"

template <typename T>
class Queue : public AbstractData<T>
{
private:
	typedef AbstractData<T>::Item Item;
	Item* list;
public:
	Queue();
	~Queue();
	void Enqueue(const T& data);
	void Dequeue();
	T Peek() const;
	virtual void Show() const;
};

template<typename T>
Queue<T>::Queue() : AbstractData<T>::AbstractData()
{
	this->list = nullptr;
}

template<typename T>
Queue<T>::~Queue()
{
	while (!this->IsEmpty())
		this->Dequeue();
}

template<typename T>
void Queue<T>::Enqueue(const T& data)
{
	Item* temp = new Item;
	temp->data = data;

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

template<typename T>
T Queue<T>::Peek() const
{
	if (!this->size) throw std::exception("Stack underflow.");
	return this->list->data;
}

template<typename T>
void Queue<T>::Show() const
{
	Item* temp = this->list;
	unsigned int k = 0;
	while (temp != nullptr) {
		std::cout << ++k << ". " << temp->data << std::endl;
		temp = temp->next;
	}
}