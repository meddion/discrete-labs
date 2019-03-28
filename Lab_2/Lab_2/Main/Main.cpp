#include "Sorting.h"
#include <ctime>
#include <iostream>

int main()
{
	/*
	sorting->FillOneDimArray(10, 1, 10);
	sorting->ShowArray();
	sorting->BubbleSort(10);
	sorting->ShowArray();
	std::cin.get();*/
	unsigned int size_of_array;
	clock_t tStart;
	double tEnd;
	unsigned int upperBorder;
	char response;
	unsigned int mod = 1;

	Sorting<char>* sorting;

	while (1) {
		std::cout << "\nSet your size of array: ";
		std::cin >> size_of_array;
		sorting = new Sorting<char>(size_of_array);

		sorting->FillOneDimArray(0, 100);

		std::cout << "Set the upper border in order to sort the array of " << size_of_array << ": ";
		std::cin >> upperBorder;

		if (upperBorder > size_of_array)
			upperBorder = size_of_array;

		std::cout << "\nPick your sroting algorithm (1 - bubble sort, 2 - selection sort, 3 - insertion sort): ";
		std::cin >> mod;

		if (mod < 1 || mod > 3)
			mod = 1;
		
		std::cout << "Array before sorting.\n";
		sorting->ShowArray();

		std::cout << "Sorted by ";
		tStart = clock();
		switch (mod) {
		case 1:
			std::cout << "bubble";
			sorting->BubbleSort(upperBorder);
			break;
		case 2:
			std::cout << "selection";
			sorting->SelectionSort(upperBorder);
			break;
		case 3:
			std::cout << "insertion";
			sorting->InsertionSort(upperBorder);
			break;
		}
		std::cout << " sort\n";
		tEnd = (double)(clock() - tStart) / CLOCKS_PER_SEC;
		sorting->ShowArray();
		std::cout << "executing time: " << tEnd << " sec\n";

		delete sorting;
		sorting = nullptr;
		
		// continue ?
		std::cout << "Do yo wanna try again ? (y/n)\n";
		std::cin >> response;
		if (response != 'y' && response != 'Y')
			break;
	}
	return 1;
}