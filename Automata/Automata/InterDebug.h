#pragma once
#include <exception>
#include <string>

struct DebugInfo
{
	int debug_line;
	int debug_position;
};

struct InterDebug : public std::exception
{
	std::string debug_message;

	InterDebug(std::string msg, DebugInfo dinfo){
		debug_message = "\n ### Debug info ###\n\nLine = " + std::to_string(dinfo.debug_line) + "\npos = " + std::to_string(dinfo.debug_position) + "\n\n" + msg + "\n\n###################";
	}

	const char* what() const throw(){
		return debug_message.c_str();
	}
};

