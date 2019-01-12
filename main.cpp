#include <iostream>
#include "String.h"

int main() {
	char str[256];
	std::cin.getline(str, 256);
	string myString(str);
	myString.append(str);
	char strSeparator[256];
	std::cin.getline(strSeparator, 256);
	string separator(strSeparator);
	int size = 0;
	string* arrString = myString.split(separator, size);
	myString.outArr(arrString, size);
	string newStr = myString.sabstr(2, 5);
	char str_1[4] = "lol";
	string myString_1(str_1); 
	char str_2[5] = "kek"; 
	string myString_2(str_2);
	myString.format(myString_1, myString_2);
	return 0;
 }

