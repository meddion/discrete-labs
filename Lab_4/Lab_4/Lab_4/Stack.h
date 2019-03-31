#pragma once
#include <iostream>
#include <exception>
#include "AbstractData.h"

template <typename T>
class Stack : public AbstractData<T>
{
public:
	typedef AbstractData<T>::Item Item;
	Stack();
	~Stack();
	void Push(T data);
	void Pop();
};

template<typename T>
Stack<T>::Stack()
{
	this->list = nullptr;
	this->size = 0;
}

template<typename T>
Stack<T>::~Stack()
{
	while (!this->IsEmpty())
		this->Pop();
}

template<typename T>
void Stack<T>::Push(T data)
{
	Item* temp = new Item;
	temp->data = new T(data);
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