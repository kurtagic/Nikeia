#include <string>
#include <vector>
#include <unordered_map>

#include "Interpreter.h"
#include "Parser.h"

int main([[maybe_unused]] int argc, char *argv[])
{
	std::string program_filepath = argv[1];
	std::string extension = program_filepath.substr(program_filepath.size() - 4, program_filepath.size() - 1);
	if (extension != ".nka")
	{
		std::cerr << "Incorrect file type, should be .nka" << std::endl;
		return 1;
	}

	std::vector<std::string> program;
	std::unordered_map<std::string, int> labels;

	Parser parser;
	parser.parse(program_filepath, program, labels);

	Interpreter interpreter(program, labels);
	interpreter.interpret();

	return 0;
}
