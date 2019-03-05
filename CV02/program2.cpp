#include <iostream>

using namespace std;

void someFunction(int a)
{
	a = 10;
	cout << "a inside someFunction = " << a << endl;
	cout << "&a inside someFunction = " << &a << endl;
}

void anotherFunction(int *pa)
{
	*pa = 10;
	cout << "a inside someFunction = " << pa << endl;
	cout << "&a inside someFunction = " << &pa << endl;
}




int main(int argc, char *argv[])
{
	int reti = 0;
	int a = 5;
	someFunction(a);
	cout << "a inside main = " << a << endl;
	cout << "&a inside main = " << &a << endl;

	return reti;
}