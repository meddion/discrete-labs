#include <iostream>
#include "Lib1.h"

int main()
{
	bool a1, b1;
	char answer;
	int a, b;
	bool arr[8][3] = {
		{true,  true,  true}, 
		{false, false, false},
		{false, true,  true},
		{false, false, true},
		{true,  false, true},
		{true,  false, false},
		{true,  true,  false},
		{false, true,  false},
	};
	while (true) {

		std::cout << "Type a and b: ";
		std::cin >> a >> b;

		a1 = static_cast<bool>(a);
		b1 = static_cast<bool>(b);

		std::cout << "#1 First part (a, b)\n";
		std::cout << "NOT(a) -> " << NOT(a1) << std::endl;
		std::cout << "NOT(b) -> " << NOT(b1) << std::endl;
		std::cout << "AND(a, b) -> " << AND(a1, b1) << std::endl;
		std::cout << "OR(a, b) -> " << OR(a1, b1) << std::endl;
		std::cout << "IMP(a, b) -> " << IMP(a1, b1) << std::endl;
		std::cout << "EQU(a, b) -> " << EQU(a1, b1) << std::endl;
		std::cout << "XOR(a, b) -> " << XOR(a1, b1) << std::endl;

		// SPECIAL TASK
		std::cout << "#2 Second part (a, b, c)\n";
		for (auto& elem : arr) {
			std::cout << "F2(" << elem[0] << elem[1] << elem[2] << ") -> "
				<< F2(elem[0], elem[1], elem[2]) << std::endl;
		}

		// CONTINUE ?
		std::cout << "Do you wanna continue ? (y/n)\n";
		std::cin >> answer;

		if (answer != 'y' && answer != 'Y')
			return 1;
	}
	return 1;
}