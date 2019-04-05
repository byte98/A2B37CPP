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
public:
	Matrix();
	~Matrix();
};