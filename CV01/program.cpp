
#include <iostream>
namespace cpp
{
	int a;
	int b;
}

using namespace std;
using namespace cpp;

/* Main program */
int main(int argc, char *argv[])
{
	int reti = 0;

	cout << "Hello world!" << endl;
	int a = 1;

	cpp::a = 5;
	cpp::b = 3;

	cout << "cpp::a: " << cpp::a << endl;
	cout << "std::a: " << a << endl;
	cout << "cpp::b: " << cpp::b << endl;

	cout << "a+b: " << a + b << endl;
	cout << "a<<b: " << (a << b) << endl;

	cout << "Insert integer: ";
	cin >> a;
	if (cin.good())
	{
		cout << "a: " << a << endl;
	}
	else
	{
		cout << "Wrong input!" << endl;
	}



	return reti;
}