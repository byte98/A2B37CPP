#include "Matrix.h"
#include <iostream>
#include <limits>

//Space allocation
void Matrix::allocateSpace()
{
	int** space = new int*[this->rows];
	for (int i = 0; i < this->rows; ++i)
	{
		space[i] = new int[this->cols];
	}
	this->data = space;
}


//Space free
void Matrix::freeSpace()
{
	if (this->rows > 0 && this->cols > 0)
	{

		for (int i = 0; i < this->rows; i++)
		{
			delete[](this->data[i]);
		}
		delete[](this->data);
	}
}


//Constructor
Matrix::Matrix(int rows, int cols, bool transpose = false)
{
	this->cols = cols;
	this->rows = rows;
	this->transposition = transpose;
	if (this->rows > 0 && this->cols > 0)
	{
		this->allocateSpace();
	}

}


//Destructor
Matrix::~Matrix()
{
	this->freeSpace();
}


//Add value to position in matrix
bool Matrix::addToMatrix(int row, int col, int value)
{
	bool reti = (row <= this->rows && col <= this->cols);
	if (reti)
	{
		this->data[row][col] = value;
	}
	return reti;
}


//Transpose matrix
Matrix Matrix::transpose()
{
	Matrix reti = Matrix(this->rows, this->cols);
	for (int r = 0; r < this->rows; r++)
	{
		for (int c = 0; c < this->cols; c++)
		{
			reti.addToMatrix(c, r, this->data[r][c]);
		}
	}
	return reti;
}


//Print values in matrix
void Matrix::write()
{
	for (int r = 0; r < this->rows; r++)
	{
		for (int c = 0; c < this->cols; c++)
		{
			printf("%3i", this->data[r][c]);
		}
		std::cout << std::endl;
	}
}


//Load matrix from input
Matrix Matrix::loadFromInput()
{
	//TODO: Something bad is hapenning here
	
	Matrix reti = ERR_MATRIX;

	//Read data of matrix
	int rows, cols;

	//Rows
	std::cin >> rows;
	if (!std::cin.good())
	{
		std::cout << "Wrong input!" << std::endl;
		return ERR_MATRIX;
	}

	//Columns
	std::cin >> cols;
	if (!std::cin.good())
	{
		std::cout << "Wrong input!" << std::endl;
		return ERR_MATRIX;
	}

	//Transpose?
	char input = 'n';
	std::scanf("%c", &input);
	while (input != '\n' && input == ' ')
	{
		std::scanf("%c", &input);
	}
	bool transpose = (input == 't');

	return reti;
}

//Load matrix from input due to conditions
Matrix Matrix::loadFromInput(Matrix first, char matrix_operator)
{
	//TODO: Continue here
}

//Are matrices same?
bool Matrix::operator == (Matrix a)
{
	bool reti = true;
	if (a.cols == this->cols && a.rows == this->rows)
	{
		if (this->cols > 0 && this->rows > 0)
		{
			for (int r = 0; r < this->rows; r++)
			{
				for (int c = 0; c < this->cols; c++)
				{
					if (a.data[r][c] != this->data[r][c])
					{
						reti = false;
						break;
					}
				}
			}
		}
	}
	else
	{
		reti = false;
	}

	return reti;
}

//Get count of rows
int Matrix::getRows()
{
	return this->rows;
}

//Get count of cols
int Matrix::getCols()
{
	return this->cols;
}