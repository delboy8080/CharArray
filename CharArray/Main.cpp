#include <iostream>
#include "CharArray.h"
using namespace std;

void display(CharArray arr)
{
	cout << "[";
	for (int i = 0; i < arr.size(); i++)
	{
		if (i != 0)
			cout << ", ";
		cout << arr.get(i);
	}
	cout << "]" << endl;
}

int main()
{
	CharArray arr(5);
	for (int i = 65; i <= 90; i++)
	{
		arr.add(i);
	}
	display(arr);
	for (int i = 0; i < arr.size(); i += 5)
	{
		arr.set('x', i);
	}
	display(arr);
	arr.insert('z', 0);
	arr.insert('z', 10);
	for (int i = 0; i < arr.size(); i += 5)
	{
		arr.remove( i);
	}
	display(arr);
	CharArray copy;
	for (int i = 97; i < 122; i++)
	{
		copy.add(i);
	}
	cout << "Copy: ";
	display(copy);
	arr = copy;
	cout << "Arr: ";
	display(arr);
}