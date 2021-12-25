#include "LexAnalyzer.h"

LexAnalyzer::LexAnalyzer(const std::string& file_text)
{
	program_text = file_text;
	current_file_pos = 0;
	current_debuginfo.debug_line = 1;
	current_debuginfo.debug_position = 1;
}

void LexAnalyzer::Start()
{
	LexemeInfo current_lexeme;

	while (current_file_pos < program_text.size())
	{
		if (isspace(program_text[current_file_pos])) { //skip all empty space
			switch (program_text[current_file_pos++])
			{
			case ' ':
				++current_debuginfo.debug_position;
				break;
			case '\n':
				current_debuginfo.debug_position = 1;
				++current_debuginfo.debug_line;
				break;
			case '\t':
				++current_debuginfo.debug_position;
				break;
			}
			continue;
		}
	}

	std::cout << std::endl << current_debuginfo.debug_line << std::endl << current_debuginfo.debug_position;
}
