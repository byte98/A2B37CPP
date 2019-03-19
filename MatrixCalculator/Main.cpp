#include "Matrix.h"
#include <iostream>
#define EXIT_ERR_INPUT -1;
#define EXIT_ERR_OPERATOR -2;

/* Main program */
int main(int argc, char *argv[])
{
	Matrix NULL_MX = NULL_MATRIX;

	int reti = EXIT_SUCCESS;

	//Load first matrix
	Matrix M1 = NULL_MATRIX;
	M1.loadFromInput();
	if (M1 == NULL_MX)
	{
		reti = EXIT_ERR_INPUT;
	}
	else
	{
		std::cout << "Loaded matrix:" << std::endl;
		M1.write();

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

		//Load second matrix
		Matrix M2 = NULL_MATRIX;
		M2.loadFromInput(M1, matrix_operator);
		std::cout << "Loaded matrix:" << std::endl;
		M2.write();
		if (M2 == NULL_MX)
		{
			reti = EXIT_ERR_INPUT;
		}
		else
		{
			//Perform computing
			Matrix result = NULL_MATRIX;
			switch (matrix_operator)
			{
			case '+':
				break;
			case '-':
				break;
			case '*':
				break;
			default:
				break;
			}

		}
	}

	
	return reti;

}