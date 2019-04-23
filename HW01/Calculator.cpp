/*
 * Copyright 2019 Jiri Skoda<skodaji4@fel.cvut.cz>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#include <iostream>
#include "calculator.h"
#include "errors.h"
#include "matrix.h"
#include "operations.h"
#include <algorithm>

#define _CRT_SECURE_NO_WARNINGS

Calculator::Calculator()
{
}

//---------------------------------------------------------------------------------------------------

Calculator::~Calculator()
{
}

//---------------------------------------------------------------------------------------------------

int Calculator::run()
{
	int reti = OK;
	reti = this->loadFirstMatrix();
	if (GOOD(reti))
	{
		char operations[] = {ADDITION, SUBSTRACTION, MULTIPLICATION, HADRAMARD, KRONECKER};
		char input;
		std::cin >> input;
		if (std::cin.good() == false)
		{
			reti = ERR_IN_OLF;
		}

		if (GOOD(reti))
		{
			char *op = std::find(std::begin(operations), std::end(operations), input);
			if (op != std::end(operations))
			{
				this->operation = input;
			}
			else
			{
				reti = ERR_IN_ONA;
			}
		}
	}
	if (GOOD(reti))
	{
		reti = this->loadSecondMatrix();
	}
	if (GOOD(reti))
	{
		std::cout << std::endl;
		Matrix M;
		if (this->M1->getDimensions().transpose)
		{
			this->M1->transpose();
		}
		if (this->M2->getDimensions().transpose)
		{
			this->M2->transpose();
		}
		switch (this->operation)
		{
		case ADDITION:
			M = *this->M1 + *this->M2;
			break;
		case SUBSTRACTION:
			M = *this->M1 - *this->M2;
			break;
		case MULTIPLICATION:
			M = *this->M1 * *this->M2;
			break;
		case HADRAMARD:
			M = Matrix::HadramardProduct(*this->M1, *this->M2);
			break;
		case KRONECKER:
			M = Matrix::KroneckerProduct(*this->M1, *this->M2);
			break;
		default:
			reti = ERR_IN_ONA;
			break;
		}
		if (GOOD(reti))
		{
			std::cout << "=======================" << std::endl;
			M.write();
		}
	}

	return reti;
}

//---------------------------------------------------------------------------------------------------

int Calculator::loadFirstMatrix()
{
	int reti = OK;
	//Load information about first matrix
	matrix_header M1_header;
	int rows, cols;
	bool transpose;
	//Rows
	std::cin >> rows;
	reti = (std::cin.good() ? OK : ERR_IN_FMR);
	if (GOOD(reti))
	{
		//Cols
		std::cin >> cols;
		reti = (std::cin.good() ? OK : ERR_IN_FMC);
	}

	if (GOOD(reti))
	{
		//Transpose?
		char input = 'n';
		std::scanf("%c", &input);
		while (input != '\n' && input == ' ')
		{
			std::scanf("%c", &input);
		}
		transpose = (input == 't');
		M1_header.cols = cols;
		M1_header.rows = rows;
		M1_header.transpose = transpose;
		this->M1 = new Matrix(M1_header);

		//Load data
		for (int r = 0; r < M1_header.rows; r++)
		{
			for (int c = 0; c < M1_header.cols; c++)
			{
				double val;
				std::cin >> val;
				if (std::cin.good() == false)
				{
					reti = ERR_IN_FMD;
					break;
				}
				reti = this->M1->addData(r, c, val);
				if (GOOD(reti) == false)
				{
					break;
				}
			}
			if (GOOD(reti) == false)
			{
				break;
			}
		}
	}

	return reti;
}

//---------------------------------------------------------------------------------------------------

int Calculator::loadSecondMatrix()
{
	int reti = OK;
	//Load information about first matrix
	matrix_header M2_header;
	int rows, cols;
	bool transpose;
	//Rows
	std::cin >> rows;
	reti = (std::cin.good() ? OK : ERR_IN_FMR);
	if (GOOD(reti))
	{
		//Cols
		std::cin >> cols;
		reti = (std::cin.good() ? OK : ERR_IN_FMC);
	}

	if (GOOD(reti))
	{
		//Transpose?
		char input = 'n';
		std::scanf("%c", &input);
		while (input != '\n' && input == ' ')
		{
			std::scanf("%c", &input);
		}
		transpose = (input == 't');
		M2_header.cols = cols;
		M2_header.rows = rows;
		M2_header.transpose = transpose;

		reti = Matrix::checkOperation(this->M1->getDimensions(), M2_header, this->operation);
		if (GOOD(reti))
		{
			this->M2 = new Matrix(M2_header);

			//Load data
			for (int r = 0; r < M2_header.rows; r++)
			{
				for (int c = 0; c < M2_header.cols; c++)
				{
					double val;
					std::cin >> val;
					if (std::cin.good() == false)
					{
						reti = ERR_IN_FMD;
						break;
					}
					reti = this->M2->addData(r, c, val);
					if (GOOD(reti) == false)
					{
						break;
					}
				}
				if (GOOD(reti) == false)
				{
					break;
				}
			}
		}
	}

	return reti;
}