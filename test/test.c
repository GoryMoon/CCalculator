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

#include <stdio.h>
#include "math.h"
#include "parser.h"
#include "test.h"

static int failures;
static int successes;

void test_mean_value(){

  int result;
  int d1;
  int d2;
  char d3;

  char *p[] = {"dummy", "1", "+", "2"};
  char *p1[] = {"dummy", "1", "+"};
  char *p2[] = {"dummy", "1", "h", "2"};
  char *p3[] = {"dummy", "a", "+"};
  char *p4[] = {"dummy", "liverpool"};

   /*
   *  Parse tests
   */

  result = parseInput(4, p, &d1, &d2, &d3);
  CHECK(0, result, "parse");
  CHECK(1, d1, "parseVal 1.1");
  CHECK(2, d2, "parseVal 1.2");
  CHECK('+', d3, "parseVal 1.3");

  result = parseInput(3, p1, &d1, &d2, &d3);
  CHECK(1, result, "parse");

  result = parseInput(4, p2, &d1, &d2, &d3);
  CHECK(2, result, "parse");

  result = parseInput(3, p3, &d1, &d2, &d3);
  CHECK(2, result, "parse");

  result = parseInput(2, p4, &d1, &d2, &d3);
  CHECK(2, result, "parse");

  /*
   *  Math tests
   */

  result = add(12, 30);
  CHECK(42, result, "addition");

  result = subtract(13, 8);
  CHECK(5, result, "subtraction");

  result = divide(24, 6);
  CHECK(4, result, "division1");

  result = divide(24, 0);
  CHECK(0, result, "division2");
  
  result = multiply(7, 7);
  CHECK(49, result, "multiplication");
  
  result = mod(36, 7);
  CHECK(1, result, "modulus");

  return ;
}

int main() {

  test_mean_value();

  printf ("Tests:       %d\n", failures+successes);
  printf ("Successes:   %d\n", successes);
  printf ("Failures:    %d\n", failures);

  return failures;  
}
