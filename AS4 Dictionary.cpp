#include "DICTIONARY.h"

int main()
{
	const int SIZE = 15;
	DICTIONARY test(SIZE);
	string t;
	cout << "Input:" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << i + 1 << " - ";
		getline(cin, t);
		test.INSERT(t);
	}
	cout << "Print:" << endl;
	test.PRINT();
	cout << endl << "Delete: ";
	getline(cin, t);
	test.Delete(t);
	cout << endl << "Print:" << endl;
	test.PRINT();
	test.MAKENULL();
	cout << endl << "MakeNull:" << endl;
	test.PRINT();
	return 0;
}