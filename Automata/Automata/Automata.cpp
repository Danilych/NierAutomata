#include <iostream>
#include <fstream>

#include<string>
#include "LexAnalyzer.h"
#include "OpsGenerator.h"


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
        std::vector<LexemeInfo> LexemesBuffer =  MyAnalyzer.GetLexemesData();
        OpsGenerator MyOpsGen(LexemesBuffer);
        InterData OpsData = MyOpsGen.GetOpsData();

        std::vector<OpsItem> MyOps = OpsData.ops_item;

        std::cout << std::endl <<"Your ops: \n\n";
        int i = 0;
         for (auto& Opsi : MyOps) // access by reference to avoid copying
         {
             switch (Opsi.Ops_type)
             {
             case OpsItemType::Error: std::cout << "ERROR "; break;
             case OpsItemType::FloatNum: std::cout << OpsData.ops_item[i].Num_Val<< " "; break;
             case OpsItemType::FloatVar: std::cout << OpsData.ops_item[i].variable_name<<" "; break;
             case OpsItemType::IntNum:std::cout << OpsData.ops_item[i].Num_Val << " "; break;
             case OpsItemType::IntVar:std::cout << OpsData.ops_item[i].variable_name << " "; break;
             case OpsItemType::Operation: std::cout << "Oper "; break;
             case OpsItemType::StringVal:std::cout << OpsData.ops_item[i].string_val << " "; break;
             case OpsItemType::StringVar:std::cout << OpsData.ops_item[i].variable_name << " "; break;
            }
             i++;
         }

        //std::cout << std::endl <<"Your lexemes: \n\n";

        //for (auto& Lexeme : LexemesBuffer) // access by reference to avoid copying
        //{
        //    if(Lexeme.lex_type == LexemeType::Finish) std::cout <<"Finish" << std::endl;
        //    else std::cout << Lexeme.lex_value << std::endl;
        //}
    }
    catch (const std::exception& excep)
    {
        std::cerr << excep.what() << std::endl;
    }
}