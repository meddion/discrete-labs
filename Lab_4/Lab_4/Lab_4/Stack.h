#pragma once
#include <iostream>
#include <exception>
#include "AbstractData.h"

template <typename T>
class Stack : public AbstractData<T>
{
private:
	typedef AbstractData<T>::Item Item;
	Item* list;
public:
	Stack();
	~Stack();
	void Push(const T& data);
	void Pop();
	T Peek() const;
	virtual void Show() const;
};

template<typename T>
Stack<T>::Stack() : AbstractData<T>::AbstractData()
{
	this->list = nullptr;
}

template<typename T>
Stack<T>::~Stack()
{
	while (!this->IsEmpty())
		this->Pop();
}

template<typename T>
void Stack<T>::Push(const T& data)
{
	Item* temp = new Item;
	temp->data = data;
	temp->next = this->list;
	this->list = temp;
	this->size++;
}

template<typename T>
void Stack<T>::Pop()
{
	if (!this->size) throw std::exception("Stack underflow.");
	Item* temp = this->list;
	this->list = temp->next;
	delete temp;
	this->size--;
}

template<typename T>
T Stack<T>::Peek() const
{
	if (!this->size) throw std::exception("Stack underflow.");
	return this->list->data;
}

template<typename T>
void Stack<T>::Show() const
{
	Item* temp = this->list;
	unsigned int k = 0;
	while (temp != nullptr) {
		std::cout << ++k << ". " << temp->data << std::endl;
		temp = temp->next;
	}
}