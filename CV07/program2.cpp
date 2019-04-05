#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	vector<int> a(7);
	vector<int> b;
	cout << "Size of a is: " << a.size() << endl;
	cout << "Size of b is: " << b.size() << endl;
	//cout << "Size of a is: " << sizeof(a) << endl;
	//cout << "Size of b is: " << sizeof(b) << endl;

	int v = a.size();
	for (int i = 0; i < v; i++)
	{
		a[i] = i;
		cout << "a[" << i << "]=" << a[i] << endl;
	}
	cout << "a.at(2)=" << a.at(2) << endl;
	try
	{
		cout << "a.at(2)=" << a.at(20) << endl;
	}
	catch (std::out_of_range &ex)
	{
		cout << ex.what() << endl;
	}
	b = a;
	for (int i = 0; i < v; i++)
	{
		a[i] = i;
		cout << "b[" << i << "]=" << b[i] << endl;
	}
	a.resize(15);
	cout << "Size after resize() is:" << a.size() << endl;
	a.resize(3);
	cout << "Size after resize() is:" << a.size() << endl;

	vector<int> c;
	for (int i = 0; i < 5; i++)
	{
		c.push_back(i + 1);
		cout << "Last element c is:" << c.back() << endl;
	}
	while (!c.empty())
	{
		c.pop_back();
	}
	cout << "Size of c is: " << c.size() << endl;
}