#pragma once
class string {
private:
	char*arr;
	bool chack(char*, int);
	string* increaseArr(string*, int);
public:
	string();
	string(char*);
	void append(char*);
	string* split(char*, int&);
	void outArr(string*, int);
};