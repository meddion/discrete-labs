#pragma once
#include <iostream>
#include <exception>

template <typename T>
class Queue
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
	} *list;
	unsigned int size;
public:
	Queue();
	~Queue();
	void Enqueue(T data);
	void Dequeue();
	//Item* GetHead() const;
	T Peek() const;
	unsigned int GetSize() const;
	bool IsEmpty() const;
};

template<typename T>
Queue<T>::Queue()
{
	list = nullptr;
	size = 0;
}

template<typename T>
Queue<T>::~Queue()
{
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

template<typename T>
inline T Queue<T>::Peek() const
{
	if (this->IsEmpty()) throw std::exception("Queue underflow.");
	return *(list->data);
}

template<typename T>
inline unsigned int Queue<T>::GetSize() const
{
	return this->size;
}

template<typename T>
inline bool Queue<T>::IsEmpty() const
{
	return (this->size == 0);
}
