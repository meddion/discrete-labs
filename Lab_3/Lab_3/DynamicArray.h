#pragma once
#include <ctime>
template<typename T>
class DynamicArray
{
private:
	T* vector = nullptr;
	unsigned int size;
public:
	DynamicArray(unsigned int size)
	{
		vector = new T[size];
		this->size = size;
	}

	~DynamicArray()
	{
		delete[] vector;
		vector = nullptr;
	}

	T* GetArray() const
	{
		return vector;
	}

	void FillOneDimArray(int from, int to, unsigned int size = 0)
	{
		srand(static_cast<int>(time(0))); // робим посів
		if (size > this->size || size == 0)
			size = this->size;

		int range = from + to;
		for (unsigned int i = 0; i < size; i++)
			vector[i] = static_cast<T>(from + rand() % range);
	}

	void ShowArray()
	{
		for (unsigned int i = 0; i < size; i++)
			std::cout << i << " -> " << vector[i] << std::endl;
	}

};