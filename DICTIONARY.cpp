#include "DICTIONARY.h"

DICTIONARY::DICTIONARY(int SIZE)
{
	this->SIZE = SIZE;
	node = new Node * [SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		node[i] = new Node[SIZE];
	}
}

DICTIONARY::~DICTIONARY()
{
	for (int i = 0; i < SIZE; i++)
	{
		delete node[i];
	}
	delete[]node;
}

void DICTIONARY::MAKENULL()
{
	for (int i = 0; i < SIZE; i++)
	{
		node[i] = NULL;
	}
}

bool DICTIONARY::MEMBER(string str)
{
	Node* temp = node[h(str)];
	while (temp != nullptr)
	{
		if (temp->data == str)
			return true;
		temp = temp->next;
	}
	return false;
}

void DICTIONARY::INSERT(string str)
{
	if (!MEMBER(str))
	{
		Node* temp = node[h(str)];
		if (temp->data == "")
			temp->data = str;
		else
		{
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = new Node();
			temp->next->data = str;
		}
	}
}

void DICTIONARY::Delete(string str)
{
	int index = h(str);
	Node* temp = node[index];
	if (MEMBER(str))
	{
		if (temp->data == str)
		{
			node[index] = node[index]->next;
		}
		else
		{
			while (temp->next != nullptr)
			{
				if (temp->next->data == str)
				{
					Node* t = temp->next;
					temp->next = temp->next->next;
					delete t;
					return;
				}
				temp = temp->next;
			}
		}
	}
}

void DICTIONARY::PRINT()
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << "[" << i << "] = ";
		Node* temp = node[i];
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}

int DICTIONARY::h(string str)
{
	int sum = 0;
	for (int i = 0; i < str.length(); i++)
	{
		sum += int(str[i]);
	}
	return sum % SIZE;
}