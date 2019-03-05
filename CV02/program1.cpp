#include <iostream>
#include <iomanip>

using namespace std;

int main(int agrc, char *argv[])
{
	int reti = 0;
	float phi = 3.14159265358979323846264338327950288419716939937510;
	std::cout << "Hello c++" << endl;
	cout << "Default precision" << endl;
	std::cout << "pi=" << phi << endl;

	std::cout << setprecision(2);

	std::cout << "Precison changed to 2" << endl;
	std::cout << "pi=" << phi << endl;

	cout << fixed;
	cout << "Fixed" << endl;
	std::cout << "pi=" << phi << endl;

	cout << scientific;
	cout << "Scientific" << endl;
	std::cout << "pi=" << phi << endl;

	//Reset to default
	cout.unsetf(ios_base::floatfield);
	cout << "Default again" << endl;
	std::cout << "pi=" << phi << endl;


	cout << "Spaces" << endl;
	cout << setw(5);
	cout << "pi=" << phi << endl;


	return reti;
}