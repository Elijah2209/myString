#pragma once
class string {
private:
	char*arr;
	bool chack(string, int);
	string* increaseArr( int);
	void increaseStr();
public:
	~string() {
	}
	string();
	string(char*);
	void append(char*);
	string* split(string, int&);
	void outArr(string*, int);
	string sabstr(int, int);
	void format(string, string);
};