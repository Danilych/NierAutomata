#include "LexAnalyzer.h"

LexAnalyzer::LexAnalyzer(const std::string& file_text)
{
	program_text = file_text;
	current_file_pos = 0;
}

bool LexAnalyzer::IsChar(char ch) {
	return ch == '_' || ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
}

std::vector<LexemeInfo> LexAnalyzer::GetLexemesData()
{
	DebugInfo current_debuginfo;
	current_debuginfo.debug_line = 1;
	current_debuginfo.debug_position = 1;
	LexemeInfo current_lexeme;

	while (current_file_pos < program_text.size())
	{
		if (isspace(program_text[current_file_pos])) { //skip all empty space
			if (program_text[current_file_pos++] == '\n') {
				current_debuginfo.debug_position = 1;
				++current_debuginfo.debug_line;
			}
			else ++current_debuginfo.debug_position;
			continue;
		}

		current_lexeme = LookForNextLexeme();
		current_lexeme.lex_debuginfo = current_debuginfo;

		if (current_lexeme.lex_type == LexemeType::Error)
		{
			std::string errormsg = "LexAnalyzer error; Unknown lexeme type = '" + current_lexeme.lex_value + "';";
			throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
		}

		current_debuginfo.debug_position += current_lexeme.lex_value.size();
		lexems_data.push_back(current_lexeme);
	}

	current_lexeme.lex_type = LexemeType::Finish;
	current_lexeme.lex_debuginfo = current_debuginfo;
	lexems_data.push_back(current_lexeme);

	return lexems_data;
}

LexemeInfo LexAnalyzer::LookForNextLexeme()
{
	char current_symbol = program_text[current_file_pos++];

	LexemeInfo FindedLexeme;
	FindedLexeme.lex_type = LexemeType::Error; //default lexeme value
	FindedLexeme.lex_value = current_symbol;

	if (IsChar(current_symbol))
	{
		FindedLexeme.lex_type = LexemeType::VarName;
		current_symbol = program_text[current_file_pos];
		while (current_file_pos < program_text.size() && IsChar(current_symbol) || isdigit(current_symbol))
		{
			FindedLexeme.lex_value += current_symbol;
			current_symbol = program_text[++current_file_pos];
		}

		if (FindedLexeme.lex_value == "int") FindedLexeme.lex_type = LexemeType::IntType;
		else if (FindedLexeme.lex_value == "float") FindedLexeme.lex_type = LexemeType::FloatType;
		else if (FindedLexeme.lex_value == "string") FindedLexeme.lex_type = LexemeType::StringType;
		else if (FindedLexeme.lex_value == "const") FindedLexeme.lex_type = LexemeType::Const;
		else if (FindedLexeme.lex_value == "array") FindedLexeme.lex_type = LexemeType::Array;
		else if (FindedLexeme.lex_value == "if") FindedLexeme.lex_type = LexemeType::If;
		else if (FindedLexeme.lex_value == "else") FindedLexeme.lex_type = LexemeType::Else;
		else if (FindedLexeme.lex_value == "while") FindedLexeme.lex_type = LexemeType::While;
		else if (FindedLexeme.lex_value == "for") FindedLexeme.lex_type = LexemeType::For;
		else if (FindedLexeme.lex_value == "read") FindedLexeme.lex_type = LexemeType::Read;
		else if (FindedLexeme.lex_value == "write") FindedLexeme.lex_type = LexemeType::Write;
		else if (FindedLexeme.lex_value == "resize") FindedLexeme.lex_type = LexemeType::Resize;
		//else if (FindedLexeme.lex_value == "new") FindedLexeme.lex_type = LexemeType::Allocate;
	}
	else if (isdigit(current_symbol))
	{
		FindedLexeme.lex_type = LexemeType::IntNum;
		current_symbol = program_text[current_file_pos];
		bool isfloat = false;
		//считывание цифр и ошибка если попалось несколько точек в числе
		while (current_file_pos < program_text.size() && isdigit(current_symbol) || current_symbol=='.') {
			FindedLexeme.lex_value += current_symbol;
			current_file_pos++;
			if (current_symbol == '.' && !isfloat) { isfloat = true; FindedLexeme.lex_type = LexemeType::FloatNum;
			}
			else if (current_symbol == '.' && isfloat) FindedLexeme.lex_type = LexemeType::Error;
			current_symbol = program_text[current_file_pos];
		}
		//Если попалась буква и другие служебные символы, то ошибка
		//TODO: добавить завершение распознования при нахождении знака операции и т.д. по таблице переходов
		if (current_file_pos < program_text.size() && IsChar(current_symbol)) {
			while (current_file_pos < program_text.size() && IsChar(current_symbol)) {
				FindedLexeme.lex_value += current_symbol;
				++current_file_pos;
				current_symbol = program_text[current_file_pos];
			}
			FindedLexeme.lex_type = LexemeType::Error;
		}
	}
	else if (current_symbol == '{') FindedLexeme.lex_type = LexemeType::LeftBrace;
	else if (current_symbol == '}') FindedLexeme.lex_type = LexemeType::RightBrace;
	else if (current_symbol == '[') FindedLexeme.lex_type = LexemeType::LeftSquareBracket;
	else if (current_symbol == ']') FindedLexeme.lex_type = LexemeType::RightSquareBracket;
	else if (current_symbol == '(') FindedLexeme.lex_type = LexemeType::LeftRoundBracket;
	else if (current_symbol == ')') FindedLexeme.lex_type = LexemeType::RightRoundBracket;
	else if (current_symbol == '+') FindedLexeme.lex_type = LexemeType::Plus;
	else if (current_symbol == '-') FindedLexeme.lex_type = LexemeType::Minus;
	else if (current_symbol == '*') FindedLexeme.lex_type = LexemeType::Multiply;
	else if (current_symbol == '/') FindedLexeme.lex_type = LexemeType::Divide;
	else if (current_symbol == ';') FindedLexeme.lex_type = LexemeType::Semicolon;
	else if (current_symbol == ',') FindedLexeme.lex_type = LexemeType::Comma;
	else if (current_symbol == '<') 
	{
		FindedLexeme.lex_type = LexemeType::Less;
		if (current_file_pos < program_text.size() && program_text[current_file_pos] == '=') {
			current_file_pos++;
			FindedLexeme.lex_type = LexemeType::LessOrEqual;
			FindedLexeme.lex_value = "<=";
		}
	}
	else if (current_symbol == '=') 
	{
		FindedLexeme.lex_type = LexemeType::Assign;
		if (current_file_pos < program_text.size() && program_text[current_file_pos] == '=') {
			current_file_pos++;
			FindedLexeme.lex_type = LexemeType::Equal;
			FindedLexeme.lex_value = "==";
		}
	}
	else if (current_symbol == '>') 
	{
		FindedLexeme.lex_type = LexemeType::More;
		if (current_file_pos < program_text.size() && program_text[current_file_pos] == '=') {
			current_file_pos++;
			FindedLexeme.lex_type = LexemeType::MoreOrEqual;
			FindedLexeme.lex_value = ">=";
		}
	}
	else if (current_symbol == '!') 
	{
		FindedLexeme.lex_type = LexemeType::Error;
		if (current_file_pos < program_text.size() && program_text[current_file_pos] == '=') {
			current_file_pos++;
			FindedLexeme.lex_type = LexemeType::NotEqual;
			FindedLexeme.lex_value = "!=";
		}
	}
	else if (current_symbol == '"')
	{
		FindedLexeme.lex_type = LexemeType::StringVal;
		while (current_file_pos < program_text.size() && program_text[current_file_pos] != '"') {
			if (program_text[current_file_pos] == '\n')
			{
				FindedLexeme.lex_type = LexemeType::Error;
				break;
			}
			FindedLexeme.lex_value += program_text[current_file_pos++];
		}
		if(current_file_pos < program_text.size() && program_text[current_file_pos] == '"' && FindedLexeme.lex_type != LexemeType::Error) FindedLexeme.lex_value += program_text[current_file_pos++];
	}
	return FindedLexeme;
}