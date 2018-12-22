#include "String.h"
#include <iostream>

string::string(char* str) {
	int N = strlen(str); 
	arr = new char[N];
	arr = str;
}

string::string() {
}


void string::append(char* str) {
	int size = strlen(arr) + strlen(str)+1;
	char* newArr = new char[size];
	int i = 0;
	for (int j = 0; j < strlen(arr);j++) {
		newArr[i] = arr[j];
		i++;
	}
	for (int j = 0; j < strlen(str)+1; j++) {
		newArr[i] = str[j];
		i++;
	}
	arr = newArr;
}

string* string::split (char* separator, int& itArr) {
	string* arrStr = new string [itArr];
	int size = strlen(separator), j = 0, it = 0;
	while (it < strlen(arr)+1) {
		char* tmpStr = new char[strlen(separator) + 1];
		string* myStr = new string(tmpStr);
		myStr->arr[j] = arr[it];
		while (!myStr->chack(separator, j) && it < strlen(arr) + 1){
			j++;
			it++;
			myStr->arr[j] = arr[it];
		}
			myStr->arr[j - (size-1)] = '\0';
			if (myStr->arr[0] != '\0') {
				itArr++;
				increaseArr(arrStr, itArr);
				arrStr[itArr - 1] = *myStr;
			}
			j = 0;
		it++;
	}
	return arrStr;
}

bool string::chack(char* separator, int j) {
	int size = strlen(separator)-1;
		int k = size;
		while (j >= 0) {
			if (arr[j] == separator[k]) {
				k--;
				j--;
				if (k < 0) {
					return 1;
				}
			}
			else {
				k = size;
				if (arr[j] != separator[k]) {
					j--;
				}
			}
	}
		return 0;
}

string* string::increaseArr(string* myArr, int size) {
	string* newArr = new string[size];
	newArr = myArr;
	return newArr;
	delete[]myArr;
}

void string::outArr(string* arrStr, int size) {
	int j = 0;
	while (j < size) {
		int i = 0;
		while (i < strlen(arrStr[j].arr)) {
			std::cout << arrStr[j].arr[i];
			i++;
		}
		std::cout << std::endl;
		j++;
	}
}
