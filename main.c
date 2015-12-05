/*
 *  CCalcuator is a basic command line calculator written in C
 *  Copyright (C) 2015  Gustaf Järgren
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "parser.h"
#include "math/math.h"
#include <stdio.h>

/*
 * NOTE: when multiplying you need to escape the '*' letter like this '\*' or 
 * else it will input everything in the current dirctory as inputs
 */

int main(int argc, char **argv) {
	int status;
	int result = 0;
	int firstVal;
	int secondVal;
	char operatorType;

	status = parseInput(argc, argv, &firstVal, &secondVal, &operatorType);
	if (status != 0)
	{
		return status;
	}

	switch (operatorType) {
		case '+':
			result = add(firstVal, secondVal);
			break;
		case '-':
			result = subtract(firstVal, secondVal);
			break;
		case '/':
			result = divide(firstVal, secondVal);
			break;
		case '*':
			result = multiply(firstVal, secondVal);
			break;
		case '%':
			result = mod(firstVal, secondVal);
	}

	printf("Result: %d\n", result);
	return status;
}