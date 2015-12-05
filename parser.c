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

int parseInput(int size, char **args, int *firstVal, int *secondVal, char *operatorType) {
	char **input = args;
	int val;
	int status = 0;
	if (size < 2)
	{
		missingArgs();
		return 1;
	}
	
	input++;
	size--;
	status = checkValidSize(size, 3);
	if (status != 0) { return status; }
	if (validNumber(input[0]) == 0)
	{
		syntaxError();
		return 2;
	} else {
		sscanf(input[0], "%d", &val);
		*firstVal = val;
	}

	size--;
	status = checkValidSize(size, 2);
	if (status != 0) { return status; }
	if (validOperator(input[1]) == 0)
	{
		syntaxError();
		return 2;
	} else {
		*operatorType = *input[1];
	}

	size--;
	status = checkValidSize(size, 1);
	if (status != 0) { return status; }
	if (validNumber(input[2]) == 0)
	{
		syntaxError();
		return 2;
	} else {
		sscanf(input[2], "%d", &val);
		*secondVal = val;
	}

	size--;
	status = checkValidSize(size, 0);

	return status;
}

int validNumber(char *n) {
	if (*n == '0' || *n == '1' || *n == '2' || *n == '3' || *n == '4' || 
		*n == '5' || *n == '6' || *n == '7' || *n == '8' || *n == '9')
	{
		return 1;
	}
	return 0;
}

int validOperator(char *o) {
	if (*o == '+' || *o == '-' || *o == '/' || *o == '*' || *o == '%')
	{
		return 1;
	}
	return 0;
}

int checkValidSize(int size, int stage) {
	if (size <= 0 && stage > 0)
	{
		missingArgs();
		return 1;
	} else if (size > 0 && stage == 0) {
		syntaxError();
		return 2;
	}
	return 0;
}

void missingArgs() {
	fprintf(stderr, "Missing Arguments\nThere needs to be 3 arguments, correct syntax is:\n\tCCalculator {value} {operator} {value}\n");
}

void syntaxError() {
	fprintf(stderr, "Syntax error\nCorrect syntax is:\n\tCCalculator {value} {operator} {value}\n");
}
