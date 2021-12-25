#include <iostream>
#include <fstream>

#include<string>
#include "LexAnalyzer.h"


int main()     
{
    std::string file_name;
    std::string file_text;

    std::cout << "Enter file with program: ";
    std::cin >> file_name;

    std::ifstream Opened_file = std::ifstream(file_name);
    std::getline(Opened_file, file_text, '\0');

    std::cout << "Trying to run " + file_name << std::endl;

    try
    {
        LexAnalyzer MyAnalyzer(file_text);
        MyAnalyzer.Start();
    }
    catch (const std::exception& excep)
    {
        std::cerr << excep.what() << std::endl;
    }
}