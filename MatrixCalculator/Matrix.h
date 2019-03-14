#ifndef __MATRIX_H__
#define __MATRIX_H__

#define ERR_MATRIX Matrix(-1,-1, false)
#define ERR_MATRIX_OPERATOR Matrix(-2, -2, false);

/*
 * Class for matrix calculations
 */
class Matrix {
private:
	int rows; //Number of rows of matrix
	int cols; //Number of columns of matrix
	int **data; //Data of matrix
	bool transposition; //Flag of transposition

	//Function to allocate space for matrix
	void allocateSpace(void);

	//Function to free space of matrix
	void freeSpace(void);

public:
	//Constructor of matrix
	// Parameters:
	// int: Rows of matrix
	// int: Columns of matrix
	// bool: Set flags if matrix should be transposed before calculations (true if yes, false if not)
	Matrix(int, int, bool);

	//Destructor of matrix
	~Matrix(void);

	//Function to add value to specific position
	// Parameters:
	// int: Row number (from 0)
	// int: Column number (from 0)
	// int: Value to be added
	// return: True if it was successfull, false if not
	bool addToMatrix(int, int, int);

	//Function to transpose matrix
	// return: New matrix, which is transposed
	Matrix transpose(void);

	//Function to print values stored in matrix
	void write(void);

	//Function to load matrix from input
	// return: Matrix loaded from standard input
	static Matrix loadFromInput(void);

	//Function to load matrix from input with checking operations conditions
	// return: Matrix loaded from standard input
	static Matrix loadFromInput(Matrix, char);

	//Define behaviour of == operator on matrices
	// return: True if matrices are same, false if not
	bool operator == (Matrix other);

	//Function to get count of rows of matrix
	// return: Count of rows
	int getRows();

	//Function to get count of columns of matrix
	// return: Count of columns
	int getCols();

};
#endif // !__MATRIX_H__
