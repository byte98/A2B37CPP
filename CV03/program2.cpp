#include <iostream>

using namespace std;

class ClassA
{
private:
	int a, b, c;

public:
	ClassA(int x = 1, int y = 2, int z = 3) :a(x) , b(y) , c(z) {};
	void print();

	static double pi()
	{
		return 3.14159265359;
	}
};

class ClassB :public ClassA
{
private: 
	int d;
public:
	ClassB() :ClassA(13, 26, 39) { d = 52; };
	void print()
	{
		cout << "<ClassB> ";
		ClassA::print();
	}
};

void ClassA::print()
{
	cout << "<ClassA> a: " << this->a << "; b: " << this->b << "; c:" << this->c << endl;
}

int main(int argc, char *argv[])
{
	int reti = 0;
	ClassA cA = ClassA(10, 20);
	cA.print();

	ClassB cB = ClassB();
	cB.print();

	cout << "pi: " << ClassA::pi() << endl;

	return reti;
}