#include <iostream>
#include "Comb.h"
#include "DynamicArray.h"
#include "Sorting.h"

int main()
{
	//DynamicArray<int> vector(10);
	//vector.FillOneDimArray(0, 10);
	//int* array = vector.GetArray();
	int array[] = {1, 2, 3, 4, 5};

	ShowAllComb(array, 5, 3);
	
//	ShowAllComb(array, 5, 3);
	//std::cout << Sorting::MinElement(array, 2, 4);

	std::cin.get();
	return 0;
}