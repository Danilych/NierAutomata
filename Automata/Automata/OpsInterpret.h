#pragma once
#include<sstream>
#include"OpsGenerator.h"

class OpsInterpret
{
private:
	InterData input_ops;

	bool is_int(const std::string& input);
	bool is_float(std::string input);
	bool check_is_string(OpsItem& a, OpsItem& b, bool assign_check);
	bool check_constant_for_assign(OpsItem& a, std::map<std::string, int>& const_flags);
	bool check_constant(OpsItem& a, std::map<std::string, int>& const_flags);

	void SetInt(OpsItem& ops_item, int num);
	void SetFloat(OpsItem& ops_item, float num);
	void SetString(OpsItem& ops_item, std::string str);
	void AllocateMemory(OpsItem& passport, int amount);
	void ResizeMemory(OpsItem& passport, int amount);

	int GetInt(OpsItem& ops_item);
	float GetFloat(OpsItem& ops_item);
	std::string GetString(OpsItem& ops_item);

public:
	void AnalyzeOps();
	OpsInterpret(InterData id);
};

