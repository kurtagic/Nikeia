#include "Parser.h"

void Parser::parse(const std::string& program_filepath, std::vector<std::string>& program, std::unordered_map<std::string, int>& labels)
{
	std::vector<std::string> program_lines = getFileLines(program_filepath);

	int token_counter = 0;

	for (const std::string& line : program_lines)
	{
		std::vector<std::string> parts = splitLine(line);

		// empty line
		if (parts.size() == 0)
		{
			continue;
		}

		std::string opcode = parts[0];
		std::string parameter;

		// Handle labels
		if (opcode[opcode.size() - 1] == ':')
		{
			std::string label = opcode.substr(0, opcode.size() - 1);
			labels[label] = token_counter;

			continue;
		}

		program.push_back(opcode);
		token_counter++;

		if (opcode.compare(PUSH) == 0)
		{
			parameter = parts[1];
			program.push_back(parameter);
			token_counter++;
		}

		if (opcode.compare(PRINT) == 0)
		{
			parameter = parts[1];
			parameter = parameter.substr(1, parameter.size() - 2);
			program.push_back(parameter);
			token_counter++;
		}

		if (opcode.compare(PRINT_LINE) == 0)
		{
			parameter = parts[1];
			parameter = parameter.substr(1, parameter.size() - 2);
			program.push_back(parameter);
			token_counter++;
		}

		if (opcode.compare(JUMP_EQL_0) == 0)
		{
			parameter = parts[1];
			program.push_back(parameter);
			token_counter++;
		}

		if (opcode.compare(JUMP_GRT_0) == 0)
		{
			parameter = parts[1];
			program.push_back(parameter);
			token_counter++;
		}

		if (opcode.compare(GOTO) == 0)
		{
			parameter = parts[1];
			program.push_back(parameter);
			token_counter++;
		}
	}
}

std::vector<std::string> Parser::getFileLines(std::string filepath)
{
	std::ifstream file(filepath);

	std::vector<std::string> lines;
	std::string line;

	while (std::getline(file, line))
	{
		lines.push_back(line);
	}

	file.close();

	return lines;
}
std::vector<std::string> Parser::splitLine(std::string line)
{
	std::vector<std::string> tokens;
	std::string token;

	if (line.empty())
	{
		return tokens;
	}

	if (line.substr(0, 1) == COMMENT)
	{
		return tokens;
	}

	std::istringstream iss(line);

	while (iss >> token)
	{
		tokens.push_back(token);
	}

	return tokens;
}

