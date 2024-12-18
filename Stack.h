#pragma once
#include <vector>

#define DEFAULT_STACK_SIZE 256

class Stack 
{
public:
    Stack();
    void resize(size_t n);
    void push(int n);
    int pop();
    int top();

private:
    int sp;
    std::vector<int> buffer;
};
