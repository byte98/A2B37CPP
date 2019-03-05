#include <iostream>

using namespace std;

struct MyStruct
{
	int defvar;

public:
	int a;

private:
	int b;
};

class MyClass
{
	int defvar;

public:
	int a;

	MyClass()
	{
		a = 13;
		b = 37;
	}

	MyClass(int value)
	{
		a = 13;
		b = value;
	}

	~MyClass();


	void setB(int value)
	{
		this->b = value;
	}
	int getB()
	{
		return this->b;
	}


private:
	int b;
};

MyClass::~MyClass()
{
	cout << "MyClass destructed." << endl;
}

/* Main program */
int main(int argc, char *argv[])
{
	MyStruct sa;
	sa.a = 13;
	//Allowed (implicit public)
	sa.defvar = 11;
	cout << "<MyStruct> sa: <int> a:" << sa.a << endl;
	cout << "<MyStruct> sa: <int> a:" << sa.defvar << endl;
	MyClass ca(3);
	/* Not allowed (implicit private)
	ca.defvar = 5;*/
	//ca.setB(3);
	cout << "<MyClass> ca: <int> a: " << ca.a << endl;
	cout << "<MyClass> ca: <int> b: " << ca.getB() << endl;

	MyClass* pta = new MyClass();
	cout << "<*MyClass> pta: <int> a: " << pta->a << endl;
	delete pta;


}