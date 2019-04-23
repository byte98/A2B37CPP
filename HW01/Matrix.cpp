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



#include "matrix.h"
#include "errors.h"
#include "operations.h"
#include <iostream>


Matrix::Matrix(matrix_header header)
{
	this->dimensions = header;
	this->data = new double*[this->dimensions.rows];
	for (int i = 0; i < this->dimensions.rows; i++)
	{
		this->data[i] = new double[this->dimensions.cols];
	}
}

//---------------------------------------------------------------------------------------------------

Matrix::~Matrix()
{
	//this->deleteData();
}

//---------------------------------------------------------------------------------------------------

int Matrix::addData(int row, int col, double value)
{
	int reti = OK;
	if (row > this->dimensions.rows)
	{
		reti = ERR_DATA_ADDRL;
	}
	else if (row < 0)
	{
		reti = ERR_DATA_ADDRS;
	}
	else if (col > this->dimensions.cols)
	{
		reti = ERR_DATA_ADDCL;
	}
	else if (col < 0)
	{
		reti = ERR_DATA_ADDCS;
	}

	if (GOOD(reti))
	{
		this->data[row][col] = value;
	}

	return reti;
}

//---------------------------------------------------------------------------------------------------

int Matrix::checkOperation(matrix_header M1, matrix_header M2, char operation)
{
	int reti = OK;

	int R1, R2, C1, C2;
	R1 = (M1.transpose ? M1.cols : M1.rows);
	C1 = (M1.transpose ? M1.rows : M1.cols);
	R2 = (M2.transpose ? M2.cols : M2.rows);
	C2 = (M2.transpose ? M2.rows : M2.cols);

	if (operation == ADDITION || operation == SUBSTRACTION)
	{
		if (R1 != R2)
		{
			if (R2 != 1)
			{
				reti = ERR_IN_SMORA;
			}
		}
		else if (C1 != C2)
		{
			if (R2 == 1 && C2 != 1)
			{
				reti = ERR_IN_SMOCA;
			}
		}
	}
	else if (operation == MULTIPLICATION)
	{
		if (R1 != C2)
		{
			if (C2 != 1)
			{
				reti = ERR_IN_SMOCM;
			}
		}
		else if (C1 != R2)
		{
			if (C2 == 1 && R2 != 1)
			{
				reti = ERR_IN_SMORM;
			}
		}
	}
	else if (operation == HADRAMARD)
	{
		if (R1 != R2)
		{
			if (R2 != 1)
			{
				reti = ERR_IN_SMORH;
			}
		}
		else if (C1 != C2)
		{
			if (R2 == 1 && C2 != 1)
			{
				reti = ERR_IN_SMOCH;
			}
		}
	}
	else if (operation == KRONECKER)
	{
		if (R1 <= 0)
		{
			reti = ERR_IN_FMORK;
		}
		else if (C1 <= 0)
		{
			reti = ERR_IN_FMOCK;
		}
		else if (R2 <= 0)
		{
			reti = ERR_IN_SMORK;
		}
		else if (C2 <= 0)
		{
			reti = ERR_IN_SMOCK;
		}
	}

	return reti;
}

//---------------------------------------------------------------------------------------------------

matrix_header Matrix::getDimensions()
{
	return this->dimensions;
}

//---------------------------------------------------------------------------------------------------

Matrix Matrix::operator + (Matrix const & obj)
{
	Matrix M2 = obj;
	matrix_header M2_dim = M2.getDimensions();
	Matrix reti = Matrix(this->getDimensions());
	if (!(M2_dim.rows == 1 && M2_dim.cols == 1))
	{
		for (int r = 0; r < M2_dim.rows; r++)
		{
			for (int c = 0; c < M2_dim.cols; c++)
			{
				reti.addData(r, c, (this->data[r][c] + M2.getData()[r][c]));
			}
		}
	}
	else
	{
		int val = M2.getData()[0][0];
		for (int r = 0; r < this->getDimensions().rows; r++)
		{
			for (int c = 0; c < this->getDimensions().cols; c++)
			{
				reti.addData(r, c, (this->data[r][c] + val));
			}
		}
	}
	return reti;
}

//---------------------------------------------------------------------------------------------------

Matrix Matrix::operator - (Matrix const & obj)
{
	Matrix M2 = obj;
	matrix_header M2_dim = M2.getDimensions();
	Matrix reti = Matrix(this->getDimensions());
	if (!(M2_dim.rows == 1 && M2_dim.cols == 1))
	{
		for (int r = 0; r < M2_dim.rows; r++)
		{
			for (int c = 0; c < M2_dim.cols; c++)
			{
				reti.addData(r, c, (this->data[r][c] - M2.data[r][c]));
			}
		}
	}
	else
	{
		for (int r = 0; r < this->getDimensions().rows; r++)
		{
			for (int c = 0; c < this->getDimensions().cols; c++)
			{
				reti.addData(r, c, (this->data[r][c] - M2.data[0][0]));
			}
		}
	}
	return reti;
}

//---------------------------------------------------------------------------------------------------

Matrix Matrix::operator * (Matrix const & obj)
{
	Matrix M2 = obj;
	int r = ((M2.dimensions.rows == 1 && M2.dimensions.cols == 1) ? this->dimensions.rows : M2.dimensions.cols);
	int c = ((M2.dimensions.rows == 1 && M2.dimensions.cols == 1) ? this->dimensions.cols : M2.dimensions.rows);
	matrix_header reti_dim;
	reti_dim.rows = r;
	reti_dim.cols = c;
	reti_dim.transpose = false;
	Matrix reti = Matrix(reti_dim);
	if (!(M2.getDimensions().rows == 1 && M2.getDimensions().cols == 1))
	{
		for (int row = 0; row < r; row++)
		{
			for (int col = 0; col < c; col++)
			{
				reti.addData(row, col, this->getMultiplySubresult(row, col, M2));
			}
		}
	}
	else
	{
		for (int row = 0; row < r; row++)
		{
			for (int col = 0; col < c; col++)
			{
				reti.addData(row, col, this->getData()[row][col] * M2.getData()[0][0]);
			}
		}
	}
	return reti;
}

//---------------------------------------------------------------------------------------------------

void Matrix::transpose()
{
	double ** values = new double*[this->dimensions.cols];
	for (int i = 0; i < this->dimensions.cols; i++)
	{
		values[i] = new double[this->dimensions.rows];
	}
	for (int r = 0; r < this->dimensions.rows; r++)
	{
		for (int c = 0; c < this->dimensions.cols; c++)
		{
			values[c][r] = this->data[r][c];
		}
	}
	this->deleteData();
	int rows = this->dimensions.cols;
	this->dimensions.cols = this->dimensions.rows;
	this->dimensions.rows = rows;
	this->data = values;
}

//---------------------------------------------------------------------------------------------------

int Matrix::getMultiplySubresult(int row, int col, Matrix& M2)
{
	int reti = 0;
	int r = 0;
	int c = 0;
	while (c < this->getDimensions().cols && r < M2.getDimensions().rows)
	{
		reti += (this->getData()[row][c] * M2.getData()[r][col]);
		r++;
		c++;
	}
	return reti;
}

//---------------------------------------------------------------------------------------------------

double ** Matrix::getData()
{
	return this->data;
}

//---------------------------------------------------------------------------------------------------

void Matrix::write()
{
	for (int r = 0; r < this->dimensions.rows; r++)
	{
		for (int c = 0; c < this->dimensions.cols; c++)
		{
			std::printf("%3.2f ", this->data[r][c]);
		}
		std::cout << std::endl;
	}
}

//---------------------------------------------------------------------------------------------------

Matrix Matrix::HadramardProduct(const Matrix & M1, const Matrix & M2)
{
	Matrix m1 = M1;
	Matrix m2 = M2;
	Matrix reti;
	int state = OK;
	if (m2.getDimensions().rows == 1 && m2.getDimensions().cols == 1)
	{
		reti = m1 * m2;
	}
	else
	{
		matrix_header dim = m1.getDimensions();
		reti = Matrix(dim);
		for (int r = 0; r < m1.getDimensions().rows; r++)
		{
			for (int c = 0; c < m1.getDimensions().cols; c++)
			{
				state = reti.addData(r, c, (m1.getData()[r][c] * m2.getData()[r][c]));
				if (GOOD(state) == false)
				{
					break;
				}
			}
			if (GOOD(state) == false)
			{
				break;
			}
		}
	}
	return reti;
}

//---------------------------------------------------------------------------------------------------

Matrix Matrix::KroneckerProduct(Matrix const & M1, Matrix const & M2)
{
	Matrix m1 = M1;
	Matrix m2 = M2;
	matrix_header dimensions;
	dimensions.rows = m1.getDimensions().rows * m2.getDimensions().rows;
	dimensions.cols = m1.getDimensions().cols * m2.getDimensions().cols;
	dimensions.transpose = false;
	Matrix reti = Matrix(dimensions);
	int row = 0;
	int col = 0;
	for (int r = 0; r < m1.getDimensions().rows; r++)
	{
		for (int c = 0; c < m1.getDimensions().cols; c++)
		{
			matrix_header multi_h;
			multi_h.cols = 1;
			multi_h.rows = 1;
			multi_h.transpose = false;
			Matrix multiplier = Matrix(multi_h);
			multiplier.addData(0, 0, m1.getData()[r][c]);
			Matrix submatrix = m2 * multiplier;
			for (int rs = 0; rs < submatrix.getDimensions().rows; rs++)
			{
				for (int cs = 0; cs < submatrix.getDimensions().cols; cs++)
				{
					reti.addData(r * m2.getDimensions().rows + rs, c * m2.getDimensions().cols + cs, submatrix.getData()[rs][cs]);
				}
			}
		}
	}
	return reti;
}

//---------------------------------------------------------------------------------------------------

void Matrix::deleteData()
{
	for (int r = 0; r < this->dimensions.rows; r++)
	{
		delete[] this->data[r];
	}
	delete[] this->data;
}