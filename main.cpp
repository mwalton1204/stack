/*********************
Name: Michael Walton
COSC-2436-004
Purpose:
 - Study and code realistic Stack ADT implementation.
 - Rigorously test the functionality of stack class and methods.
**********************/

#include "main.h"

int main(int argc, char **argv) {
    srand(time(NULL));

    int stackSize;
    string tempInfo;
    int tempId;

    try {
        stackSize = stoi(argv[1]);
    } catch (...) {
        stackSize = -1;
    }

    Stack myStack(stackSize);

    if (argc == 2 && stackSize != -1) {

        cout << "-------------------\tTESTING INITIALIZED STACK\t-------------------\n\n";

        test_getSize(&myStack);
        test_isEmpty(&myStack);

        cout << "-------------------\tTESTING FILLING AND FULL STACK\t-------------------\n\n";

        for(int i=0; i < stackSize * MULTIPLIER; i++){ //test push and peek
            tempId = rand() % MAX_ID_SIZE + 1;
            rand_string(&tempInfo);

            if(!tempInfo.empty()) {
                test_push(&myStack, tempId, tempInfo);
            } else {
                i--;
            }
        }

        test_isEmpty(&myStack);
        test_peek(&myStack);
        test_pop(&myStack);

        cout << "-------------------\tTESTING EMPTYING AND EMPTY STACK\t-------------------\n\n";

        test_isEmpty(&myStack);

        for(int i=0; i < stackSize * MULTIPLIER; i++){ //test pop and peek
            test_peek(&myStack);
            test_pop(&myStack);
        }

        test_isEmpty(&myStack);

        cout << "-------------------\tRANDOMIZED TESTING\t-------------------\n\n";

        while(!myStack.isEmpty()) {
            test_pop(&myStack);
        }
        for (int i = 0; i < int(stackSize / 2); i++) {
            tempId = rand() % MAX_ID_SIZE + 1;
            rand_string(&tempInfo);

            if(!tempInfo.empty()) {
                test_push(&myStack, tempId, tempInfo);
            } else {
                i--;
            }
        }

        int choice = rand() % CHOICES + 1;
        for (int i = 0; i < stackSize; i++) {
            switch(choice) {
                case 1:
                case 2:
                    tempId = rand() % MAX_ID_SIZE + 1;
                    rand_string(&tempInfo);

                    if (!tempInfo.empty()) {
                        test_push(&myStack, tempId, tempInfo);
                    } else {
                        i--;
                    }
                    break;
                case 3:
                case 4:
                    test_pop(&myStack);
                    break;
                case 5:
                    test_peek(&myStack);
                    break;
                case 6:
                    test_isEmpty(&myStack);
                    break;
            }
            choice = rand() % CHOICES + 1;
        }
    } else {
        cout << "Invalid Argument\n" << "Format: [program name] [integer]";
    }

    return 0;
}
