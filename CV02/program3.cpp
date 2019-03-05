#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	std::ifstream file;
	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		file.open("neexistujici soubor");
	}
	catch (std::ifstream::failure exep)
	{
		std::cout << "I/O Error" << std::endl;
		std::cout << exep.what() << std::endl;
	}

}