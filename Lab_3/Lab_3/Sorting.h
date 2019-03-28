#pragma once
namespace Sorting {
	template<typename T>
	void Swap(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;
	}

	template<typename T>
	int MinElement(T* vector, unsigned int start, unsigned int end)
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

		return index;
	}

	/* Sort algorithms*/
	template<typename T>
	void BubbleSort(T* vector, unsigned int size, unsigned int from = 0)
	{
		float flag;
		do {
			flag = false;
			for (unsigned int i = size - 1; i > from; i--) {
				if (vector[i] < vector[i - 1]) {
					Swap(vector[i], vector[i - 1]);
					flag = true;
				}
			}
			from++;
		} while(flag);
	}

	template<typename T>
	void SelectionSort(T* vector, unsigned int size, unsigned int from = 0)
	{
		int minindex;
		for (unsigned int i = from; i < size; i++)
			if ((minindex = MinElement(vector, i, size)) != i)
				Swap(vector[i], vector[minindex]);
	}

	template<typename T>
	void InsertionSort(T* vector, unsigned int size, unsigned int from = 0)
	{
		for (unsigned int i = from; i < size; i++)
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
}