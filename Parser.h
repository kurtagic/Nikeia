#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include<vector>
#include <unordered_map>

#include "Instructions.h"

class Parser
{
public:
	void parse(const std::string& program_filepath, std::vector<std::string>& program, std::unordered_map<std::string, int>& labels);
	std::vector<std::string> getFileLines(std::string filepath);
	std::vector<std::string> splitLine(std::string line);
};

