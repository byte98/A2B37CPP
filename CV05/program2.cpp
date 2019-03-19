#include <iostream>

using namespace std;

class B;

class A
{
public:
	void showB(B &);
};

class B
{
private:
	int b;
public:
	B()
	{
		this->b = 13;
	}
	friend void A::showB(B& x); //Friend function
};

void A::showB(B& x)
{
	std::cout << "B::b=" << x.b << std::endl;
};

int main(int argc, char *argv[])
{
	int reti = 0;
	A a;
	B x;
	a.showB(x);
	return reti;
}