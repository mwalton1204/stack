/*********************
Name: Michael Walton
COSC-2436-004
Purpose:
 - Study and code realistic Stack ADT implementation.
 - Rigorously test the functionality of stack class and methods.
**********************/

#ifndef STACK_H
#define STACK_H

#define DEFAULT 10

#include "data.h"

class Stack {

public:

    Stack(int);
    ~Stack();

    bool push(int, string&);
    bool pop(Data&);
    bool peek(Data&);
    bool isEmpty();
    int getSize();
    
private:

    int top;
    int size;
    Data **stack;
};

#endif //STACK_H
