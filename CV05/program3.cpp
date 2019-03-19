#include <iostream>

using namespace std;

class A
{
private:
	int aa;
public:
	A(int h)
	{
		this->aa = h;
		cout << "(i) Class A instanced." << endl;
	}
	~A()
	{
		cout << "(i) Instance of class A destructed." << endl;
	}

	void fA()
	{
		cout << "(i) fA()" << endl;
	}
};

class B : virtual public A
{
private:
	int bb;
public:
	B(int h):A(h)
	{
		this->bb = h;
		cout << "(i) Class B instanced." << endl;
	}
	~B()
	{
		cout << "(i) Instance of class B destructed." << endl;
	}
	void fB()
	{
		cout << "(i) fB()" << endl;
	}
};

class C : virtual public A
{
private:
	int cc;
public:
	C(int h):A(h)
	{
		this->cc = h;
		cout << "(i) Class C instanced." << endl;
	}
	~C()
	{
		cout << "(i) Instance of class C destructed." << endl;
	}
	void fC()
	{
		cout << "(i) fC()" << endl;
	}
};

class D: public B, public C
{
private:
	int dd;
public:
	D(int h):C(h+2), B(h+1), A(h+3)
	{
		this->dd = h;
		cout << "(i) Class D instanced." << endl;
	}
	~D()
	{
		cout << "(i) Instance of class D destructed." << endl;
	}
	void fD()
	{
		cout << "(i) fD()" << endl;
	}
};

int main(int argc, char*argv[])
{
	int reti = 0;

	D d1 = 100;
	d1.fA();
	d1.fB();
	d1.fC();
	d1.fD();
	return reti;
}