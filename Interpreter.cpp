#include "Interpreter.h"

Interpreter::Interpreter(const std::vector<std::string>& program, std::unordered_map<std::string, int>& labels)
{
	this->pc = 0;
	this->stack.resize(DEFAULT_STACK_SIZE);

	this->program = program;
	this->labels = labels;
}

void Interpreter::interpret()
{
	while (program[this->pc].compare(HALT) != 0)
	{
		std::string opcode = program[this->pc++];

		if (opcode.compare(PUSH) == 0)
		{
			handlePush();
		}

		else if (opcode.compare(POP) == 0)
		{
			handlePop();
		}

		else if (opcode.compare(ADD) == 0)
		{
			handleAdd();
		}

		else if (opcode.compare(SUB) == 0)
		{
			handleSub();
		}

		else if (opcode.compare(PRINT) == 0)
		{
			handlePrint();
		}

		else if (opcode.compare(PRINT_LINE) == 0)
		{
			handlePrintLine();
		}

		else if (opcode.compare(READ) == 0)
		{
			handleRead();
		}

		else if (opcode.compare(JUMP_EQL_0) == 0)
		{
			handleJumpEql0();
		}

		else if (opcode.compare(JUMP_GRT_0) == 0)
		{
			handleJumpGrt0();
		}

		else if (opcode.compare(GOTO) == 0)
		{
			handleGoto();
		}
	}
}

void Interpreter::handlePush()
{
	int n = std::stoi(program[this->pc++]);
	this->stack.push(n);
}

void Interpreter::handlePop()
{
	this->stack.pop();
}

void Interpreter::handleAdd()
{
	int a = this->stack.pop();
	int b = this->stack.pop();
	this->stack.push(a + b);
}

void Interpreter::handleSub()
{
	int a = this->stack.pop();
	int b = this->stack.pop();
	this->stack.push(b - a);
}

void Interpreter::handlePrint()
{
	std::string output = program[this->pc++];
	std::cout << output;
}

void Interpreter::handlePrintLine()
{
	std::string output = program[this->pc++];
	std::cout << output << std::endl;
}

void Interpreter::handleRead()
{
	int n;
	std::cin >> n;
	this->stack.push(n);
}

void Interpreter::handleJumpEql0()
{
	int n = this->stack.top();
	if (n == 0)
	{
		this->pc = labels[program[this->pc]];
	}
	else
	{
		this->pc++;
	}
}

void Interpreter::handleJumpGrt0()
{
	int n = this->stack.top();
	if (n > 0)
	{
		this->pc = labels[program[this->pc]];
	}
	else
	{
		this->pc++;
	}
}

void Interpreter::handleGoto()
{
	this->pc = labels[program[this->pc]];
}

