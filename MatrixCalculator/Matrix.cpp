#include "Matrix.h"
#include <iostream>
#include <limits>

#ifdef _WIN32
#pragma warning(disable : 4996) //Disable Microsoft Visual C++ compiler to warn about using "not secure" functions (like scanf)
#endif // _WIN32

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
		this->setValue(INT16_MIN);
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
void Matrix::loadFromInput()
{
	int rows, cols;
	bool transpose;

	//Rows
	std::cin >> rows;
	while (std::cin.good() == false)
	{
		std::cout << "Wrong input! Number of rows must be an integer." << std::endl << "Enter number of rows:" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> rows;
	}

	//Cols
	std::cin >> cols;
	while (std::cin.good() == false)
	{
		std::cout << "Wrong input! Number of columns must be an integer." << std::endl << "Enter number of columns:" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> cols;
	}

	//Transpose?
	char input = 'n';
	std::scanf("%c", &input);
	while (input != '\n' && input == ' ')
	{
		std::scanf("%c", &input);
	}
	transpose = (input == 't');

	this->transposition = transpose;
	this->rows = rows;
	this->cols = cols;
	this->allocateSpace();

#ifdef _DEBUG
	std::cout << "% Loaded attributes of matrix: rows=" << rows << "; cols=" << cols << "; transpose=" << (transpose ? "true" : "false") << std::endl;
#endif // _DEBUG


	//Load data
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			int value;
			std::cin >> value;
			while (std::cin.good() == false)
			{
				std::cout << "Wrong input! Values in matrix must be integers only." << std::endl << "Enter value:" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> cols;
			}
			this->data[r][c] = value;
		}
	}

}

//Load matrix from input due to conditions of operator
void Matrix::loadFromInput(Matrix first, char matrix_operator)
{
	int rows, cols;
	bool transpose;

	//Rows
	std::cin >> rows;

	//Addition/substraction condition
	bool add_sub_c = ((matrix_operator == '+' || matrix_operator == '-') && (rows == first.getRows() || rows == 1));

	//Multiplication condition
	bool multi_c = (matrix_operator == '*' && (rows == first.getCols() || rows == 1));

	while ((std::cin.good() == false && add_sub_c == false && multi_c == false))
	{
		if (std::cin.good() == false)
		{
			std::cout << "Wrong input! Number of rows must be an integer." << std::endl << "Enter number of rows:" << std::endl;
		}
		else if (add_sub_c == false && (matrix_operator == '+' || matrix_operator == '-'))
		{
			std::cout << "Wrong input! Number of rows must be " << first.getCols() << " or 1." << std::endl << "Enter number of rows:" << std::endl;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> rows;
		add_sub_c = ((matrix_operator == '+' || matrix_operator == '-') && (rows == first.getRows() || rows == 1));
		multi_c = (matrix_operator == '*' && (rows == first.getCols() || rows == 1));
	}

	//Cols
	std::cin >> cols;
	while (std::cin.good() == false)
	{
		std::cout << "Wrong input! Number of columns must be an integer." << std::endl << "Enter number of columns:" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> cols;
	}

	//Transpose?
	char input = 'n';
	std::scanf("%c", &input);
	while (input != '\n' && input == ' ')
	{
		std::scanf("%c", &input);
	}
	transpose = (input == 't');

	this->transposition = transpose;
	this->rows = rows;
	this->cols = cols;
	this->allocateSpace();

	//Load data
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			int value;
			std::cin >> value;
			while (std::cin.good() == false)
			{
				std::cout << "Wrong input! Values in matrix must be integers only." << std::endl << "Enter value:" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> cols;
			}
			this->data[r][c] = value;
		}
	}
}

//Are matrices same?
bool Matrix::operator == (Matrix &a)
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

//Are matrices different?
bool Matrix::operator != (Matrix &a)
{
	bool reti = false;
	if (a.cols == this->cols && a.rows != this->rows)
	{
		if (this->cols > 0 && this->rows > 0)
		{
			for (int r = 0; r < this->rows; r++)
			{
				for (int c = 0; c < this->cols; c++)
				{
					if (a.data[r][c] != this->data[r][c])
					{
						reti = true;
						break;
					}
				}
			}
		}
	}
	else
	{
		reti = true;
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

//Set same value
void Matrix::setValue(int value)
{
	for (int r = 0; r < this->rows; r++)
	{
		for (int c = 0; c < this->cols; c++)
		{
			this->data[r][c] = value;
		}
	}
}