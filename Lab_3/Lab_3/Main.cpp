#include <iostream>
#include "Comb.h"
#include "DynamicArray.h"
#include "Sorting.h"

int main()
{
	int array[] = {1, 2, 3, 4, 5};
	ShowAllComb(array, 5, 3);
	
	std::cin.get();
	return 0;
}