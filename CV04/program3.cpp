#include <iostream>

using namespace std;

struct complex
{
	double re;
	double im;
};

complex operator+ (complex a, complex b)
{
	complex reti;
	reti.im = a.im + b.im;
	reti.re = a.re + b.re;

	return reti;
}

ostream & operator<< (ostream &input, complex c)
{
	input << c.re << " + " << c.im << "i";
	return input;
}

int main(int argc, char *argv[])
{
	int reti = 0;

	complex a = { 2.3, 4.8 };
	complex b = { 3.2, 8.4 };
	complex c = a + b;

	cout << c << endl;

	return reti;
}