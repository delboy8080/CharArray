#pragma once
#include <iostream>
using std::ostream;
class CharArray
{
	char* arr;
	int capacity;
	int top;

public:
	CharArray(int size = 10);
	CharArray(const CharArray& other);
	bool add(char c);
	bool insert(char c, int pos);
	bool remove(int index);
	char get(int index);
	bool set(char c, int index);
	int size();
	CharArray& operator=(CharArray& other);
	friend ostream& operator<<(ostream& out, CharArray& other);
	~CharArray();
};

