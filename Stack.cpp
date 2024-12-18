#include "Stack.h"

Stack::Stack()
{
	this->sp = -1;
}
void Stack::resize(size_t n)
{
	this->buffer.resize(n);
}

void Stack::push(int n)
{
	this->sp++;
	this->buffer[this->sp] = n;
}

int Stack::pop()
{
	int n = this->buffer[this->sp];
	this->sp--;
	return n;
}

int Stack::top()
{
	return this->buffer[this->sp];
}