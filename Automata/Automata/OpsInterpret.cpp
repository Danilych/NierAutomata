#include "OpsInterpret.h"

bool OpsInterpret::is_int(const std::string& input)
{
	std::string::const_iterator it = input.begin();
	if(*it == '-') it++;
	while (it != input.end() && std::isdigit(*it)) ++it;
	return !input.empty() && it == input.end();
}

bool OpsInterpret::is_float(std::string input) {
	std::istringstream iss(input);
	float f;
	iss >> std::noskipws >> f;
	return iss.eof() && !iss.fail();
}

bool OpsInterpret::check_is_string(OpsItem& a, OpsItem& b, bool assign_check)
{
	if (!assign_check)
	{
		return ((a.Ops_type == OpsItemType::StringVal || a.Ops_type == OpsItemType::StringVar) || (b.Ops_type == OpsItemType::StringVal || b.Ops_type == OpsItemType::StringVar));
	}
	else return (a.Ops_type == OpsItemType::StringVar && (b.Ops_type == OpsItemType::StringVal || b.Ops_type == OpsItemType::StringVar));
}

void OpsInterpret::AnalyzeOps()
{
	std::stack<OpsItem> magazine;
	auto& ops_data = input_ops.ops_item;
	auto& int_table = input_ops.int_table;
	auto& arrayInt_table = input_ops.massInt_table;
	auto& float_table = input_ops.float_table;
	auto& arrayFloat_table = input_ops.massFloat_table;
	auto& string_table = input_ops.string_table;
	auto& constid_table = input_ops.constid_table;
	std::map<std::string, int> const_init_flag;

	

	for (int i = 0; i < constid_table.size(); i++) const_init_flag.emplace(constid_table[i], 0);

	for (size_t i = 0; i < ops_data.size(); ++i)
	{
		switch (ops_data[i].Ops_type)
		{
		case OpsItemType::IntVar:
		case OpsItemType::IntNum:
		{
			magazine.push(ops_data[i]);
			break;
		}
		case OpsItemType::FloatVar:
		case OpsItemType::FloatNum:
		{
			magazine.push(ops_data[i]);
			break;
		}
		case OpsItemType::StringVar:
		case OpsItemType::StringVal:
		{
			magazine.push(ops_data[i]);
			break;
		}
		case OpsItemType::Operation:
		{
			switch (ops_data[i].Ops_operation)
			{
			case OpsItemOperation::Read:
			{
				auto a = magazine.top();
				magazine.pop();

				check_constant(a, const_init_flag);

				std::string input;
				std::cin >> input;

				switch (a.Ops_type)
				{
				case OpsItemType::FloatVar: SetFloat(a, std::stof(input)); break;
				case OpsItemType::IntVar: SetInt(a, std::stoi(input)); break;
				case OpsItemType::StringVar: SetString(a, input); break;
				}
				break;
			}
			case OpsItemOperation::Write:
			{
				auto a = magazine.top();
				magazine.pop();
				switch (a.Ops_type)
				{
				case OpsItemType::IntNum: std::cout << GetInt(a) << std::endl; break;
				case OpsItemType::IntVar:  std::cout << GetInt(a) << std::endl; break;
				case OpsItemType::FloatNum: std::cout << GetFloat(a) << std::endl; break;
				case OpsItemType::FloatVar:  std::cout << GetFloat(a) << std::endl; break;
				case OpsItemType::StringVal: std::cout << GetString(a) << std::endl; break;
				case OpsItemType::StringVar: std::cout << GetString(a) << std::endl; break;
				}
				break;
			}
			case OpsItemOperation::Resize:
			{
				auto newamount = magazine.top();
				magazine.pop();
				auto arr = magazine.top();
				magazine.pop();

				ResizeMemory(arr, GetInt(newamount));
				magazine.push(arr);
				break;
			}
			case OpsItemOperation::Plus:
			{
				auto b = magazine.top();
				magazine.pop();
				auto a = magazine.top();
				magazine.pop();

				float result;

				if (check_is_string(a, b, false))
				{
					std::string errormsg = "Interpreter error - can't plus string;";
					throw InterDebug(errormsg, a.debuginfo);
				}
				else
				{
					if ((a.Ops_type == OpsItemType::IntNum || a.Ops_type == OpsItemType::IntVar) && (b.Ops_type == OpsItemType::IntNum || b.Ops_type == OpsItemType::IntVar))
					{
						int result = GetInt(a) + GetInt(b);
						magazine.emplace(result, a.debuginfo);
					}
					else if ((a.Ops_type == OpsItemType::FloatNum || a.Ops_type == OpsItemType::FloatVar) && (b.Ops_type == OpsItemType::FloatNum || b.Ops_type == OpsItemType::FloatVar))
					{
						float result = GetFloat(a) + GetFloat(b);
						magazine.emplace(result, a.debuginfo);
					}
					else if ((a.Ops_type == OpsItemType::IntNum || a.Ops_type == OpsItemType::IntVar) && (b.Ops_type == OpsItemType::FloatNum || b.Ops_type == OpsItemType::FloatVar))
					{
						float result = GetInt(a) + GetFloat(b);
						magazine.emplace(result, a.debuginfo);
					}
					else if (((a.Ops_type == OpsItemType::FloatNum || a.Ops_type == OpsItemType::FloatVar) && (b.Ops_type == OpsItemType::IntNum || b.Ops_type == OpsItemType::IntVar)))
					{
						float result = GetFloat(a) + GetInt(b);
						magazine.emplace(result, a.debuginfo);
					}
					else
					{
						std::string errormsg = "Interpreter error - can't plus: unknow error;";
						throw InterDebug(errormsg, a.debuginfo);
					}
				}
				break;
			}
			case OpsItemOperation::Minus:
			{
				auto b = magazine.top();
				magazine.pop();
				auto a = magazine.top();
				magazine.pop();

				float result;

				if (check_is_string(a, b, false))
				{
					std::string errormsg = "Interpreter error - can't minus string;";
					throw InterDebug(errormsg, a.debuginfo);
				}
				else
				{
					if ((a.Ops_type == OpsItemType::IntNum || a.Ops_type == OpsItemType::IntVar) && (b.Ops_type == OpsItemType::IntNum || b.Ops_type == OpsItemType::IntVar))
					{
						int result = GetInt(a) - GetInt(b);
						magazine.emplace(result, a.debuginfo);
					}
					else if ((a.Ops_type == OpsItemType::FloatNum || a.Ops_type == OpsItemType::FloatVar) && (b.Ops_type == OpsItemType::FloatNum || b.Ops_type == OpsItemType::FloatVar))
					{
						float result = GetFloat(a) - GetFloat(b);
						magazine.emplace(result, a.debuginfo);
					}
					else if ((a.Ops_type == OpsItemType::IntNum || a.Ops_type == OpsItemType::IntVar) && (b.Ops_type == OpsItemType::FloatNum || b.Ops_type == OpsItemType::FloatVar))
					{
						float result = GetInt(a) - GetFloat(b);
						magazine.emplace(result, a.debuginfo);
					}
					else if (((a.Ops_type == OpsItemType::FloatNum || a.Ops_type == OpsItemType::FloatVar) && (b.Ops_type == OpsItemType::IntNum || b.Ops_type == OpsItemType::IntVar)))
					{
						float result = GetFloat(a) - GetInt(b);
						magazine.emplace(result, a.debuginfo);
					}
					else
					{
						std::string errormsg = "Interpreter error - can't minus: unknow error;";
						throw InterDebug(errormsg, a.debuginfo);
					}
				}
				break;
			}
			case OpsItemOperation::UnarMinus:
			{
				auto a = magazine.top();
				magazine.pop();

				switch (a.Ops_type)
				{
				case OpsItemType::IntNum: magazine.emplace(-GetInt(a), a.debuginfo); break;
				case OpsItemType::IntVar: magazine.emplace(-GetInt(a), a.debuginfo); break;
				case OpsItemType::FloatNum: magazine.emplace(-GetFloat(a), a.debuginfo); break;
				case OpsItemType::FloatVar: magazine.emplace(-GetInt(a), a.debuginfo); break;
				case OpsItemType::StringVal:
				{
					std::string errormsg = "Interpreter error - string can't use unar minus;";
					throw InterDebug(errormsg, a.debuginfo);
				}
				case OpsItemType::StringVar:
				{
					std::string errormsg = "Interpreter error - string can't use unar minus;";
					throw InterDebug(errormsg, a.debuginfo);
				}
				}
				break;
			}
			case OpsItemOperation::Multiply:
			{
				auto b = magazine.top();
				magazine.pop();
				auto a = magazine.top();
				magazine.pop();

				float result;

				if (check_is_string(a, b, false))
				{
					std::string errormsg = "Interpreter error - can't multiply string;";
					throw InterDebug(errormsg, a.debuginfo);
				}
				else
				{
					if ((a.Ops_type == OpsItemType::IntNum || a.Ops_type == OpsItemType::IntVar) && (b.Ops_type == OpsItemType::IntNum || b.Ops_type == OpsItemType::IntVar))
					{
						int result = GetInt(a) * GetInt(b);
						magazine.emplace(result, a.debuginfo);
					}
					else if ((a.Ops_type == OpsItemType::FloatNum || a.Ops_type == OpsItemType::FloatVar) && (b.Ops_type == OpsItemType::FloatNum || b.Ops_type == OpsItemType::FloatVar))
					{
						float result = GetFloat(a) * GetFloat(b);
						magazine.emplace(result, a.debuginfo);
					}
					else if ((a.Ops_type == OpsItemType::IntNum || a.Ops_type == OpsItemType::IntVar) && (b.Ops_type == OpsItemType::FloatNum || b.Ops_type == OpsItemType::FloatVar))
					{
						float result = GetInt(a) * GetFloat(b);
						magazine.emplace(result, a.debuginfo);
					}
					else if (((a.Ops_type == OpsItemType::FloatNum || a.Ops_type == OpsItemType::FloatVar) && (b.Ops_type == OpsItemType::IntNum || b.Ops_type == OpsItemType::IntVar)))
					{
						float result = GetFloat(a) * GetInt(b);
						magazine.emplace(result, a.debuginfo);
					}
					else
					{
						std::string errormsg = "Interpreter error - can't multiply: unknow error;";
						throw InterDebug(errormsg, a.debuginfo);
					}
				}
				break;
			}
			case OpsItemOperation::Divide:
			{
				auto b = magazine.top();
				magazine.pop();
				auto a = magazine.top();
				magazine.pop();

				float result;

				if (check_is_string(a, b, false))
				{
					std::string errormsg = "Interpreter error - can't divide string;";
					throw InterDebug(errormsg, a.debuginfo);
				}
				else
				{
					if ((a.Ops_type == OpsItemType::IntNum || a.Ops_type == OpsItemType::IntVar) && (b.Ops_type == OpsItemType::IntNum || b.Ops_type == OpsItemType::IntVar))
					{
						int result = GetInt(a) / GetInt(b);
						magazine.emplace(result, a.debuginfo);
					}
					else if ((a.Ops_type == OpsItemType::FloatNum || a.Ops_type == OpsItemType::FloatVar) && (b.Ops_type == OpsItemType::FloatNum || b.Ops_type == OpsItemType::FloatVar))
					{
						float result = GetFloat(a) / GetFloat(b);
						magazine.emplace(result, a.debuginfo);
					}
					else if ((a.Ops_type == OpsItemType::IntNum || a.Ops_type == OpsItemType::IntVar) && (b.Ops_type == OpsItemType::FloatNum || b.Ops_type == OpsItemType::FloatVar))
					{
						float result = GetInt(a) / GetFloat(b);
						magazine.emplace(result, a.debuginfo);
					}
					else if (((a.Ops_type == OpsItemType::FloatNum || a.Ops_type == OpsItemType::FloatVar) && (b.Ops_type == OpsItemType::IntNum || b.Ops_type == OpsItemType::IntVar)))
					{
						float result = GetFloat(a) / GetInt(b);
						magazine.emplace(result, a.debuginfo);
					}
					else
					{
						std::string errormsg = "Interpreter error - can't divide: unknow error;";
						throw InterDebug(errormsg, a.debuginfo);
					}
				}
				break;
			}
			case OpsItemOperation::Less:
			{
				auto b = magazine.top();
				magazine.pop();
				auto a = magazine.top();
				magazine.pop();

				float result;

				if (check_is_string(a, b, false))
				{
					std::string errormsg = "Interpreter error - can't compare string;";
					throw InterDebug(errormsg, a.debuginfo);
				}
				else
				{
					if ((a.Ops_type == OpsItemType::IntNum || a.Ops_type == OpsItemType::IntVar) && (b.Ops_type == OpsItemType::IntNum || b.Ops_type == OpsItemType::IntVar))
						magazine.emplace(GetInt(a) < GetInt(b), a.debuginfo);
					else if ((a.Ops_type == OpsItemType::FloatNum || a.Ops_type == OpsItemType::FloatVar) && (b.Ops_type == OpsItemType::FloatNum || b.Ops_type == OpsItemType::FloatVar))
						magazine.emplace(GetFloat(a) < GetFloat(b), a.debuginfo);
					else if ((a.Ops_type == OpsItemType::IntNum || a.Ops_type == OpsItemType::IntVar) && (b.Ops_type == OpsItemType::FloatNum || b.Ops_type == OpsItemType::FloatVar))
						magazine.emplace(GetInt(a) < GetFloat(b), a.debuginfo);
					else if (((a.Ops_type == OpsItemType::FloatNum || a.Ops_type == OpsItemType::FloatVar) && (b.Ops_type == OpsItemType::IntNum || b.Ops_type == OpsItemType::IntVar)))
						magazine.emplace(GetFloat(a) < GetInt(b), a.debuginfo);
					else 
					{
						std::string errormsg = "Interpreter error - can't compare: unknow error;";
						throw InterDebug(errormsg, a.debuginfo);
					}
				}
				break;
			}
			case OpsItemOperation::Assign:
			{
				auto b = magazine.top();
				magazine.pop();
				auto a = magazine.top();
				magazine.pop();

				float result;

				check_constant_for_assign(a, const_init_flag);

				if (a.Ops_type == OpsItemType::StringVar && (b.Ops_type == OpsItemType::StringVal || b.Ops_type == OpsItemType::StringVar))
					SetString(a, GetString(b));
				else if (a.Ops_type != OpsItemType::StringVar && a.Ops_type != OpsItemType::StringVal && b.Ops_type != OpsItemType::StringVal && b.Ops_type != OpsItemType::StringVar)
				{
					if (a.Ops_type == OpsItemType::IntVar && (b.Ops_type == OpsItemType::IntNum || b.Ops_type == OpsItemType::IntVar))
						SetInt(a, GetInt(b));
					else if (a.Ops_type == OpsItemType::FloatVar && (b.Ops_type == OpsItemType::IntVar || b.Ops_type == OpsItemType::IntNum))
						SetFloat(a, (float)GetInt(b));
					else if (a.Ops_type == OpsItemType::IntVar && (b.Ops_type == OpsItemType::FloatNum || b.Ops_type == OpsItemType::FloatVar))
					{
						std::string errormsg = "Interpreter error - can't assign float to int;";
						throw InterDebug(errormsg, a.debuginfo);
					}
					else if (a.Ops_type == OpsItemType::FloatVar)
						SetFloat(a, GetFloat(b));
					else
					{
						std::string errormsg = "Interpreter error - can't assign unknown types;";
						throw InterDebug(errormsg, a.debuginfo);
					}
				}
				else
				{
					std::string errormsg = "Interpreter error - can't assign string;";
					throw InterDebug(errormsg, a.debuginfo);
				}
				break;
			}
			case OpsItemOperation::More:
			{
				auto b = magazine.top();
				magazine.pop();
				auto a = magazine.top();
				magazine.pop();

				float result;

				if (check_is_string(a, b, false))
				{
					std::string errormsg = "Interpreter error - can't compare string;";
					throw InterDebug(errormsg, a.debuginfo);
				}
				else
				{
					if ((a.Ops_type == OpsItemType::IntNum || a.Ops_type == OpsItemType::IntVar) && (b.Ops_type == OpsItemType::IntNum || b.Ops_type == OpsItemType::IntVar))
						magazine.emplace(GetInt(a) > GetInt(b), a.debuginfo);
					else if ((a.Ops_type == OpsItemType::FloatNum || a.Ops_type == OpsItemType::FloatVar) && (b.Ops_type == OpsItemType::FloatNum || b.Ops_type == OpsItemType::FloatVar))
						magazine.emplace(GetFloat(a) > GetFloat(b), a.debuginfo);
					else if ((a.Ops_type == OpsItemType::IntNum || a.Ops_type == OpsItemType::IntVar) && (b.Ops_type == OpsItemType::FloatNum || b.Ops_type == OpsItemType::FloatVar))
						magazine.emplace(GetInt(a) > GetFloat(b), a.debuginfo);
					else if (((a.Ops_type == OpsItemType::FloatNum || a.Ops_type == OpsItemType::FloatVar) && (b.Ops_type == OpsItemType::IntNum || b.Ops_type == OpsItemType::IntVar)))
						magazine.emplace(GetFloat(a) > GetInt(b), a.debuginfo);
					else
					{
						std::string errormsg = "Interpreter error - can't compare: unknow error;";
						throw InterDebug(errormsg, a.debuginfo);
					}
				}
				break;
			}
			case OpsItemOperation::Equal:
			{
				auto b = magazine.top();
				magazine.pop();
				auto a = magazine.top();
				magazine.pop();

				float result;

				if (check_is_string(a, b, false))
				{
					magazine.emplace(GetString(a) == GetString(b), a.debuginfo);
				}
				else
				{
					if ((a.Ops_type == OpsItemType::IntNum || a.Ops_type == OpsItemType::IntVar) && (b.Ops_type == OpsItemType::IntNum || b.Ops_type == OpsItemType::IntVar))
						magazine.emplace(GetInt(a) == GetInt(b), a.debuginfo);
					else if ((a.Ops_type == OpsItemType::FloatNum || a.Ops_type == OpsItemType::FloatVar) && (b.Ops_type == OpsItemType::FloatNum || b.Ops_type == OpsItemType::FloatVar))
						magazine.emplace(GetFloat(a) == GetFloat(b), a.debuginfo);
					else if ((a.Ops_type == OpsItemType::IntNum || a.Ops_type == OpsItemType::IntVar) && (b.Ops_type == OpsItemType::FloatNum || b.Ops_type == OpsItemType::FloatVar))
						magazine.emplace(GetInt(a) == GetFloat(b), a.debuginfo);
					else if (((a.Ops_type == OpsItemType::FloatNum || a.Ops_type == OpsItemType::FloatVar) && (b.Ops_type == OpsItemType::IntNum || b.Ops_type == OpsItemType::IntVar)))
						magazine.emplace(GetFloat(a) == GetInt(b), a.debuginfo);
					else
					{
						std::string errormsg = "Interpreter error - can't compare: unknow error;";
						throw InterDebug(errormsg, a.debuginfo);
					}
				}
				break;
			}
			case OpsItemOperation::LessOrEqual:
			{
				auto b = magazine.top();
				magazine.pop();
				auto a = magazine.top();
				magazine.pop();

				float result;

				if (check_is_string(a, b, false))
				{
					std::string errormsg = "Interpreter error - can't compare string;";
					throw InterDebug(errormsg, a.debuginfo);
				}
				else
				{
					if ((a.Ops_type == OpsItemType::IntNum || a.Ops_type == OpsItemType::IntVar) && (b.Ops_type == OpsItemType::IntNum || b.Ops_type == OpsItemType::IntVar))
						magazine.emplace(GetInt(a) <= GetInt(b), a.debuginfo);
					else if ((a.Ops_type == OpsItemType::FloatNum || a.Ops_type == OpsItemType::FloatVar) && (b.Ops_type == OpsItemType::FloatNum || b.Ops_type == OpsItemType::FloatVar))
						magazine.emplace(GetFloat(a) <= GetFloat(b), a.debuginfo);
					else if ((a.Ops_type == OpsItemType::IntNum || a.Ops_type == OpsItemType::IntVar) && (b.Ops_type == OpsItemType::FloatNum || b.Ops_type == OpsItemType::FloatVar))
						magazine.emplace(GetInt(a) <= GetFloat(b), a.debuginfo);
					else if (((a.Ops_type == OpsItemType::FloatNum || a.Ops_type == OpsItemType::FloatVar) && (b.Ops_type == OpsItemType::IntNum || b.Ops_type == OpsItemType::IntVar)))
						magazine.emplace(GetFloat(a) <= GetInt(b), a.debuginfo);
					else
					{
						std::string errormsg = "Interpreter error - can't compare: unknow error;";
						throw InterDebug(errormsg, a.debuginfo);
					}
				}
				break;
			}
			case OpsItemOperation::MoreOrEqual:
			{
				auto b = magazine.top();
				magazine.pop();
				auto a = magazine.top();
				magazine.pop();

				float result;

				if (check_is_string(a, b, false))
				{
					std::string errormsg = "Interpreter error - can't compare string;";
					throw InterDebug(errormsg, a.debuginfo);
				}
				else
				{
					if ((a.Ops_type == OpsItemType::IntNum || a.Ops_type == OpsItemType::IntVar) && (b.Ops_type == OpsItemType::IntNum || b.Ops_type == OpsItemType::IntVar))
						magazine.emplace(GetInt(a) >= GetInt(b), a.debuginfo);
					else if ((a.Ops_type == OpsItemType::FloatNum || a.Ops_type == OpsItemType::FloatVar) && (b.Ops_type == OpsItemType::FloatNum || b.Ops_type == OpsItemType::FloatVar))
						magazine.emplace(GetFloat(a) >= GetFloat(b), a.debuginfo);
					else if ((a.Ops_type == OpsItemType::IntNum || a.Ops_type == OpsItemType::IntVar) && (b.Ops_type == OpsItemType::FloatNum || b.Ops_type == OpsItemType::FloatVar))
						magazine.emplace(GetInt(a) >= GetFloat(b), a.debuginfo);
					else if (((a.Ops_type == OpsItemType::FloatNum || a.Ops_type == OpsItemType::FloatVar) && (b.Ops_type == OpsItemType::IntNum || b.Ops_type == OpsItemType::IntVar)))
						magazine.emplace(GetFloat(a) >= GetInt(b), a.debuginfo);
					else
					{
						std::string errormsg = "Interpreter error - can't compare: unknow error;";
						throw InterDebug(errormsg, a.debuginfo);
					}
				}
				break;
			}
			case OpsItemOperation::NotEqual:
			{
				auto b = magazine.top();
				magazine.pop();
				auto a = magazine.top();
				magazine.pop();

				float result;

				if (check_is_string(a, b, false))
				{
					magazine.emplace(GetString(a) != GetString(b), a.debuginfo);
				}
				else
				{
					if ((a.Ops_type == OpsItemType::IntNum || a.Ops_type == OpsItemType::IntVar) && (b.Ops_type == OpsItemType::IntNum || b.Ops_type == OpsItemType::IntVar))
						magazine.emplace(GetInt(a) != GetInt(b), a.debuginfo);
					else if ((a.Ops_type == OpsItemType::FloatNum || a.Ops_type == OpsItemType::FloatVar) && (b.Ops_type == OpsItemType::FloatNum || b.Ops_type == OpsItemType::FloatVar))
						magazine.emplace(GetFloat(a) != GetFloat(b), a.debuginfo);
					else if ((a.Ops_type == OpsItemType::IntNum || a.Ops_type == OpsItemType::IntVar) && (b.Ops_type == OpsItemType::FloatNum || b.Ops_type == OpsItemType::FloatVar))
						magazine.emplace(GetInt(a) != GetFloat(b), a.debuginfo);
					else if (((a.Ops_type == OpsItemType::FloatNum || a.Ops_type == OpsItemType::FloatVar) && (b.Ops_type == OpsItemType::IntNum || b.Ops_type == OpsItemType::IntVar)))
						magazine.emplace(GetFloat(a) != GetInt(b), a.debuginfo);
					else
					{
						std::string errormsg = "Interpreter error - can't compare: unknow error;";
						throw InterDebug(errormsg, a.debuginfo);
					}
				}
				break;
			}
			case OpsItemOperation::Jump:
			{
				auto mark = magazine.top();
				magazine.pop();

				i = GetInt(mark) - 1;
				break;
			}
			case OpsItemOperation::JumpIfElse:
			{
				auto mark = magazine.top();
				magazine.pop();

				auto cond = magazine.top();
				magazine.pop();

				if (GetInt(cond) == 0) i = GetInt(mark) - 1;
				break;
			}
			case OpsItemOperation::Index:
			{
				auto ind = magazine.top();
				magazine.pop();
				auto array_name = magazine.top();
				magazine.pop();

				array_name.Num_Val = GetInt(ind);

				magazine.push(array_name);
				break;
			}
			case OpsItemOperation::Memory:
			{
				auto amount = magazine.top(); 
				magazine.pop();
				auto arr = magazine.top(); 
				magazine.pop();

				AllocateMemory(arr, GetInt(amount));
				magazine.push(arr);
				break;
			}
			default:
			{
				std::string errormsg = "Interpreter error - Unknown operation;";
				throw InterDebug(errormsg, ops_data[i].debuginfo);
			}
			}
		}
		}
	}
}

void OpsInterpret::SetInt(OpsItem& ops_item, int num)
{
	if (input_ops.int_table.count(ops_item.variable_name))
	{
		input_ops.int_table[ops_item.variable_name] = num;
	}
	else if (input_ops.massInt_table.count(ops_item.variable_name))
	{
		input_ops.massInt_table[ops_item.variable_name][(int)ops_item.Num_Val] = num;
	}
	else
	{
		std::string errormsg = "Interpreter error - int variable was expected;";
		throw InterDebug(errormsg, ops_item.debuginfo);
	}
}

bool OpsInterpret::check_constant_for_assign(OpsItem& a, std::map<std::string, int>& const_flags)
{
	if (const_flags.count(a.variable_name))
	{
		if (const_flags[a.variable_name] == 0)
		{
			const_flags[a.variable_name] = 1;
			return true;
		}
		else
		{
			std::string errormsg = "Interpreter error - constant can't be changed after init;";
			throw InterDebug(errormsg, a.debuginfo);
		}
	}
	else 
		return true;

	return false;
}

void OpsInterpret::SetFloat(OpsItem& ops_item, float num)
{
	if (input_ops.float_table.count(ops_item.variable_name))
	{
		input_ops.float_table[ops_item.variable_name] = num;
	}
	else if (input_ops.massFloat_table.count(ops_item.variable_name))
	{
		input_ops.massFloat_table[ops_item.variable_name][(int)ops_item.Num_Val] = num;
	}
	else
	{
		std::string errormsg = "Interpreter error - float variable was expected;";
		throw InterDebug(errormsg, ops_item.debuginfo);
	}
}

bool OpsInterpret::check_constant(OpsItem& a, std::map<std::string, int>& const_flags)
{
	if (const_flags.count(a.variable_name))
	{
		if (const_flags[a.variable_name] == 0)
		{
			const_flags[a.variable_name] = 1;
			return true;
		}
		else
		{
			std::string errormsg = "Interpreter error - constant can't be changed after init;";
			throw InterDebug(errormsg, a.debuginfo);
		}
	}
	else
		return true;
	return false;
}

void OpsInterpret::SetString(OpsItem& ops_item, std::string str)
{
	if (input_ops.string_table.count(ops_item.variable_name))
	{
		input_ops.string_table[ops_item.variable_name] = str;
	}
	else
	{
		std::string errormsg = "Ops Interpreter error - string variable was expected;";
		throw InterDebug(errormsg, ops_item.debuginfo);
	}
}

void OpsInterpret::ResizeMemory(OpsItem& passport, int amount)
{
	if (amount <= 0)
	{
		std::string errormsg = "Ops Interpreter error - New array size can't be 0 and less;";
		throw InterDebug(errormsg, passport.debuginfo);
	}
	switch (passport.Ops_type)
	{
	case OpsItemType::IntVar:
	{
		if (input_ops.massInt_table.count(passport.variable_name))
				input_ops.massInt_table[passport.variable_name].resize(amount);
		else
		{
			std::string errormsg = "Ops Interpreter error - unknown int array passport;";
			throw InterDebug(errormsg, passport.debuginfo);
		}
		break;
	}
	case OpsItemType::FloatVar:
	{
		if (input_ops.massFloat_table.count(passport.variable_name))
				input_ops.massFloat_table[passport.variable_name].resize(amount);
		else
		{
			std::string errormsg = "Ops Interpreter error - unknown float array passport;";
			throw InterDebug(errormsg, passport.debuginfo);
		}
		break;
	}
	default:
	{
		std::string errormsg = "Ops Interpreter error - unknown array passport;";
		throw InterDebug(errormsg, passport.debuginfo);
	}
	}
}

int OpsInterpret::GetInt(OpsItem& ops_item)
{
	if (ops_item.Ops_type == OpsItemType::IntNum)
	{
		return (int)ops_item.Num_Val;
	}
	else if (input_ops.int_table.count(ops_item.variable_name))
	{
		return input_ops.int_table[ops_item.variable_name];
	}
	else if (input_ops.massInt_table.count(ops_item.variable_name))
	{
		return input_ops.massInt_table[ops_item.variable_name][(int)ops_item.Num_Val];
	}
	else
	{
		std::string errormsg = "Ops Interpreter error - int variable or int number was expected;";
		throw InterDebug(errormsg, ops_item.debuginfo);
	}
}

float OpsInterpret::GetFloat(OpsItem& ops_item)
{
	if (ops_item.Ops_type == OpsItemType::FloatNum)
	{
		return (float)ops_item.Num_Val;
	}
	else if (input_ops.float_table.count(ops_item.variable_name))
	{
		return input_ops.float_table[ops_item.variable_name];
	}
	else if (input_ops.massFloat_table.count(ops_item.variable_name))
	{
		return input_ops.massFloat_table[ops_item.variable_name][(int)ops_item.Num_Val];
	}
	else
	{
		std::string errormsg = "Ops Interpreter error - float variable or float number was expected;";
		throw InterDebug(errormsg, ops_item.debuginfo);
	}
}

std::string OpsInterpret::GetString(OpsItem& ops_item)
{
	if (ops_item.Ops_type == OpsItemType::StringVal)
	{
		return ops_item.string_val;
	}
	else if (input_ops.string_table.count(ops_item.variable_name))
	{
		return input_ops.string_table[ops_item.variable_name];
	}
	else
	{
		std::string errormsg = "Ops Interpreter error - string variable or string value was expected;";
		throw InterDebug(errormsg, ops_item.debuginfo);
	}
}


OpsInterpret::OpsInterpret(InterData id)
{
	input_ops = id;
}



void OpsInterpret::AllocateMemory(OpsItem& passport, int amount)
{
	switch (passport.Ops_type)
	{
	case OpsItemType::IntVar:
	{
		if (input_ops.massInt_table.count(passport.variable_name))
		{
			if (input_ops.massInt_table[passport.variable_name].size() > 0)
			{
				std::string errormsg = "Ops Interpreter error - memory for array is already initialized;";
				throw InterDebug(errormsg, passport.debuginfo);
			}
			else
			{
				input_ops.massInt_table[passport.variable_name].resize(amount);
			}
		}
		else
		{
			std::string errormsg = "Ops Interpreter error - unknown int array passport;";
			throw InterDebug(errormsg, passport.debuginfo);
		}
	}
	break;
	case OpsItemType::FloatVar:
	{
		if (input_ops.massFloat_table.count(passport.variable_name))
		{
			if (input_ops.massFloat_table[passport.variable_name].size() > 0)
			{
				std::string errormsg = "Ops Interpreter error - memory for array is already initialized;";
				throw InterDebug(errormsg, passport.debuginfo);
			}
			else
			{
				input_ops.massFloat_table[passport.variable_name].resize(amount);
			}
		}
		else
		{
			std::string errormsg = "Ops Interpreter error - unknown float array passport;";
			throw InterDebug(errormsg, passport.debuginfo);
		}
	}
	break;
	default:
	{
		std::string errormsg = "Ops Interpreter error - unknown array passport or invalid array type;";
		throw InterDebug(errormsg, passport.debuginfo);
	}
	}
}

