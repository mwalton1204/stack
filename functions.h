/*********************
Name: Michael Walton
COSC-2436-004
Purpose:
 - Study and code realistic Stack ADT implementation.
 - Rigorously test the functionality of stack class and methods.
**********************/

#ifndef STACKS_FUNCTIONS_H
#define STACKS_FUNCTIONS_H

#define MAXSTRSIZE 8

#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>
#include "stack.h"

using std::cout;
using std::string;


void rand_string(string*);

void test_push(Stack*, int, string);
void test_pop(Stack*);
void test_peek(Stack*);
void test_isEmpty(Stack*);
void test_getSize(Stack*);

#endif /* STACKS_FUNCTIONS_H */