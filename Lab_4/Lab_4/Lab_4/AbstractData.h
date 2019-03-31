#pragma once

template <typename T>
class AbstractData {
protected:
	struct Item;
	unsigned int size;
	Item* list;
public:
	T Peek() const;
	void Show() const;
	unsigned int GetSize() const;
	bool IsEmpty() const;
};

template<typename T>
struct AbstractData<T>::Item
{
	T* data;
	Item* next = nullptr;
	~Item()
	{
		delete data;
	}
};

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

template<typename T>
T AbstractData<T>::Peek() const
{
	if (!this->size) throw std::exception("Stack underflow.");
	return *(this->list->data);
}

template<typename T>
void AbstractData<T>::Show() const
{
	Item* temp = this->list;
	unsigned int k = 0;
	while (temp != nullptr) {
		std::cout << ++k << ". " << *(temp->data) << std::endl;
		temp = temp->next;
	}
}