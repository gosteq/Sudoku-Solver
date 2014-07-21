#ifndef STACK_H
#define STACK_H
#include "Structures.h"

class Stack{
private:
    BoardInfo boards[81];
    int actualFreePlaceForBoard;
public:
    Stack();
    ~Stack();
    void push(BoardInfo* boardInfo);
    void pop(BoardInfo* boardInfo);
    bool empty();
};

#endif // STACK_H
