#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	std::ifstream in("program4.cpp");
	std::ofstream out("program4_copy.cpp");

	if (in.good())
	{
		cout << "Input file was successfully opened." << endl;
		string s;
		while (getline(in, s))
		{
			out << s << endl;
		}
	}
	else
	{
		cout << "Input file cannot be opened!" << endl;
	}
}