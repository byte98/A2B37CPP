#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	int reti = 0;
	
	float d[] = { 0.1, 2.0, 5.1, 4.6, 9.1 };
	fstream FILE;
	FILE.open("./data.bin", ios::out | ios::binary);
	FILE.write((char *)d, sizeof(d));
	FILE.close();

	FILE.open("./data.bin", ios::in | ios::binary);
	float e[5];
	FILE.read((char*)e, sizeof(e));
	FILE.close();
	cout << "Output:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;
	cout << "Input:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << e[i] << " ";
	}
	cout << endl;

	/**************************************************************/

	ifstream fin("program1.cpp");
	fin.seekg(0, ios::end); // ios::beg, ios::cur
	int a = fin.tellg();
	cout << "Actual get cursor: " << a << endl;
	char c;
	fin.seekg(0, ios::beg);
	for (int i = 0; i < a; i++)
	{
		fin.get(c);
		if (fin.eof())
		{
			break;
		}
		else
		{
			cout << c;
		}
	}

	fin.close();
	char stop;
	cin >> stop;



	return reti;
}