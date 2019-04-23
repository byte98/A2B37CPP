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
/// Definition of some colours to color output to console
/// </summary>

/// <summary>
/// Red colour
/// </summary>
#define RED "\u001b[0;31"

/// <summary>
/// Red colour with bold letters
/// </summary>
#define BRED "\u001b[1;31m"

/// <summary>
/// Green colour
/// </summary>
#define GREEN "\u001b[0;32m"

/// <summary>
/// Green colour with bold letters
/// </summary>
#define BGREEN "\u001b[1;32m"

/// <summary>
/// Yellow colour
/// </summary>
#define YELLOW "\u001b[0;33m"

/// <summary>
/// Yellow colour with bold letters
/// </summary>
#define BYELLOW "\u001b[01;33m"

/// <summary>
/// Blue colour
/// </summary>
#define BLUE "\u001b[0;34m"

/// <summary>
/// Blue colour with bold letters
/// </summary>
#define BBLUE "\u001b[1;34m"

/// <summary>
/// Magenta colour
/// </summary>
#define MAGENTA " \u001b[35m"

/// <summary>
/// Magenta colour with bold letters
/// </summary>
#define BMAGENTA " \u001b[1;35m"

/// <summary>
/// Cyan colour
/// </summary>
#define CYAN "\u001b[0;36m"

/// <summary>
/// Cyan colour with bold letters
/// </summary>
#define BCYAN "\u001b[1;36m"

/// <summary>
/// Reset colour settings to system default
/// </summary>
#define RST "\u001b[0m"