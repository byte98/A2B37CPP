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
/// Definitions of possible errors
/// </summary>


/// <summary>
/// Everything gone right
/// </summary>
#define OK 0
/// <summary>
/// Macro to check if everything is good
/// </summary>
/// <param name="code">Error code to be checked</param>
#define GOOD(code) ((code) == OK ? true : false)



/// <summary>
/// Loading of count of rows of first matrix failed
/// </summary>
#define ERR_IN_FMR 111

/// <summary>
/// Loading of count of columns of first matrix failed
/// </summary>
#define ERR_IN_FMC 112

/// <summary>
/// Loading data to first matrix failed
/// </summary>
#define ERR_IN_FMD 113

/// <summary>
/// Rows of first matrix isn't allowed for Kronecker product
/// </summary>
#define ERR_IN_FMORK 114

/// <summary>
/// Columns of first matrix isn't allowed for Kronecker product
/// </summary>
#define ERR_IN_FMOCK 115



/// <summary>
/// Loading of count of rows of second matrix failed
/// </summary>
#define ERR_IN_SMR 121

/// <summary>
/// Loading of count of columns of second matrix failed
/// </summary>
#define ERR_IN_SMC 122

/// <summary>
/// Loading data to second matrix failed
/// </summary>
#define ERR_IN_SMD 123

/// <summary>
/// Rows of second matrix isn't allowed for addition/substraction
/// </summary>
#define ERR_IN_SMORA 124

/// <summary>
/// Columns of second matrix isn't allowed for addition/substraction
/// </summary>
#define ERR_IN_SMOCA 125

/// <summary>
/// Rows of second matrix isn't allowed for multiplying
/// </summary>
#define ERR_IN_SMORM 126

/// <summary>
/// Columns of second matrix isn't allowed for multiplying
/// </summary>
#define ERR_IN_SMOCM 127

/// <summary>
/// Rows of second matrix isn't allowed for Hadramard product
/// </summary>
#define ERR_IN_SMORH 128

/// <summary>
/// Columns of second matrix isn't allowed for Hadramard product
/// </summary>
#define ERR_IN_SMOCH 129

/// <summary>
/// Rows of second matrix isn't allowed for Kronecker product
/// </summary>
#define ERR_IN_SMORK 130

/// <summary>
/// Columns of second matrix isn't allowed for Kronecker product
/// </summary>
#define ERR_IN_SMOCK 131



/// <summary>
/// Loading character of operation failed
/// </summary>
#define ERR_IN_OLF 141

/// <summary>
/// Loaded operation is not in allowed operations
/// </summary>
#define ERR_IN_ONA 142



/// <summary>
/// Adding data to matrix failed because of rows number is too small
/// </summary>
#define ERR_DATA_ADDRS 201

/// <summary>
/// Adding data to matrix failed because of rows number is too large
/// </summary>
#define ERR_DATA_ADDRL 202

/// <summary>
/// Adding data to matrix failed because of columns number is too small
/// </summary>
#define ERR_DATA_ADDCS 203

/// <summary>
/// Adding data to matrix failed because of columns number is too large
/// </summary>
#define ERR_DATA_ADDCL 204