#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char *argv[])
{
	stack<int> stack;
	/*
     | Methods:
	 |  > size() - returns size
	 |  > empty() - returns number: 1 empty, 0 not empty
	 |  > push() - inserts into stack
	 |  > pop() - gets from stack
	 |  > top()  - gets last added item
	 */

	cout << "size: " << stack.size() << endl;
	for (int i = 0; i < 5; i++)
	{
		stack.push('a' + i);
	}
	cout << "size: " << stack.size() << endl;
	cout << "top: " << stack.top() << endl;
	while (!stack.empty())
	{
		cout << "> " << stack.top() << endl;
		stack.pop();
	}
	cout << "size: " << stack.size() << endl;
}