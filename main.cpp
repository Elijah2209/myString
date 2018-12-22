#include <iostream>
#include "String.h"

int main() {
	char str[256];
	std::cin.getline(str, 256);
	string myString(str);
	myString.append(str);
	char* separator = new char[256];
	std::cin.getline(separator, 256);
	int size = 0;
	string* arrString = myString.split(separator, size);
	myString.outArr(arrString, size);
	return 0;
 }

