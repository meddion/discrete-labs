#pragma once
#include "AbstractData.h"

template <typename T>
class Deque : public AbstractData<T>
{
private:
	unsigned int id;
	typedef AbstractData<T>::Node Node;
	Node *tail, *head;
	Node* CreateNode(const T& data);
public:
	Deque();
	~Deque();
	void AddToTail(const T& data);
	void AddToHead(const T& data);
	void DelFromTail();
	void DelFromHead();
	Node* Search(unsigned int id);
	void AddAfter(const T& data, unsigned int id);
	void DelElementById(unsigned int id);
	virtual void Show() const;
};

template<typename T>
Deque<T>::Deque() : AbstractData<T>::AbstractData()
{ 
	this->tail = this->head = nullptr;
	this->id = 0;
}

template<typename T>
Deque<T>::~Deque()
{
	while (!this->IsEmpty())
		this->DelFromTail();
}

template<typename T>
typename Deque<T>::Node* Deque<T>::CreateNode(const T& data)
{
	Node* node = new Node;
	node->data = data;
	node->id = this->id++;
	return node;
}

template<typename T>
void Deque<T>::AddToTail(const T& data)
{
	Node* temp = CreateNode(data);

	temp->next = this->tail;
	if (this->tail != nullptr)
		this->tail->prev = temp;
	else
		this->head = temp;

	this->tail = temp;
	this->size++;
}

template<typename T>
void Deque<T>::AddToHead(const T& data)
{
	Node* temp = CreateNode(data);

	temp->prev = this->head;
	if (this->head != nullptr)
		this->head->next = temp;
	else
		this->tail = temp;

	this->head = temp;
	this->size++;
}

template<typename T>
void Deque<T>::DelFromTail()
{
	if (this->IsEmpty()) throw std::exception("Deque underflow.");

	Node* temp = this->tail;
	this->tail = temp->next;
	if (this->tail != nullptr) this->tail->prev = nullptr;
	delete temp;
	this->size--;
}

template<typename T>
void Deque<T>::DelFromHead()
{
	if (this->IsEmpty()) throw std::exception("Deque underflow.");

	Node* temp = this->head;
	this->head = temp->prev;
	if (this->head != nullptr) this->head->next = nullptr;
	delete temp;
	this->size--;
}

template<typename T>
typename Deque<T>::Node* Deque<T>::Search(unsigned int id)
{
	if (this->IsEmpty()) throw std::exception("Deque underflow.");
	
	Node* temp = this->tail;
	do {
		if (id == temp->id)
			return temp;
		temp = temp->next;
	} while (temp != nullptr);

	return nullptr;
}

template<typename T> 
void Deque<T>::AddAfter(const T& data, unsigned int id)
{
	Node* founded = this->Search(id);
	if (founded == nullptr) throw std::exception("There's no such element in the deque.");
	Node* temp = CreateNode(data);
	temp->next = founded->next;
	temp->prev = founded;
	if (founded->next != nullptr)
		founded->next->prev = temp;
	
	founded->next = temp;
}

template<typename T>
void Deque<T>::DelElementById(unsigned int id)
{
	Node* founded = this->Search(id);
	if (founded == nullptr) throw std::exception("There's no such element in the deque.");

	if (founded->next != nullptr)
		founded->next->prev = founded->prev;

	if (founded->prev != nullptr)
		founded->prev->next = founded->next;

	delete founded;
}

template<typename T>
inline void Deque<T>::Show() const
{
	Node* temp = this->tail;
	unsigned int k = 0;
	while (temp != nullptr) {
		std::cout << ++k << ". " << temp->data << std::endl;
		temp = temp->next;
	}
}
