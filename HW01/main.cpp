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
/// Main program file
/// Here program starts (obviously)
/// </summary>

#include "calculator.h"
#include "errors.h"
#include <iostream>
#include "colours.h"

#pragma warning(disable:4996)



/// <summary>
/// Main function of program
/// </summary>
/// <param name="argc">Count of intput arguments</param>
/// <param name="argv">Array of strings with arguments value</param>
/// <returns>0 if everything gone ok, something different if not</returns>
int main(int argc, char*argv[])
{
	int reti = OK;
	Calculator matrixcalc;
	reti = matrixcalc.run();
	std::cout << std::endl << "===========================================" << std::endl;
	std::cout << "Program exited with code "<< (reti == OK ? BGREEN : BRED)  << reti << " (0x" << std::hex << reti << ")" << RST << "." << std::endl;
	std::cout << "To see, what does it mean, look into" << BMAGENTA << "errors.h" << RST << "." << std::endl;

	//Wait for something
	std::cout << std::endl;
	std::cin.ignore(1024, '\n');
	std::cout << "Press enter to continue..." << std::endl;
	std::cin.get(); 
	
	return reti;
}