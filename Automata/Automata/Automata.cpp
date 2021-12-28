#include <iostream>
#include <fstream>

#include<string>
#include "LexAnalyzer.h"
#include "OpsGenerator.h"
#include "OpsInterpret.h"


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
         for (auto& Opsi : MyOps)
         {
             switch (Opsi.Ops_type)
             {
             case OpsItemType::Error: std::cout << "ERROR "; break;
             case OpsItemType::FloatNum: std::cout << OpsData.ops_item[i].Num_Val<< " "; break;
             case OpsItemType::FloatVar: std::cout << OpsData.ops_item[i].variable_name<<" "; break;
             case OpsItemType::IntNum:std::cout << OpsData.ops_item[i].Num_Val << " "; break;
             case OpsItemType::IntVar:std::cout << OpsData.ops_item[i].variable_name << " "; break;
             case OpsItemType::Operation: 
             {
                 switch (OpsData.ops_item[i].Ops_operation)
                 {
                 case OpsItemOperation::Assign:  std::cout << "= "; break;
                 case OpsItemOperation::Divide:  std::cout << "/ "; break;
                 case OpsItemOperation::Equal:  std::cout << "== "; break;
                 case OpsItemOperation::Error:  std::cout << "ERROR "; break;
                 case OpsItemOperation::Index:  std::cout << "I "; break;
                 case OpsItemOperation::Jump:  std::cout << "J "; break;
                 case OpsItemOperation::JumpIfElse:  std::cout << "JF "; break;
                 case OpsItemOperation::Less:  std::cout << "< "; break;
                 case OpsItemOperation::LessOrEqual:  std::cout << "<= "; break;
                 case OpsItemOperation::Memory:  std::cout << "M "; break;
                 case OpsItemOperation::Minus:  std::cout << "- "; break;
                 case OpsItemOperation::More:  std::cout << "> "; break;
                 case OpsItemOperation::MoreOrEqual:  std::cout << ">- "; break;
                 case OpsItemOperation::Multiply:  std::cout << "* "; break;
                 case OpsItemOperation::NotEqual:  std::cout << "!= "; break;
                 case OpsItemOperation::Plus:  std::cout << "+ "; break;
                 case OpsItemOperation::Read:  std::cout << "R "; break;
                 case OpsItemOperation::Resize:  std::cout << "RE "; break;
                 case OpsItemOperation::UnarMinus:  std::cout << "-' "; break;
                 case OpsItemOperation::Write:  std::cout << "W "; break;
                 }
                 break;
             }
             case OpsItemType::StringVal:std::cout << OpsData.ops_item[i].string_val << " "; break;
             case OpsItemType::StringVar:std::cout << OpsData.ops_item[i].variable_name << " "; break;
            }
             i++;
         }

        std::cout << std::endl <<"Ops interpretating: \n\n";

        OpsInterpret MyOpsInt(OpsData);
        MyOpsInt.AnalyzeOps();
        
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
    system("pause");
}