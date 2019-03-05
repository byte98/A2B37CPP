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
		int reti = INT32_MIN;
		if (items > 0)
		{
			reti = this->data[(this->items - 1)];
			this->items--;
		}
		return reti;
	}
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
	cout << "Pop: " << s.pop() << endl;

	return reti;
}