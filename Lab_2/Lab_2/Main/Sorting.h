#pragma once
#include <iostream>
#include <ctime>
/* Additional functions */

template<typename T>
class Sorting {
private:
	T* vector = nullptr;
	unsigned int size;
public:
	Sorting(unsigned int size)
	{
		vector = new T[size];
		this->size = size;
		srand(static_cast<int>(time(0))); // робим посів
	}
	
	~Sorting()
	{
		delete[] vector;
		vector = nullptr;
	}

	void FillOneDimArray(int from, int to, unsigned int size = 0)
	{
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

	/* Sort algorithms*/
	void BubbleSort(unsigned int size)
	{
		float flag = true;
		unsigned int k = 0;
		while (flag) {
			flag = false;
			for (unsigned int i = size - 1; i > k; i--) {
				if (vector[i] < vector[i - 1]) {
					Swap(vector[i], vector[i - 1]);
					flag = true;
				}
			}
			k++;
		}
	}

	void SelectionSort(unsigned int size)
	{
		if (size > this->size)
			size = this->size;
		
		int minindex;
		for (unsigned int i = 0; i < size; i++)
			if ((minindex = MinElement(i, size)) != -1)
				Swap(vector[i], vector[minindex]);
	}

	void InsertionSort(unsigned int size)
	{
		if (size > this->size)
			size = this->size;

		for (unsigned int i = 1; i < size; i++)
			for (unsigned int k = i; k < size, vector[k - 1] > vector[k]; k--)
				Swap(vector[k - 1], vector[k]);

		/*for (unsigned int i = 1; i < size; i++) {
			for (unsigned int k = i; k < size; k--) {
				if (vector[k - 1] > vector[k])
					Swap(vector[k - 1], vector[k]);
				else
					break;
			}
		}*/
	}

private:
	void Swap(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;
	}

	int MinElement(unsigned int start, unsigned int end)
	{
		T element = vector[start];
		unsigned int index = start;
		for (unsigned int i = start + 1; i < end; i++) {
			if (element > vector[i]) {
				index = i;
				if (index != end - 1)
					element = vector[i];
			}
		}

		return index != start ? index : -1;
	}
};