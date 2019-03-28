#include <iostream>
#include "Sorting.h"

unsigned int fact(unsigned int num)
{
	if (num < 2)
		return 1;

	return num * fact(num - 1);
	/*
	unsigned int fact = 1;
	while(num > 1)
		fact *= num--;

	return fact;
	*/
}

unsigned int UnicA(unsigned int n, unsigned int k)
{
	return fact(n) / fact(n - k);
}

unsigned int A(unsigned int n, unsigned int k)
{
	return static_cast<unsigned int>(pow(n, k));
}

unsigned int UnicC(unsigned int n, unsigned int k)
{
	return UnicA(n, k) / fact(k);
}

unsigned int C(unsigned int n, unsigned int k)
{
	return UnicA(k, n + k - 1);
}

template<typename T>
unsigned int MinElement(T* vector, unsigned int start, unsigned int end, T value)
{
	T element = vector[start];
	unsigned int index = start;
	for (unsigned int i = start + 1; i < end; i++) {
		if (element > vector[i] && value < vector[i]) {
			index = i;
			if (index != end - 1)
				element = vector[i];
		}
	}

	return index;
}

template<typename T>
bool GenPerm(T* v, unsigned int size)
{
	int i;
	for (i = size - 2; i >= 0; i--)
		if (v[i] < v[i + 1])
			break;

	if (i == -1)
		return false;

	unsigned int min;
	do {
		min = MinElement(v, i + 1, size, v[i]);
	} while (v[i] > v[min]);

	Sorting::Swap(v[i], v[min]);
	Sorting::SelectionSort(v, size, i + 1);

	return true;
}

template<typename T>
void ShowArray(T* array, unsigned int size, int k = -1)
{
	if (k != -1)
		std::cout << k++ << ". ";

	for (unsigned int n = 0; n < size; n++)
		std::cout << array[n];
	std::cout << std::endl;
}

template<typename T>
void ShowAllPerm(T* array, unsigned int size)
{
	Sorting::SelectionSort(array, size);
	int k = 1;
	do {
		ShowArray(array, size, k++);
	} while (GenPerm(array, size) && size > 1);
}

template<typename T>
bool GenComb(T* array, unsigned int n, unsigned int k)
{
	for (int i = k - 1; i >= 0; i--) {
		if (array[i] < (int)(n - k + i + 1)) {
			array[i]++;
			for (unsigned int j = i + 1; j < k; j++)
				array[j] = array[j - 1] + 1;

			return true;
		}
	}
	return false;
}

template<typename T>
void ShowAllComb(T* array, unsigned int n, unsigned int k)
{
	Sorting::SelectionSort(array, n);
	ShowArray(array, k, 1);
	unsigned int x = 2;
	for (unsigned int i = 1; i <= UnicC(n, k); i++) {

		if (!GenComb(array, n, k))
			break;

		ShowArray(array, k, x++);
	}
}