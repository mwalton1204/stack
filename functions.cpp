/*********************
Name: Michael Walton
COSC-2436-004
Purpose:
 - Study and code realistic Stack ADT implementation.
 - Rigorously test the functionality of stack class and methods.
**********************/

#include "functions.h"

void rand_string(string *str){
    // create size 0 to MAXSTRSIZE-1
    int rnum = rand() % MAXSTRSIZE;
    
    // make buffer to hold rand string
    char *buffer = new char[rnum+1];

    // fill buffer with random characters A to Z
    int i = 0;
    for(; i < rnum; i++){
        buffer[i] = (rand() % ('Z' - 'A' + 1)) + 'A';
    }
    buffer[i] = '\0';

    // transfer buffer to passed in string
    *str = buffer;

    // clean up
    delete[] buffer;
    return;
}

void test_push(Stack *s, int id, string info) {
    cout << "Attempting Push...\n";

    if(s->push(id, info)) {
        cout << "ID: " << id << "\nInformation: " << info << "\nPush Successful!\n\n";
    } else {
        cout << "Overflow Error\n\n";
    }
}

void test_pop(Stack *s) {
    cout << "Attempting Pop...\n";

    Data emptyData;

    if (s->pop(emptyData)) {
        cout << "ID: " << emptyData.id << "\nInformation: " << emptyData.information << "\nPop Successful!\n\n";
    } else {
        cout << "Underflow Error\n\n";
    }
}

void test_peek(Stack *s) {
    cout << "Attempting Peek...\n";

    Data emptyData;

    if (s->peek(emptyData)) {
        cout << "ID: " << emptyData.id << "\nInformation: " << emptyData.information << "\nPeek Successful!\n\n";
    } else {
        cout << "Underflow Error\n\n";
    }
}

void test_isEmpty(Stack *s) {
    cout << "Checking if Empty...\n";

    if (s->isEmpty()) {
        cout << "Stack Status: Empty\n\n";
    } else {
        cout << "Stack Status: Not Empty\n\n";
    }
}

void test_getSize(Stack *s) {
    cout << "Checking size of Stack...\n";
    cout << "Stack Size: " << s->getSize() << "\n\n";
}

