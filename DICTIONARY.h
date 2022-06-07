#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Node
{
	Node()
	{
		next = nullptr;
		data = "";
	}
	Node* next;
	string data;
};

class DICTIONARY
{
public:
	DICTIONARY(int SIZE);
	~DICTIONARY();

	void MAKENULL();
	bool MEMBER(string str);
	void INSERT(string str);
	void Delete(string str);

	void PRINT();
private:
	int h(string str);
	int SIZE;
	Node** node;
};