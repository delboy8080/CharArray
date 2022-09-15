#include "CharArray.h"

CharArray::CharArray(int size)
{
	arr = new char[size];
	capacity = size;
	top = 0;
}
CharArray::CharArray(const CharArray& other)
{
	capacity = other.capacity;
	top = other.top;
	arr = new char[capacity];
	for (int i = 0; i < top; i++)
	{
		arr[i] = other.arr[i];
	}
}

CharArray& CharArray::operator=(CharArray& other)
{
	std::cout << "Assignment Operator Called" << std::endl;
	if (this == &other)
		return *this;

	capacity = other.capacity;
	top = other.top;
	if (arr != nullptr)
	{
		delete[] arr;
	}
	arr = new char[capacity];
	for (int i = 0; i < top; i++)
	{
		arr[i] = other.arr[i];
	}
	return *this;
}
bool CharArray::add(char c)
{
	if (top == capacity)
	{
		char* temp = new char[capacity * 2];
		for (int i = 0; i < top; i++)
		{
			temp[i] = arr[i];
		}
		capacity *= 2;
		delete[] arr;
		arr = temp;
	}
	arr[top] = c;
	top++;
	return true;
}
bool CharArray::insert(char c, int pos)
{
	if (top == capacity)
	{
		char* temp = new char[capacity * 2];
		for (int i = 0; i < top; i++)
		{
			temp[i] = arr[i];
		}
		capacity *= 2;
		delete[] arr;
		arr = temp;
	}
	for (int i = top-1; i >= pos; i--)
	{
		arr[i+1] = arr[i];
	}
	arr[pos] = c;
	top++;
	return true;
}
bool CharArray::remove(int index)
{
	if (index < top && index >-1)
	{
		for (int i = index; i < top; i++)
		{
			arr[i] = arr[i + 1];
		}
		top--;
		return true;
	}
	return false;
}
char CharArray::get(int index)
{
	if (index < top && index>-1)
	{
		return arr[index];
	}
	return 0;
}
bool CharArray::set(char c, int index)
{
	if (index < top && index>-1)
	{
		arr[index] = c;
		return true;
	}
	return false;
}
int CharArray::size()
{
	return top;
}
CharArray::~CharArray()
{
	delete[] arr;
	arr = nullptr;
}