#pragma once
#include <iostream>
#include <exception>

template <typename T>
class Stack 
{
private:
	struct Item
	{
		T* data;
		Item* next = nullptr;
		~Item()
		{
			delete data;
		}
	} *top;
	unsigned int size;
public:
	Stack();
	~Stack();
	void Push(T data);
	void Pop();
	T Peek() const;
	void Show() const;
	unsigned int GetSize() const;
};

template<typename T>
Stack<T>::Stack()
{
	top = nullptr;
	size = 0;
}

template<typename T>
Stack<T>::~Stack()
{
	Item* next = nullptr;
	Item* temp = this->top;
	while (temp != nullptr) {
		next = temp->next;
		delete temp;
		temp = next;
	}
}

template<typename T>
void Stack<T>::Push(T data)
{
	Item* temp = new Item;
	temp->data = new T(data);
	temp->next = this->top;
	this->top = temp;
	this->size++;
}

template<typename T>
void Stack<T>::Pop()
{
	if (!size) throw std::exception("Stack underflow.");
	Item* temp = this->top;
	this->top = temp->next;
	delete temp;
	this->size--;
}

template<typename T>
T Stack<T>::Peek() const
{
	if (!size) throw std::exception("Stack underflow.");
	return *(this->top->data);
}

template<typename T> 
void Stack<T>::Show() const
{
	Item* temp = this->top;
	unsigned int k = 0;
	while (temp != nullptr) {
		std::cout << ++k << ". " << temp->data << std::endl;
		temp = temp->next;
	}
}

template<typename T>
inline unsigned int Stack<T>::GetSize() const
{
	return this->size;
}
