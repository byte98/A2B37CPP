#include <iostream>
#include <limits.h>

using namespace std;

class Stack
{
private:
	int size;
	int items;
	int *data;

public:
	Stack(int depth = 10)
	{
		this->size = depth;
		this->data = new int[this->size];
		this->items = 0;
	}

	~Stack()
	{
		delete[] this->data;
	}

	bool push(int item)
	{
		bool reti = items < size;
		if (reti)
		{
			this->data[items] = item;
			this->items++;
		}

		return reti;
	}

	int pop()
	{
		int reti = 0;
		if (items > 0)
		{
			reti = this->data[(this->items - 1)];
			this->items--;
		}
		else
		{
			throw new EmptyStack(this->items);
		}
		return reti;
	}

	class EmptyStack
	{
	public:
		int index;
		EmptyStack(int i) :index(i) {};

	};
};

int main(int argc, char *argv[])
{
	int reti = 0;

	Stack s = Stack();
	s.push(1);
	s.push(2);
	s.push(3);
	cout << "Pop: " << s.pop() << endl;
	cout << "Pop: " << s.pop() << endl;
	cout << "Pop: " << s.pop() << endl;
	try
	{
		cout << "Pop: " << s.pop() << endl;
	}
	catch (Stack::EmptyStack &exception)
	{
		cerr << "Error! Popping from empty stack!" << endl;
		cerr << "       Index " << exception.index << " is too small." << endl;
	}

	return reti;
}