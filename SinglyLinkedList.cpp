// SinglyLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "SinglyLinked.h"

using namespace std;

int main()
{
	
	SinglyLinked<int> myList;
	myList.insert(4);
	myList.insert(1);
	myList.insert(3);
	myList.insert(6);
	myList.insert(8);
	cout << "myList:   " << myList << endl;
	myList.insert(9);
	cout << "myList:   " << myList << endl;

	SinglyLinked<int> newList(myList);
	cout << "newList:  " << newList << endl;

	SinglyLinked<int> revList = myList;

	cout << "newList reversed:  " << newList.reverse() << endl;

	revList.merge(myList);

	cout << "revList Merged:  " << revList << endl;
	cout << "revList front:  " << revList.front() << endl;
	cout << "revList back:  " << revList.back() << endl;

	revList.popBack();

	cout << "revList:  " << revList << endl;

	revList.popFront();

	cout << "revList:  " << revList << endl;
	cout << "revList Size:  " << revList.size() << endl;

}
