#include <iostream>

using namespace std;

class fraction
{
	//Overloaded operators +-*/
	friend fraction operator+(fraction f1, fraction f2);
	friend fraction operator-(fraction f1, fraction f2);
	friend fraction operator*(fraction f1, fraction f2);
	friend fraction operator/(fraction f1, fraction f2);
public:
	fraction(int n, int d = 1) : num(n), den(d){};
	fraction(): num(0),den(1){};
	void show(); //Writes fraction to std out
	void get(); //Loads fraction from std in
	double evaluate(); // Computes value of fraction
	void simplify();
private:
	int num;
	int den;
};

fraction operator+ (fraction f1, fraction f2)
{
	fraction reti;
	reti.num = f1.num * f2.den + f2.num * f1.den;
	reti.den = f1.den * f2.den;
	return reti;
}
fraction operator- (fraction f1, fraction f2)
{
	fraction reti;
	reti.num = f1.num * f2.den - f2.num * f1.den;
	reti.den = f1.den * f2.den;
	return reti;
}
fraction operator* (fraction f1, fraction f2)
{
	fraction reti;
	reti.num = f1.num * f2.num;
	reti.den = f1.den * f2.den;
	return reti;
}

fraction operator/ (fraction f1, fraction f2)
{
	fraction reti;
	reti.num = f1.num * f2.den;
	reti.den = f1.den * f2.num;
	return reti;
}


void fraction::show()
{
	cout << num << "/" << den;
}

void fraction::get()
{
	char div_sign; //Hope it is slash
	cin >> num >> div_sign >> den;
}

double fraction::evaluate()
{
	double n = num;
	double d = den;
	return n / d;
}

void fraction::simplify()
{
	int n = num;
	int d = den;
	while (n != d)
	{
		if (n > d)
		{
			n -= d;
		}
		else
		{
			d -= n;
		}
	}
	if (n > 1)
	{
		num = num / n;
		den = den / n;
	}

}

int main(int argc, char *argv[])
{
	//4 constructors
	fraction f1(3, 2), f2(4), f3(0, 1), f4(0, 1), f5(0, 1), f6(0, 1), f7(0, 1);

	//View created fractions
	cout << "f1 = ";
	f1.show();
	cout << endl;

	cout << "f2 = ";
	f2.show();
	cout << endl;

	cout << "f3 = ";
	f3.show();
	cout << endl;

	cout << "f4 = ";
	f4.show();
	cout << endl;

	// Entering own fraction
	cout << "Enter your fraction: " << endl;
	f3.get();
	cout << "You entered: " << endl;
	cout << "f3 = ";
	f3.show();
	cout << endl;

	//Operations test
	f4 = f1 + f3;
	cout << "f4 = f1 + f3 = ";
	f4.show();
	cout << endl;

	f5 = f1 - f3;
	cout << "f5 = f1 - f3 = ";
	f5.show();
	cout << endl;

	f6 = f1 * f3;
	cout << "f6 = f1 * f3 = ";
	f6.show();
	cout << endl;

	f7 = f1 / f3;
	cout << "f7 = f1 / f3 = ";
	f7.show();
	cout << endl;

	//Simplify test
	f4.simplify();
	cout << "f4 = ";
	f4.show();
	cout << endl;

	//Eval test
	cout << "f4 = ";
	cout << f4.evaluate();
	cout << endl;

	return 0;
}