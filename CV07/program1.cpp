#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
	vector <int> A(3);
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);

	for (int i = 0; i < A.size(); i++)
	{
		cout << "A[" << i << "]" << A[i] << endl;
	}

	vector<int>::iterator i; //Not inicialised iterator; Always points to same type as vector v<>
	vector<int>::const_iterator i2 = A.begin();
	//begin() returns iterator to begin of vector
	i = A.begin();
	*i = 33;
	i = i + 3;

	cout << *i << endl;

	//List - both direction list
	list<int> B;
	cout << "----- list ------" << endl;
	for (int j = 0; j < 5; j++)
	{
		B.push_back(j*j);
	}
	for (int j = 1; j < 5; j++)
	{
		B.push_back(j*j*j);
	}
	list<int>::iterator i3 = B.begin();
	for (; i3 != B.end(); i3++)
	{
		cout << *i3 << endl;
	}

	//Map - associative container (structure)
	map<string, int> C;
	C["Ajedna"] = 1;
	C["Bdva"] = 2;
	C["Dctyri"] = 4;
	C["Ctri"] = 3;

	map<string, int>::iterator i4;
	for (i4 = C.begin(); i4 != C.end(); i4++)
	{
		cout << i4->first << "\t" << i4->second << endl;
	}
	
}