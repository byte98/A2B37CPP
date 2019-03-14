#include "Matrix.h"
#include <iostream>
#define EXIT_ERR_INPUT -1;

/* Main program */
int main(int argc, char *argv[])
{
	int reti = EXIT_SUCCESS;

	//Load first matrix
	Matrix M1 = Matrix::loadFromInput();
	while (M1 == ERR_MATRIX)
	{
		Matrix M1 = Matrix::loadFromInput();
		std::cout << "Wrong matrix loaded!" << std::endl;
	}

	//Load operator
	bool correct = false;
	char matrix_operator;
	while (!correct)
	{
		std::cin >> matrix_operator;
		if (!std::cin.good())
		{
			std::cout << "Wrong operator! Allowed operators: '+', '-', '*'." << std::endl;
		}
		else
		{
			switch (matrix_operator)
			{
			case '+':
				correct = true;
				break;
			case '-':
				correct = true;
				break;
			case '*':
				correct = true;
				break;
			default:
				std::cout << "Wrong operator! Allowed operators: '+', '-', '*'." << std::endl;
				break;
			}
		}
	}


}