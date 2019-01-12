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

string* string::split (string separator, int& itArr) {
	string* arrStr = new string [itArr];
	int size = strlen(separator.arr), j = 0, it = 0;
	while (it < strlen(arr)+1) {
		char* tmpStr = new char[strlen(arr) + 1];
		string* myStr = new string(tmpStr);
		myStr->arr[j] = arr[it];
		while (!myStr->chack(separator.arr, j) && it < strlen(arr)){
			j++;
			it++;
			myStr->arr[j] = arr[it];
		}
		if (myStr->arr[j] != '\0') {
			myStr->arr[j - (size - 1)] = '\0';
		}
			if (myStr->arr[0] != '\0') {
				itArr++;
				arrStr = arrStr->increaseArr(itArr);
				arrStr[itArr - 1] = *myStr;
			}
			j = 0;
		it++;
	}
	return arrStr;
}



bool string::chack(string separator, int j) {
	int size = strlen(separator.arr)-1;
		int k = size;
		while (j >= 0) {
			if (arr[j] == separator.arr[k]) {
				k--;
				j--;
				if (k < 0) {
					return 1;
				}
			}
			else {
				k = size;
				if (arr[j] != separator.arr[k]) {
					j--;
				}
			}
	}
		return 0;
}

string* string::increaseArr(int size) {
	string* newArr = new string[size];
	int i = 0;
	while (i < size - 1) {
		newArr[i] = this[i];
		i++;
	}
	delete[] this;
	return newArr;
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

string string::sabstr(int left, int right) {
	if (strlen(arr) >= right) {
		int size = right - left + 1;
		char* tmpStr = new char[size];
		string myStr(tmpStr);
		int i = 0;
		while (left < right) {
			myStr.arr[i] = arr[left];
			left++;
			i++;
		}
		myStr.arr[i] = '\0';
		return myStr;
	}
	return 0;
}

void string::format(string from, string to) {
	int size = strlen(from.arr), j = 0, it = 0;
	char* tmpStr = new char[strlen(from.arr) + 1];
	string* myStr = new string(tmpStr);
	while (it < strlen(arr) + 1) {
		myStr->arr[j] = arr[it];
		while (!myStr->chack(from.arr, j)){
			if (it >= strlen(arr)){
				arr = myStr->arr;
				return;
			}
			j++;
			it++;
			if (strlen(myStr->arr) <= j) {
			 myStr->increaseStr();
			}
			myStr->arr[j] = arr[it];
		}
		int i = j - (size - 1);
		if (i + strlen(to.arr) >= strlen(myStr->arr)) {
			 myStr->increaseStr();
		}
		int k = 0;
		while (k < strlen(to.arr)) {
			myStr->arr[i] = to.arr[k];
			k++;
			i++;
			}
		j = i;
		it++;
	}
	arr = myStr->arr;
}
void string::increaseStr() {
	int size = strlen(arr) * 2;
	char* str = new char[size];
	int i = 0;
	while (i < size/2) {
		str[i] = arr[i];
		i++;
	}
	arr=str;
	size = strlen(arr);
}
