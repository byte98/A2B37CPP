#pragma once
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
/// <summary>
/// Matrix class definition
/// </summary>


/// <summary>
/// Struct to store information about matrix
/// </summary>
struct matrix_header
{
public:
	/// <summary>
	/// Rows in matrix
	/// </summary>
	int rows;

	/// <summary>
	/// Columns in matrix
	/// </summary>
	int cols;

	/// <summary>
	/// Should be matrix transposed?
	/// </summary>
	bool transpose;
};


/// <summary>
/// Class to provide basic matrix calculus
/// </summary>
class Matrix
{
private:
	/// <summary>
	/// Information about dimensions of matrix
	/// </summary>
	matrix_header dimensions;

	/// <summary>
	/// Values of matrix
	/// </summary>
	double** data;

	/// <summary>
	/// Computes one member of matrix after multiplying
	/// </summary>
	/// <param name="row">Row position of member</param>
	/// <param name="M1">First matrix</param>
	/// <param name="col">Column position of member</param>
	/// <param name="M2">Second matrix</param>
	/// <returns>Computed value for set position</returns>
	int getMultiplySubresult(int row, int col, Matrix &M2);

	/// <summary>
	/// Frees space used by matrix data
	/// </summary>
	void deleteData();
public:
	Matrix() {}
	/// <summary>
	/// Constructor of matrix
	/// </summary>
	/// <param name="header">Information about dimensions of matrix</param>
	Matrix(matrix_header header);

	///<summary>
	/// Deletes space used by matrix
	///</summary>
	~Matrix();

	/// <summary>
	/// Adds value to matrix at set position
	/// </summary>
	/// <param name="row">Row to add data</param>
	/// <param name="col">Columns to add data</param>
	/// <param name="value">Value to be added</param>
	/// <returns>0 if it was successfull, something different if not</returns>
	int addData(int row, int col, double value);

	/// <summary>
	/// Gets dimension of matrix
	/// </summary>
	/// <returns>Dimensions of matrix</returns>
	matrix_header getDimensions();

	/// <summary>
	/// Gets values stored in matrix
	/// </summary>
	/// <returns>Values stored in matrix</returns>
	double** getData(void);

	/// <summary>
	/// Defines operation of addition on matrices
	/// </summary>
	/// <param name="obj">Matrix to be added by</param>
	/// <returns>Matrix added by another matrix</returns>
	Matrix operator + (Matrix const & obj);

	/// <summary>
	/// Defines operation of substraction on matrices
	/// </summary>
	/// <param name="obj">Matrix to be substracted by</param>
	/// <returns>Matrix substracted by another matrix</returns>
	Matrix operator - (Matrix const & obj);

	/// <summary>
	/// Defines operation of multiplication between matrices
	/// </summary>
	/// <param name="obj">Matrix to be multiplied by</param>
	/// <returns>Matrix multiplied by another matrix</returns>
	Matrix operator * (Matrix const & obj);



	/// <summary>
	/// Transposes matrix
	/// </summary>
	void transpose();

	/// <summary>
	/// Print matrix values on standart output
	/// </summary>
	void write();

	
static
	/// <summary>
	/// Function to check, if loaded dimensions are right according to loaded operation
	/// </summary>
	/// <param name="M1">First loaded matrix</param>
	/// <param name="M2">Second loaded matrix</param>
	/// <param name="operation">Loaded operation</param>
	/// <returns>0 if dimensions are correct, false if not</returns>
	int checkOperation(matrix_header M1, matrix_header M2, char operation);

static
	///<summary>
	/// Function to provide Hadramard product computing
	///</summary>
	///<param name="M1">First matrix to compute Hadramard product from</param>
	///<param name="M2">Second matrix to compute Hadramard product from</param>
	///<returns>Matrix computed by Hadramard product of two matrices</returns>
	Matrix HadramardProduct(Matrix const & M1, Matrix const & M2);

static
	///<summary>
	/// Function to provide Kronecker product computing
	///</summary>
	///<param name="M1">First matrix to compute Kronecker product from</param>
	///<param name="M2">Second matrix to compute Kronecker product from</param>
	///<returns>Matrix computed by Kronecker product of two matrices</returns>
	Matrix KroneckerProduct(Matrix const & M1, Matrix const & M2);

};