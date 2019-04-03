#pragma once

template <typename T>
class AbstractData {
protected:
	struct Item;
	struct Node;
	unsigned int size;
public:
	AbstractData();
	virtual void Show() const = 0;
	unsigned int GetSize() const;
	bool IsEmpty() const;
};

template<typename T>
struct AbstractData<T>::Item
{
	T data;
	Item* next = nullptr;
};

template<typename T>
struct AbstractData<T>::Node
{
	unsigned int id;
	T data;
	Node* next = nullptr;
	Node* prev = nullptr;
};

template<typename T>
AbstractData<T>::AbstractData()
{
	this->size = 0;
}


template<typename T>
inline unsigned int AbstractData<T>::GetSize() const
{
	return this->size;
}

template<typename T>
inline bool AbstractData<T>::IsEmpty() const
{
	return (this->size == 0);
}