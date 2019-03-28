#include "Lib1.h"

bool NOT(bool a)
{
	return a ? false : true;
	//return !a;
}

bool AND(bool a, bool b)
{
	if (a)
		if (b)
			return true;

	return false;
	//return a && b;
}

bool OR(bool a, bool b)
{
	return a ? a : b;
	//return a || b;
}

bool IMP(bool a, bool b)
{
	return OR(NOT(a), b);
	//return !a || b;
}

bool EQU(bool a, bool b)
{
	return OR(AND(a, b), AND(NOT(a), NOT(b)));
	//return a == b;
}

bool XOR(bool a, bool b)
{
	return EQU(a, b) ? false : OR(a, b);
}

bool F2(bool a, bool b, bool c)
{
	return EQU(IMP(a, AND(b, c)), AND(IMP(a, b), IMP(a, c)));
}
