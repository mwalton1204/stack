/*********************
Name: Michael Walton
COSC-2436-004
Purpose:
 - Study and code realistic Stack ADT implementation.
 - Rigorously test the functionality of stack class and methods.
**********************/

#include "stack.h"

Stack::Stack(int i) {
    top = -1;
    size = i;

    if (size < 2) {
        size = DEFAULT;
    }

    stack = new Data*[size];
}

Stack::~Stack() {
    for (int i = 0; i <= top; i++) {
        delete stack[i];
    }
    delete[] stack;
}

bool Stack::push(int id, string& info){
    bool pushed = false;

    if (top < size - 1) {
        if (id > 0 && !info.empty()) {
            top++;
            stack[top] = new Data{id, info};

            pushed = true;
        }
    }

    return pushed;
}

bool Stack::pop(Data &emptyData) {
    bool popped = false;

    if (top != -1) {
        emptyData = *(stack[top--]);
        delete stack[top+1];
        popped = true;
    } else {
        emptyData.id = -1;
        emptyData.information = "";
    }

    return popped;
}

bool Stack::peek(Data &emptyData) {
    bool peeked = false;

    if (top != -1) {
        emptyData = *(stack[top]);
        peeked = true;
    } else {
        emptyData.id = -1;
        emptyData.information = "";
    }

    return peeked;
}

bool Stack::isEmpty(){
    return top == -1;
}

int Stack::getSize(){
    return size;
}


