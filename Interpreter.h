#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

#include "Stack.h"
#include "Instructions.h"

class Interpreter
{
public:
	Interpreter(const std::vector<std::string>& program, std::unordered_map<std::string, int>& labels);
	void interpret();

private:
	void handlePush();
	void handlePop();
	void handleAdd();
	void handleSub();
	void handlePrint();
	void handlePrintLine();
	void handleRead();
	void handleJumpEql0();
	void handleJumpGrt0();
	void handleGoto();

	int pc;
	Stack stack;
	std::vector<std::string> program;
	std::unordered_map<std::string, int> labels;
};

