#pragma once
#include <string>
#include <map>
#include <stack>
#include "InterDebug.h"
#include "LexAnalyzer.h"

enum class OpsItemType
{
	IntVar,
	IntNum,
	FloatVar,
	FloatNum,
	StringVar,
	StringVal,
	Operation,
	Error
};

enum class OpsItemOperation
{
	Read,
	Write,
	Resize,
	Plus,
	Minus,
	UnarMinus,
	Multiply,
	Divide,
	Less,
	Assign,
	More,
	Equal,
	LessOrEqual,
	MoreOrEqual,
	NotEqual,
	Jump,
	JumpIfElse,
	Index,
	Memory,
	Error
};

struct OpsItem
{
	OpsItemType Ops_type = OpsItemType::Error;
	OpsItemOperation Ops_operation = OpsItemOperation::Error;
	std::string variable_name;
	std::string string_val = "";
	float Num_Val = 0;
	DebugInfo debuginfo;

	OpsItem(std::string var_name, OpsItemType ops_type, DebugInfo di)
	{
		Ops_type = ops_type;
		variable_name = var_name;
		debuginfo = di;
	}

	OpsItem(OpsItemOperation ops_operation, DebugInfo di)
	{
		Ops_type = OpsItemType::Operation;
		Ops_operation = ops_operation;
		debuginfo = di;
	}

	OpsItem(int num_value, DebugInfo di)
	{
		Ops_type = OpsItemType::IntNum;
		Num_Val = num_value;
		debuginfo = di;
	}

	OpsItem(float num_value, DebugInfo di)
	{
		Ops_type = OpsItemType::FloatNum;
		Num_Val = num_value;
		debuginfo = di;
	}

	OpsItem(std::string str_val, DebugInfo di)
	{
		Ops_type = OpsItemType::StringVal;
		string_val = str_val;
		debuginfo = di;
	}
};

struct InterData
{
	std::vector<OpsItem> ops_item;
	std::map<std::string, int> int_table;
	std::map<std::string, std::vector<int>> massInt_table;
	std::map<std::string, float> float_table;
	std::map<std::string, std::vector<float>> massFloat_table;
	std::map<std::string, std::string> string_table;
	std::vector<std::string> constid_table;
	////
};

class OpsGenerator
{
private:

	enum class Nonterminal {
		S, // → const OS | Int IS | float IS | array GS | aH = E;Q | b = Y;Q | read(aH);Q | write(E);Q | resize(a, E);Q | if (C) {AQ}kQ | while (C) {AQ}Q | for (P;C;P) {AQ}Q
		G, // → int J | float J
		O, // → int B | float B | string B
		Q, // → aH = E;Q | b = Y;Q | read(aH);Q | write(E);Q | resize(a, E);Q | if (C) {AQ}kQ | while (C) {AQ}Q | for (P;C;P) {AQ}Q | λ
		A, // → aH = E; | b = Y; | read(aH); | write(E); | resize(a, E); | if (C) {AQ}k | while (C) {AQ} | for (P;C;P) {AQ}
		Y, // → b | k
		B, // → a = kD
		D, // → ,B | ;
		P, // → a = E
		I, // → aM
		M, // → , aM | ;
		J, // → a[k]N
		N, // → , a[k]N | ;
		H, // → [E] | λ
		C, // → (E)VUL | aHVUL | kVUL | +FVUL | -FVUL
		L, // < EZ | > EZ | ==EZ | <=EZ | >= EZ | !=EZ
		K, // → else {Q} | λ
		E, // → (E)VU | aHVU | kVU | +FVU | -FVU
		U, // → +TU | -TU | λ
		T, // → (E)V | aHV | kV | +FV | -FV
		V, // → *RV | /RV | λ
		R, // → +F | -FZ | (E) | aH | k
		F, // → (E) | aH | k
		Z, // → λ
		Error // ошибочное состояние
	};

	enum class GeneratorTask
	{
		Empty,
		VariableId, //
		ConstVal,   //
		IntNumber,  //
		FloatNumber,//
		StringVal,  //
		Read,
		Write,
		Plus,
		Minus,
		UnarMinus,
		Multiply,
		Divide,
		Less,
		Assign,
		Memory,
		Resize,
		More,
		Equal,
		LessOrEqual,
		MoreOrEqual,
		NotEqual,
		Index,
		Task1,
		Task2,
		Task3,
		Task4,
		Task5,
		Task6,
		Task7,
		Task8,
		Task9,
		Task10,
		Task11,
		Task12
	};

	struct MagazineItem
	{
		bool is_terminal;
		LexemeType lexeme_type;
		Nonterminal nonterminal;

		MagazineItem(LexemeType lex_type) {
			is_terminal = true;
			lexeme_type = lex_type;
			nonterminal = Nonterminal::Error;
		}

		MagazineItem(Nonterminal s) {
			is_terminal = false;
			lexeme_type = LexemeType::Error;
			nonterminal = s;
		}
	};

	enum class vartable {
		Int,
		Float,
		String
	};

	std::vector<LexemeInfo> input_lexemes;

	std::stack<MagazineItem> magazine;
	std::stack<GeneratorTask> generator;
	std::stack<int> magazine_marks;

	std::vector<std::string> names_table;

	LexemeInfo current_lexeme;
	Nonterminal current_nonterminal;
	vartable current_table;
	GeneratorTask current_task;
	InterData interdata;

	bool is_constant = false;
	bool is_array = false;

	void DoTask();
	void GrammNonterminal();

public:

	OpsGenerator(std::vector<LexemeInfo> input);
	InterData GetOpsData();

};

