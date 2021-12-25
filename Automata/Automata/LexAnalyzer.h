#pragma once
#include <iostream>
#include <vector>
#include "InterDebug.h"

enum class LexemeType
{
	VarName, //имя (идентификатор переменной)
	IntType,
	FloatType,
	StringType,
	Const,
	Array,
	IntNum,
	FloatNum,
	StringVal,
	If,
	Else,
	While,
	For,
	Read,
	Write,
	Resize,
	Allocate, //new
	LeftBrace, //{
	RightBrace,
	LeftSquareBracket,
	RightSquareBracket,
	LeftRoundBracket,
	RightRoundBracket,
	Plus,
	Minus,
	Multiply,
	Divide,
	Semicolon,
	Comma,
	Less,
	Assign,
	More,
	Equal,
	LessOrEqual,
	MoreOrEqual,
	NotEqual,
	Finish,
	Error
};

struct LexemeInfo
{
	LexemeType lex_type;
	std::string lex_value;
	DebugInfo lex_debuginfo;
};

class LexAnalyzer {

private:
	LexemeInfo NextLexeme();
	bool IsChar(char ch);

	std::string program_text;
	int current_file_pos;			//
	DebugInfo current_debuginfo;
	std::vector<LexemeInfo> lexems_data;
	
public:
	void Start();
	std::vector<LexemeInfo> GetLexemesData();
	LexAnalyzer(const std::string&);
};
//
////text(char *) -> lex_anal(text) -> lexemes(lexeme *) -> synt_anal(lexemes) -> OPS -> interpret(OPS)