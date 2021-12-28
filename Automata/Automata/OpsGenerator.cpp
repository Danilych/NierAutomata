#include "OpsGenerator.h"

void OpsGenerator::GrammNonterminal()
{
    switch (current_nonterminal)
    {
        case Nonterminal::S:
        {
            switch (current_lexeme.lex_type)
            {
            case LexemeType::Const:
            {
                magazine.emplace(Nonterminal::S);
                magazine.emplace(Nonterminal::O);
                magazine.emplace(LexemeType::Const);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            case LexemeType::IntType:
            {
                magazine.emplace(Nonterminal::S);
                magazine.emplace(Nonterminal::I);
                magazine.emplace(LexemeType::IntType);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task7);
                break;
            }
            case LexemeType::FloatType:
            {
                magazine.emplace(Nonterminal::S);
                magazine.emplace(Nonterminal::I);
                magazine.emplace(LexemeType::FloatType);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task8);
                break;
            }
            case LexemeType::StringType:
            {
                magazine.emplace(Nonterminal::S);
                magazine.emplace(Nonterminal::I);
                magazine.emplace(LexemeType::StringType);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task9);
                break;
            }
            case LexemeType::Array:
            {
                magazine.emplace(Nonterminal::S);
                magazine.emplace(Nonterminal::G);
                magazine.emplace(LexemeType::Array);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            case LexemeType::VarName:
            {
                if(current_table == vartable::String)
                {
                    magazine.emplace(Nonterminal::Q);
                    magazine.emplace(LexemeType::Semicolon);
                    magazine.emplace(Nonterminal::Y);
                    magazine.emplace(LexemeType::Assign);
                    magazine.emplace(LexemeType::VarName);

                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Assign);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::VariableId);
                    break;
                }
                else
                {
                    magazine.emplace(Nonterminal::Q);
                    magazine.emplace(LexemeType::Semicolon);
                    magazine.emplace(Nonterminal::E);
                    magazine.emplace(LexemeType::Assign);
                    magazine.emplace(Nonterminal::H);
                    magazine.emplace(LexemeType::VarName);

                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Assign);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::VariableId);
                    break;
                }
            }
            case LexemeType::If:
            {
                magazine.emplace(Nonterminal::Q);
                magazine.emplace(Nonterminal::Z);
                magazine.emplace(Nonterminal::K);
                magazine.emplace(LexemeType::RightBrace);
                magazine.emplace(Nonterminal::Q);
                magazine.emplace(Nonterminal::A);
                magazine.emplace(LexemeType::LeftBrace);
                magazine.emplace(LexemeType::RightRoundBracket);
                magazine.emplace(Nonterminal::C);
                magazine.emplace(LexemeType::LeftRoundBracket);
                magazine.emplace(LexemeType::If);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task3);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task1);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            case LexemeType::While:
            {
                magazine.emplace(Nonterminal::Q);
                magazine.emplace(LexemeType::RightBrace);
                magazine.emplace(Nonterminal::Q);
                magazine.emplace(Nonterminal::A);
                magazine.emplace(LexemeType::LeftBrace);
                magazine.emplace(LexemeType::RightRoundBracket);
                magazine.emplace(Nonterminal::C);
                magazine.emplace(LexemeType::LeftRoundBracket);
                magazine.emplace(LexemeType::While);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task5);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task1);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task4);
                break;
            }
            case LexemeType::For:
            {
                magazine.emplace(Nonterminal::Q);
                magazine.emplace(LexemeType::RightBrace);
                magazine.emplace(Nonterminal::Q);
                magazine.emplace(Nonterminal::A);
                magazine.emplace(LexemeType::LeftBrace);
                magazine.emplace(LexemeType::RightRoundBracket);
                magazine.emplace(Nonterminal::P);
                magazine.emplace(LexemeType::Semicolon);
                magazine.emplace(Nonterminal::C);
                //magazine.emplace(LexemeType::Semicolon);
                magazine.emplace(Nonterminal::P);
                magazine.emplace(LexemeType::LeftRoundBracket);
                magazine.emplace(LexemeType::For);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task5);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task1);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                //generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task4);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            case LexemeType::Read:
            {
                magazine.emplace(Nonterminal::Q);
                magazine.emplace(LexemeType::Semicolon);
                magazine.emplace(LexemeType::RightRoundBracket);
                magazine.emplace(Nonterminal::H);
                magazine.emplace(LexemeType::VarName);
                magazine.emplace(LexemeType::LeftRoundBracket);
                magazine.emplace(LexemeType::Read);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Read);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::VariableId);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            case LexemeType::Write:
            {
                magazine.emplace(Nonterminal::Q);
                magazine.emplace(LexemeType::Semicolon);
                magazine.emplace(LexemeType::RightRoundBracket);
                magazine.emplace(Nonterminal::E);
                magazine.emplace(LexemeType::LeftRoundBracket);
                magazine.emplace(LexemeType::Write);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Write);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            case LexemeType::Resize:
            {
                magazine.emplace(Nonterminal::Q);
                magazine.emplace(LexemeType::Semicolon);
                magazine.emplace(LexemeType::RightRoundBracket);
                magazine.emplace(Nonterminal::E);
                magazine.emplace(LexemeType::Comma);
                magazine.emplace(LexemeType::VarName);
                magazine.emplace(LexemeType::LeftRoundBracket);
                magazine.emplace(LexemeType::Resize);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Resize);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::VariableId);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            default:
            {
                std::string errormsg = "Ops Generator error S - Unexpected lexeme;";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            }
            break;
        }
        case Nonterminal::G:
        {
            switch (current_lexeme.lex_type)
            {
            case LexemeType::IntType:
            {
                magazine.emplace(Nonterminal::J);
                magazine.emplace(LexemeType::IntType);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task7);
                break;
            }
            case LexemeType::FloatType:
            {
                magazine.emplace(Nonterminal::J);
                magazine.emplace(LexemeType::FloatType);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task8);
                break;
            }
            default:
            {
                std::string errormsg = "Ops Generator error G - Unexpected lexeme;";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            }
            break;
        }
        case Nonterminal::O:
        {
            switch (current_lexeme.lex_type)
            {
            case LexemeType::IntType:
            {
                magazine.emplace(Nonterminal::B);
                magazine.emplace(LexemeType::IntType);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task7);
                break;
            }
            case LexemeType::FloatType:
            {
                magazine.emplace(Nonterminal::B);
                magazine.emplace(LexemeType::FloatType);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task8);
                break;
            }
            case LexemeType::StringType:
            {
                magazine.emplace(Nonterminal::B);
                magazine.emplace(LexemeType::StringType);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task9);
                break;
            }

            default:
            {
                std::string errormsg = "Ops Generator error O - Unexpected lexeme;";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            }
            break;
        }
        case Nonterminal::Q:
        {
            switch (current_lexeme.lex_type)
            {
                case LexemeType::While:
                {
                    magazine.emplace(Nonterminal::Q);
                    magazine.emplace(LexemeType::RightBrace);
                    magazine.emplace(Nonterminal::Q);
                    magazine.emplace(Nonterminal::A);
                    magazine.emplace(LexemeType::LeftBrace);
                    magazine.emplace(LexemeType::RightRoundBracket);
                    magazine.emplace(Nonterminal::C);
                    magazine.emplace(LexemeType::LeftRoundBracket);
                    magazine.emplace(LexemeType::While);

                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Task5);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Task1);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Task4);
                    break;
                }
                case LexemeType::If:
                {
                    magazine.emplace(Nonterminal::Q);
                    magazine.emplace(Nonterminal::Z);
                    magazine.emplace(Nonterminal::K);
                    magazine.emplace(LexemeType::RightBrace);
                    magazine.emplace(Nonterminal::Q);
                    magazine.emplace(Nonterminal::A);
                    magazine.emplace(LexemeType::LeftBrace);
                    magazine.emplace(LexemeType::RightRoundBracket);
                    magazine.emplace(Nonterminal::C);
                    magazine.emplace(LexemeType::LeftRoundBracket);
                    magazine.emplace(LexemeType::If);

                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Task3);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Task1);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    break;
                }
                case LexemeType::For:
                {
                    magazine.emplace(Nonterminal::Q);
                    magazine.emplace(LexemeType::RightBrace);
                    magazine.emplace(Nonterminal::Q);
                    magazine.emplace(Nonterminal::A);
                    magazine.emplace(LexemeType::LeftBrace);
                    magazine.emplace(LexemeType::RightRoundBracket);
                    magazine.emplace(Nonterminal::P);
                    magazine.emplace(LexemeType::Semicolon);
                    magazine.emplace(Nonterminal::C);
                   // magazine.emplace(LexemeType::Semicolon);
                    magazine.emplace(Nonterminal::P);
                    magazine.emplace(LexemeType::LeftRoundBracket);
                    magazine.emplace(LexemeType::For);

                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Task5);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Task1);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                   // generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Task4);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    break;
                }
                case LexemeType::Read:
                {
                    magazine.emplace(Nonterminal::Q);
                    magazine.emplace(LexemeType::Semicolon);
                    magazine.emplace(LexemeType::RightRoundBracket);
                    magazine.emplace(Nonterminal::H);
                    magazine.emplace(LexemeType::VarName);
                    magazine.emplace(LexemeType::LeftRoundBracket);
                    magazine.emplace(LexemeType::Read);

                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Read);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::VariableId);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    break;
                }
                case LexemeType::Write:
                {
                    magazine.emplace(Nonterminal::Q);
                    magazine.emplace(LexemeType::Semicolon);
                    magazine.emplace(LexemeType::RightRoundBracket);
                    magazine.emplace(Nonterminal::E);
                    magazine.emplace(LexemeType::LeftRoundBracket);
                    magazine.emplace(LexemeType::Write);

                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Write);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    break;
                }
                case LexemeType::Resize:
                {
                    magazine.emplace(Nonterminal::Q);
                    magazine.emplace(LexemeType::Semicolon);
                    magazine.emplace(LexemeType::RightRoundBracket);
                    magazine.emplace(Nonterminal::E);
                    magazine.emplace(LexemeType::Comma);
                    magazine.emplace(LexemeType::VarName);
                    magazine.emplace(LexemeType::LeftRoundBracket);
                    magazine.emplace(LexemeType::Resize);

                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Resize);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::VariableId);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    break;
                }
                case LexemeType::VarName:
                {
                    if (current_table == vartable::String)
                    {
                        magazine.emplace(Nonterminal::Q);
                        magazine.emplace(LexemeType::Semicolon);
                        magazine.emplace(Nonterminal::Y);
                        magazine.emplace(LexemeType::Assign);
                        magazine.emplace(LexemeType::VarName);

                        generator.emplace(GeneratorTask::Empty);
                        generator.emplace(GeneratorTask::Assign);
                        generator.emplace(GeneratorTask::Empty);
                        generator.emplace(GeneratorTask::Empty);
                        generator.emplace(GeneratorTask::VariableId);
                        break;
                    }
                    else
                    {
                        magazine.emplace(Nonterminal::Q);
                        magazine.emplace(LexemeType::Semicolon);
                        magazine.emplace(Nonterminal::E);
                        magazine.emplace(LexemeType::Assign);
                        magazine.emplace(Nonterminal::H);
                        magazine.emplace(LexemeType::VarName);

                        generator.emplace(GeneratorTask::Empty);
                        generator.emplace(GeneratorTask::Assign);
                        generator.emplace(GeneratorTask::Empty);
                        generator.emplace(GeneratorTask::Empty);
                        generator.emplace(GeneratorTask::Empty);
                        generator.emplace(GeneratorTask::VariableId);
                        break;
                    }
                }
            }
            break;
        }
        case Nonterminal::A:
        {
            switch (current_lexeme.lex_type)
            {
            case LexemeType::While:
            {
                magazine.emplace(LexemeType::RightBrace);
                magazine.emplace(Nonterminal::Q);
                magazine.emplace(Nonterminal::A);
                magazine.emplace(LexemeType::LeftBrace);
                magazine.emplace(LexemeType::RightRoundBracket);
                magazine.emplace(Nonterminal::C);
                magazine.emplace(LexemeType::LeftRoundBracket);
                magazine.emplace(LexemeType::While);

                generator.emplace(GeneratorTask::Task5);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task1);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task4);
                break;
            }
            case LexemeType::If:
            {
                magazine.emplace(Nonterminal::Z);
                magazine.emplace(Nonterminal::K);
                magazine.emplace(LexemeType::RightBrace);
                magazine.emplace(Nonterminal::Q);
                magazine.emplace(Nonterminal::A);
                magazine.emplace(LexemeType::LeftBrace);
                magazine.emplace(LexemeType::RightRoundBracket);
                magazine.emplace(Nonterminal::C);
                magazine.emplace(LexemeType::LeftRoundBracket);
                magazine.emplace(LexemeType::If);

                generator.emplace(GeneratorTask::Task3);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task1);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            case LexemeType::For:
            {
                magazine.emplace(LexemeType::RightBrace);
                magazine.emplace(Nonterminal::Q);
                magazine.emplace(Nonterminal::A);
                magazine.emplace(LexemeType::LeftBrace);
                magazine.emplace(LexemeType::RightRoundBracket);
                magazine.emplace(Nonterminal::P);
                magazine.emplace(LexemeType::Semicolon);
                magazine.emplace(Nonterminal::C);
                //magazine.emplace(LexemeType::Semicolon);
                magazine.emplace(Nonterminal::P);
                magazine.emplace(LexemeType::LeftRoundBracket);
                magazine.emplace(LexemeType::For);

                generator.emplace(GeneratorTask::Task5);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task1);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
               // generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task4);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            case LexemeType::Read:
            {
                magazine.emplace(LexemeType::Semicolon);
                magazine.emplace(LexemeType::RightRoundBracket);
                magazine.emplace(Nonterminal::H);
                magazine.emplace(LexemeType::VarName);
                magazine.emplace(LexemeType::LeftRoundBracket);
                magazine.emplace(LexemeType::Read);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Read);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::VariableId);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            case LexemeType::Write:
            {
                magazine.emplace(LexemeType::Semicolon);
                magazine.emplace(LexemeType::RightRoundBracket);
                magazine.emplace(Nonterminal::E);
                magazine.emplace(LexemeType::LeftRoundBracket);
                magazine.emplace(LexemeType::Write);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Write);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            case LexemeType::Resize:
            {
                magazine.emplace(LexemeType::Semicolon);
                magazine.emplace(LexemeType::RightRoundBracket);
                magazine.emplace(Nonterminal::E);
                magazine.emplace(LexemeType::Comma);
                magazine.emplace(LexemeType::VarName);
                magazine.emplace(LexemeType::LeftRoundBracket);
                magazine.emplace(LexemeType::Resize);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Resize);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::VariableId);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            case LexemeType::VarName:
            {
                if (current_table == vartable::String)
                {
                    magazine.emplace(LexemeType::Semicolon);
                    magazine.emplace(Nonterminal::Y);
                    magazine.emplace(LexemeType::Assign);
                    magazine.emplace(LexemeType::VarName);

                    generator.emplace(GeneratorTask::Assign);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::VariableId);
                    break;
                }
                else
                {
                    magazine.emplace(LexemeType::Semicolon);
                    magazine.emplace(Nonterminal::E);
                    magazine.emplace(LexemeType::Assign);
                    magazine.emplace(Nonterminal::H);
                    magazine.emplace(LexemeType::VarName);

                    generator.emplace(GeneratorTask::Assign);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::VariableId);
                    break;
                }
            }
            default:
            {
                std::string errormsg = "Ops Generator error A - Unexpected lexeme;";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            }
            break;
        }
        case Nonterminal::Y: 
        {
            switch (current_lexeme.lex_type)
            {
            case LexemeType::VarName: 
            {
                magazine.emplace(LexemeType::VarName);

                generator.emplace(GeneratorTask::VariableId);
                break;
            }
            case LexemeType::StringVal:
            {
                magazine.emplace(LexemeType::StringVal);

                generator.emplace(GeneratorTask::StringVal);
                break;
            }
            default:
            {
                std::string errormsg = "Ops Generator error Y - Unexpected lexeme;";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            }
            break;
        }
        case Nonterminal::B:
        {
            switch (current_lexeme.lex_type)
            {
            case LexemeType::VarName:
            {
                if (current_table == vartable::String)
                {
                    magazine.emplace(Nonterminal::D);
                    magazine.emplace(LexemeType::StringVal);
                    magazine.emplace(LexemeType::Assign);
                    magazine.emplace(LexemeType::VarName);

                    generator.emplace(GeneratorTask::Assign);
                    generator.emplace(GeneratorTask::StringVal);  
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Task11);
                    break;
                }
                else if(current_table == vartable::Int)
                {
                    magazine.emplace(Nonterminal::D);
                    magazine.emplace(LexemeType::IntNum);
                    magazine.emplace(LexemeType::Assign);
                    magazine.emplace(LexemeType::VarName);

                    generator.emplace(GeneratorTask::Assign);
                    generator.emplace(GeneratorTask::IntNumber);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Task11);
                    break;
                }
                else if (current_table == vartable::Float)
                {
                    magazine.emplace(Nonterminal::D);
                    magazine.emplace(LexemeType::FloatNum);
                    magazine.emplace(LexemeType::Assign);
                    magazine.emplace(LexemeType::VarName);

                    generator.emplace(GeneratorTask::Assign);
                    generator.emplace(GeneratorTask::FloatNumber);
                    generator.emplace(GeneratorTask::Empty);
                    generator.emplace(GeneratorTask::Task11);
                    break;
                }
            }
            default:
            {
                std::string errormsg = "Ops Generator error B - Unexpected lexeme;";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            }
            break;
        }
        case Nonterminal::D:
        {
            switch (current_lexeme.lex_type)
            {
            case LexemeType::Semicolon:
            {
                magazine.emplace(LexemeType::Semicolon);

                generator.emplace(GeneratorTask::Empty);
                break;
            }
            case LexemeType::Comma:
            {
                magazine.emplace(Nonterminal::B);
                magazine.emplace(LexemeType::Comma);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            default:
            {
                std::string errormsg = "Ops Generator error D - Unexpected lexeme;";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            }
            break;
        }
        case Nonterminal::P:
        {
            switch (current_lexeme.lex_type)
            {
            case LexemeType::VarName:
            {
                magazine.emplace(LexemeType::Semicolon);
                magazine.emplace(Nonterminal::E);
                magazine.emplace(LexemeType::Assign);
                magazine.emplace(LexemeType::VarName);

                generator.emplace(GeneratorTask::Assign);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::VariableId);
                break;
            }
            default:
            {
                std::string errormsg = "Ops Generator error P - Unexpected lexeme;";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            }
            break;
        }
        case Nonterminal::I:
        {
            switch (current_lexeme.lex_type)
            {
            case LexemeType::VarName:
            {
                magazine.emplace(Nonterminal::M);
                magazine.emplace(LexemeType::VarName);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task6);
                break;
            }
            default:
            {
                std::string errormsg = "Ops Generator error I - Unexpected lexeme;";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            }
            break;
        }
        case Nonterminal::M:
        {
            switch (current_lexeme.lex_type)
            {
            case LexemeType::Semicolon:
            {
                magazine.emplace(LexemeType::Semicolon);

                generator.emplace(GeneratorTask::Empty);
                break;
            }
            case LexemeType::Comma:
            {
                magazine.emplace(Nonterminal::M);
                magazine.emplace(LexemeType::VarName);
                magazine.emplace(LexemeType::Comma);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task6);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            default:
            {
                std::string errormsg = "Ops Generator error M - Unexpected lexeme;";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            }
            break;
        }
        case Nonterminal::J:
        {
            switch (current_lexeme.lex_type)
            {
            case LexemeType::VarName:
            {
                magazine.emplace(Nonterminal::N);
                magazine.emplace(LexemeType::RightSquareBracket);
                magazine.emplace(LexemeType::IntNum);
                magazine.emplace(LexemeType::LeftSquareBracket);
                magazine.emplace(LexemeType::VarName);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Memory);
                generator.emplace(GeneratorTask::IntNumber);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task10);
                break;
            }
            default:
            {
                std::string errormsg = "Ops Generator error J - Unexpected lexeme;";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            }
            break;
        }
        case Nonterminal::N:
        {
            switch (current_lexeme.lex_type)
            {
            case LexemeType::Comma:
            {
                magazine.emplace(Nonterminal::N);
                magazine.emplace(LexemeType::RightSquareBracket);
                magazine.emplace(LexemeType::IntNum);
                magazine.emplace(LexemeType::LeftSquareBracket);
                magazine.emplace(LexemeType::VarName);
                magazine.emplace(LexemeType::Comma);

                generator.emplace(GeneratorTask::Task6);
                generator.emplace(GeneratorTask::Task10);
                generator.emplace(GeneratorTask::IntNumber);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            case LexemeType::Semicolon:
            {
                magazine.emplace(LexemeType::Semicolon);

                generator.emplace(GeneratorTask::Empty);
                break;
            }
            default:
            {
                std::string errormsg = "Ops Generator error N - Unexpected lexeme;";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            }
            break;
        }
        case Nonterminal::H:
        {
            switch (current_lexeme.lex_type)
            {
            case LexemeType::LeftSquareBracket:
            {
                magazine.emplace(LexemeType::RightSquareBracket);
                magazine.emplace(Nonterminal::E);
                magazine.emplace(LexemeType::LeftSquareBracket);

                generator.emplace(GeneratorTask::Index);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            }
            break;
        }
        case Nonterminal::C:
        {
            switch (current_lexeme.lex_type)
            {
            case LexemeType::VarName:
            {
                magazine.emplace(Nonterminal::L);
                magazine.emplace(Nonterminal::U);
                magazine.emplace(Nonterminal::V);
                magazine.emplace(Nonterminal::H);
                magazine.emplace(LexemeType::VarName);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::VariableId);
                break;
            }
            case LexemeType::Plus:
            {
                magazine.emplace(Nonterminal::L);
                magazine.emplace(Nonterminal::U);
                magazine.emplace(Nonterminal::V);
                magazine.emplace(Nonterminal::F);
                magazine.emplace(LexemeType::Plus);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            case LexemeType::Minus:
            {
                magazine.emplace(Nonterminal::L);
                magazine.emplace(Nonterminal::U);
                magazine.emplace(Nonterminal::V);
                magazine.emplace(Nonterminal::F);
                magazine.emplace(LexemeType::Minus);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::UnarMinus);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            case LexemeType::IntNum:
            {
                magazine.emplace(Nonterminal::L);
                magazine.emplace(Nonterminal::U);
                magazine.emplace(Nonterminal::V);
                magazine.emplace(LexemeType::IntNum);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::IntNumber);
                break;
            }
            case LexemeType::FloatNum:
            {
                magazine.emplace(Nonterminal::L);
                magazine.emplace(Nonterminal::U);
                magazine.emplace(Nonterminal::V);
                magazine.emplace(LexemeType::FloatNum);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::FloatNumber);
                break;
            }
            case LexemeType::LeftRoundBracket:
            {
                magazine.emplace(Nonterminal::L);
                magazine.emplace(Nonterminal::U);
                magazine.emplace(Nonterminal::V);
                magazine.emplace(LexemeType::RightRoundBracket);
                magazine.emplace(Nonterminal::E);
                magazine.emplace(LexemeType::RightRoundBracket);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            default:
            {
                std::string errormsg = "Ops Generator error C - Unexpected lexeme;";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            }
            break;
        }
        case Nonterminal::L:
        {
            switch (current_lexeme.lex_type)
            {
            case LexemeType::LessOrEqual:
            {
                magazine.emplace(Nonterminal::Z);
                magazine.emplace(Nonterminal::E);
                magazine.emplace(LexemeType::LessOrEqual);

                generator.emplace(GeneratorTask::LessOrEqual);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                
                break;
            }
            case LexemeType::MoreOrEqual:
            {
                magazine.emplace(Nonterminal::Z);
                magazine.emplace(Nonterminal::E);
                magazine.emplace(LexemeType::MoreOrEqual);

                generator.emplace(GeneratorTask::MoreOrEqual);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                
                break;
            }
            case LexemeType::Equal:
            {
                magazine.emplace(Nonterminal::Z);
                magazine.emplace(Nonterminal::E);
                magazine.emplace(LexemeType::Equal);

                generator.emplace(GeneratorTask::Equal);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                
                break;
            }
            case LexemeType::Less:
            {
                magazine.emplace(Nonterminal::Z);
                magazine.emplace(Nonterminal::E);
                magazine.emplace(LexemeType::Less);

                generator.emplace(GeneratorTask::Less);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                
                break;
            }
            case LexemeType::More:
            {
                magazine.emplace(Nonterminal::Z);
                magazine.emplace(Nonterminal::E);
                magazine.emplace(LexemeType::More);

                generator.emplace(GeneratorTask::More);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                
                break;
            }
            default:
            {
                std::string errormsg = "Ops Generator error L - Unexpected lexeme;";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            }
            break;
        }
        case Nonterminal::K:
        {
            switch (current_lexeme.lex_type)
            {
            case LexemeType::Else:
            {
                magazine.emplace(LexemeType::RightBrace);
                magazine.emplace(Nonterminal::Q);
                magazine.emplace(LexemeType::LeftBrace);
                magazine.emplace(LexemeType::Else);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Task2);
                break;
            }
            }
            break;
        }
        case Nonterminal::E:
        {
            switch (current_lexeme.lex_type)
            {
            case LexemeType::VarName:
            {
                magazine.emplace(Nonterminal::U);
                magazine.emplace(Nonterminal::V);
                magazine.emplace(Nonterminal::H);
                magazine.emplace(LexemeType::VarName);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::VariableId);
                break;
            }
            case LexemeType::Plus:
            {
                magazine.emplace(Nonterminal::U);
                magazine.emplace(Nonterminal::V);
                magazine.emplace(Nonterminal::F);
                magazine.emplace(LexemeType::Plus);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            case LexemeType::Minus:
            {
                magazine.emplace(Nonterminal::U);
                magazine.emplace(Nonterminal::V);
                magazine.emplace(Nonterminal::F);
                magazine.emplace(LexemeType::Minus);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::UnarMinus);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            case LexemeType::IntNum:
            {
                magazine.emplace(Nonterminal::U);
                magazine.emplace(Nonterminal::V);
                magazine.emplace(LexemeType::IntNum);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::IntNumber);
                break;
            }
            case LexemeType::FloatNum:
            {
                magazine.emplace(Nonterminal::U);
                magazine.emplace(Nonterminal::V);
                magazine.emplace(LexemeType::FloatNum);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::FloatNumber);
                break;
            }
            case LexemeType::StringVal:
            {
                magazine.emplace(Nonterminal::U);
                magazine.emplace(Nonterminal::V);
                magazine.emplace(LexemeType::StringVal);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::StringVal);
                break;
            }
            case LexemeType::LeftRoundBracket:
            {
                magazine.emplace(Nonterminal::U);
                magazine.emplace(Nonterminal::V);
                magazine.emplace(LexemeType::RightRoundBracket);
                magazine.emplace(Nonterminal::E);
                magazine.emplace(LexemeType::RightRoundBracket);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            default:
            {
                std::string errormsg = "Ops Generator error E - Unexpected lexeme;";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            }
            break;
        }
        case Nonterminal::U:
        {
            switch (current_lexeme.lex_type)
            {
            case LexemeType::Plus:
            {
                magazine.emplace(Nonterminal::U);
                magazine.emplace(Nonterminal::T);
                magazine.emplace(LexemeType::Plus);

                generator.emplace(GeneratorTask::Plus);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            case LexemeType::Minus:
            {
                magazine.emplace(Nonterminal::U);
                magazine.emplace(Nonterminal::T);
                magazine.emplace(LexemeType::Minus);

                generator.emplace(GeneratorTask::Minus);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            }
            break;
        }
        case Nonterminal::T:
        {
            switch (current_lexeme.lex_type)
            {
            case LexemeType::VarName:
            {
                magazine.emplace(Nonterminal::V);
                magazine.emplace(Nonterminal::H);
                magazine.emplace(LexemeType::VarName);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::VariableId);
                break;
            }
            case LexemeType::Plus:
            {
                magazine.emplace(Nonterminal::V);
                magazine.emplace(Nonterminal::F);
                magazine.emplace(LexemeType::Plus);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            case LexemeType::Minus:
            {
                magazine.emplace(Nonterminal::V);
                magazine.emplace(Nonterminal::F);
                magazine.emplace(LexemeType::Minus);

                generator.emplace(GeneratorTask::UnarMinus);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            case LexemeType::IntNum:
            {
                magazine.emplace(Nonterminal::V);
                magazine.emplace(LexemeType::IntNum);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::IntNumber);
                break;
            }
            case LexemeType::FloatNum:
            {
                magazine.emplace(Nonterminal::V);
                magazine.emplace(LexemeType::FloatNum);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::FloatNumber);
                break;
            }
            case LexemeType::LeftRoundBracket:
            {
                magazine.emplace(Nonterminal::V);
                magazine.emplace(LexemeType::RightRoundBracket);
                magazine.emplace(Nonterminal::E);
                magazine.emplace(LexemeType::RightRoundBracket);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            default:
            {
                std::string errormsg = "Ops Generator error T - Unexpected lexeme;";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            }
            break;
        }
        case Nonterminal::V:
        {
            switch (current_lexeme.lex_type)
            {
            case LexemeType::Divide:
            {
                magazine.emplace(Nonterminal::V);
                magazine.emplace(Nonterminal::R);
                magazine.emplace(LexemeType::Divide);

                generator.emplace(GeneratorTask::Divide);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            case LexemeType::Multiply:
            {
                magazine.emplace(Nonterminal::V);
                magazine.emplace(Nonterminal::R);
                magazine.emplace(LexemeType::Multiply);

                generator.emplace(GeneratorTask::Multiply);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            }
            break;
        }
        case Nonterminal::R:
        {
            switch (current_lexeme.lex_type)
            {
            case LexemeType::VarName:
            {
                magazine.emplace(Nonterminal::H);
                magazine.emplace(LexemeType::VarName);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::VariableId);
                break;
            }
            case LexemeType::Plus:
            {
                magazine.emplace(Nonterminal::F);
                magazine.emplace(LexemeType::Plus);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            case LexemeType::Minus:
            {
                magazine.emplace(Nonterminal::Z);
                magazine.emplace(Nonterminal::F);
                magazine.emplace(LexemeType::Minus);

                generator.emplace(GeneratorTask::UnarMinus);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            case LexemeType::IntNum:
            {
                magazine.emplace(LexemeType::IntNum);

                generator.emplace(GeneratorTask::IntNumber);
                break;
            }
            case LexemeType::FloatNum:
            {
                magazine.emplace(LexemeType::FloatNum);

                generator.emplace(GeneratorTask::FloatNumber);
                break;
            }
            case LexemeType::LeftRoundBracket:
            {
                magazine.emplace(LexemeType::RightRoundBracket);
                magazine.emplace(Nonterminal::E);
                magazine.emplace(LexemeType::LeftRoundBracket);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            default:
            {
                std::string errormsg = "Ops Generator error R - Unexpected lexeme;";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            }
            break;
        }
        case Nonterminal::F:
        {
            switch (current_lexeme.lex_type)
            {
            case LexemeType::VarName:
            {
                magazine.emplace(Nonterminal::H);
                magazine.emplace(LexemeType::VarName);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::VariableId);
                break;
            }
            case LexemeType::IntNum:
            {
                magazine.emplace(LexemeType::IntNum);

                generator.emplace(GeneratorTask::IntNumber);
                break;
            }
            case LexemeType::FloatNum:
            {
                magazine.emplace(LexemeType::FloatNum);

                generator.emplace(GeneratorTask::FloatNumber);
                break;
            }
            case LexemeType::StringVal:
            {
                magazine.emplace(LexemeType::StringVal);

                generator.emplace(GeneratorTask::StringVal);
                break;
            }
            case LexemeType::LeftRoundBracket:
            {
                magazine.emplace(LexemeType::RightRoundBracket);
                magazine.emplace(Nonterminal::E);
                magazine.emplace(LexemeType::RightRoundBracket);

                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                generator.emplace(GeneratorTask::Empty);
                break;
            }
            default:
            {
                std::string errormsg = "Ops Generator error F - Unexpected lexeme;";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            }
            break;
        }
        case Nonterminal::Z: break;
        case Nonterminal::Error:
        default:
            std::string errormsg = "Ops Generator error Error - Error or unknown state;";
            throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
    }
}

void OpsGenerator::DoTask()
{
    switch (current_task)
    {
    case GeneratorTask::Empty:
        break;
    case GeneratorTask::VariableId:
    {
        std::string var_name = current_lexeme.lex_value; //Поиск переменной по имени в таблице
        if (interdata.int_table.count(var_name) || 
            interdata.massInt_table.count(var_name))
        {
            interdata.ops_item.emplace_back(var_name, OpsItemType::IntVar, current_lexeme.lex_debuginfo);
        }
        else if (interdata.float_table.count(var_name) ||
            interdata.massFloat_table.count(var_name))
        {
            interdata.ops_item.emplace_back(var_name, OpsItemType::FloatVar, current_lexeme.lex_debuginfo);
        }
        else if (interdata.string_table.count(var_name))
        {
            interdata.ops_item.emplace_back(var_name, OpsItemType::StringVar, current_lexeme.lex_debuginfo);
        }
        else
        {
            std::string errormsg = "OpsGenerator error - Unknown variable name = '" + var_name + "';";
            throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
        }
        break;
    }
    case GeneratorTask::IntNumber:
    {
        interdata.ops_item.emplace_back(std::stoi(current_lexeme.lex_value), current_lexeme.lex_debuginfo);
        break;
    }
    case GeneratorTask::FloatNumber:
    {
        interdata.ops_item.emplace_back(std::stof(current_lexeme.lex_value), current_lexeme.lex_debuginfo);
        break;
    }
    case GeneratorTask::StringVal:
    {
        interdata.ops_item.emplace_back(current_lexeme.lex_value, current_lexeme.lex_debuginfo);
        break;
    }
    case GeneratorTask::Read:
        interdata.ops_item.emplace_back(OpsItemOperation::Read, current_lexeme.lex_debuginfo);
        break;
    case GeneratorTask::Write:
        interdata.ops_item.emplace_back(OpsItemOperation::Write, current_lexeme.lex_debuginfo);
        break;
    case GeneratorTask::Plus:
        interdata.ops_item.emplace_back(OpsItemOperation::Plus, current_lexeme.lex_debuginfo);
        break;
    case GeneratorTask::Minus:
        interdata.ops_item.emplace_back(OpsItemOperation::Minus, current_lexeme.lex_debuginfo);
        break;
    case GeneratorTask::UnarMinus:
        interdata.ops_item.emplace_back(OpsItemOperation::UnarMinus, current_lexeme.lex_debuginfo);
        break;
    case GeneratorTask::Multiply:
        interdata.ops_item.emplace_back(OpsItemOperation::Multiply, current_lexeme.lex_debuginfo);
        break;
    case GeneratorTask::Divide:
        interdata.ops_item.emplace_back(OpsItemOperation::Divide, current_lexeme.lex_debuginfo);
        break;
    case GeneratorTask::Less:
        interdata.ops_item.emplace_back(OpsItemOperation::Less, current_lexeme.lex_debuginfo);
        break;
    case GeneratorTask::Assign:
        interdata.ops_item.emplace_back(OpsItemOperation::Assign, current_lexeme.lex_debuginfo);
        break;
    case GeneratorTask::More:
        interdata.ops_item.emplace_back(OpsItemOperation::More, current_lexeme.lex_debuginfo);
        break;
    case GeneratorTask::Equal:
        interdata.ops_item.emplace_back(OpsItemOperation::Equal, current_lexeme.lex_debuginfo);
        break;
    case GeneratorTask::LessOrEqual:
        interdata.ops_item.emplace_back(OpsItemOperation::LessOrEqual, current_lexeme.lex_debuginfo);
        break;
    case GeneratorTask::MoreOrEqual:
        interdata.ops_item.emplace_back(OpsItemOperation::MoreOrEqual, current_lexeme.lex_debuginfo);
        break;
    case GeneratorTask::NotEqual:
        interdata.ops_item.emplace_back(OpsItemOperation::NotEqual, current_lexeme.lex_debuginfo);
        break;
    case GeneratorTask::Index:
        interdata.ops_item.emplace_back(OpsItemOperation::Index, current_lexeme.lex_debuginfo);
        break;
    case GeneratorTask::Task1:
    {
        magazine_marks.push(interdata.ops_item.size());
        interdata.ops_item.emplace_back(0, current_lexeme.lex_debuginfo);
        interdata.ops_item.emplace_back(OpsItemOperation::JumpIfElse, current_lexeme.lex_debuginfo);
        break;
    }
    case GeneratorTask::Task2:
    {
        int marks_place = magazine_marks.top(); 
        magazine_marks.pop();
        magazine_marks.push(interdata.ops_item.size());
        interdata.ops_item.emplace_back(0, current_lexeme.lex_debuginfo);
        interdata.ops_item.emplace_back(OpsItemOperation::Jump, current_lexeme.lex_debuginfo);
        interdata.ops_item[marks_place].Num_Val = interdata.ops_item.size(); //k+2
        break;
    }
    case GeneratorTask::Task3:
    {
        int marks_place = magazine_marks.top();
        magazine_marks.pop();
        interdata.ops_item[marks_place].Num_Val = interdata.ops_item.size();//k
        break;
    }
    case GeneratorTask::Task4: //While For
    {
        magazine_marks.push(interdata.ops_item.size());
        break;
    }
    case GeneratorTask::Task5:
    {
        int marks_place = magazine_marks.top();
        magazine_marks.pop();

        interdata.ops_item.emplace_back(magazine_marks.top(), current_lexeme.lex_debuginfo); 
        magazine_marks.pop();

        interdata.ops_item.emplace_back(OpsItemOperation::Jump, current_lexeme.lex_debuginfo);
        interdata.ops_item[marks_place].Num_Val = interdata.ops_item.size();//k+2
        break;
    }
    case GeneratorTask::Task6: //vars
    {
        std::string var_name = current_lexeme.lex_value;

        switch (current_table)
        {
        case vartable::Int:
        {
            
            if (is_constant && is_array)
            {
                std::string errormsg = "Ops Generator error - Constant can't be an array = '" + var_name + "';";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            else
            {
                if (std::count(names_table.begin(), names_table.end(), var_name) == 0)
                {
                    if (is_constant)
                    {
                        interdata.int_table.insert({ var_name, 0 });
                        interdata.constid_table.push_back(var_name);
                        names_table.push_back(var_name);
                    }
                    else if (is_array)
                    {
                        interdata.massInt_table.insert({ var_name, std::vector<int>(0) });
                        names_table.push_back(var_name);
                    }
                    else
                    {
                        interdata.int_table.insert({ var_name, 0 });
                        names_table.push_back(var_name);
                    }
                }
                else
                {
                    std::string errormsg = "Ops Generator error - Redefine a variable name = '" + var_name + "';";
                    throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
                }
            }
            break;
        }
        case vartable::Float:
        {
            if (is_constant && is_array)
            {
                std::string errormsg = "Ops Generator error - Constant can't be an array = '" + var_name + "';";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            else
            {
                if (std::count(names_table.begin(), names_table.end(), var_name) == 0)
                {
                    if (is_constant)
                    {
                        interdata.float_table.insert({ var_name, 0 });
                        interdata.constid_table.push_back(var_name);
                        names_table.push_back(var_name);
                    }
                    else if (is_array)
                    {
                        interdata.massFloat_table.insert({ var_name, std::vector<float>(0) });
                        names_table.push_back(var_name);
                    }
                    else
                    {
                        interdata.float_table.insert({ var_name, 0 });
                        names_table.push_back(var_name);
                    }
                }
                else
                {
                    std::string errormsg = "Ops Generator error - Redefine a variable name = '" + var_name + "';";
                    throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
                }
            }
            break;
        }
        case vartable::String:
        {
            if (is_constant && is_array)
            {
                std::string errormsg = "Ops Generator error - Constant can't be an array = '" + var_name + "';";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            else
            {
                if (std::count(names_table.begin(), names_table.end(), var_name) == 0)
                {
                    if (is_constant)
                    {
                        interdata.string_table.insert({ var_name, ""});
                        interdata.constid_table.push_back(var_name);
                        names_table.push_back(var_name);
                    }
                    else if (is_array)
                    {
                        std::string errormsg = "Ops Generator error - String can't be an array = '" + var_name + "';";
                        throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
                    }
                    else
                    {
                        interdata.string_table.insert({ var_name, ""});
                        names_table.push_back(var_name);
                    }
                }
                else
                {
                    std::string errormsg = "Ops Generator error - Redefine a variable name = '" + var_name + "';";
                    throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
                }
            }
            break;
        }
        }
        break;
    }
    case GeneratorTask::Task7: //int
    {
        current_table = vartable::Int;
        // current_table = table::MassInt;
        break;
    }
    case GeneratorTask::Task8: //float
    {
        current_table = vartable::Float;
        // current_table = table::MassInt;
        break;
    }
    case GeneratorTask::Task9: //string
    {
        current_table = vartable::String;
        // current_table = table::MassInt;
        break;
    }
    case GeneratorTask::Task10: //array
    {
        std::string var_name = current_lexeme.lex_value;
        is_array = true;
        switch (current_table)
        {
        case vartable::Int:
        {

            if (is_constant && is_array)
            {
                std::string errormsg = "Ops Generator error - Constant can't be an array = '" + var_name + "';";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            else
            {
                if (std::count(names_table.begin(), names_table.end(), var_name) == 0)
                {

                    interdata.massInt_table.insert({ var_name, std::vector<int>(0) });
                    names_table.push_back(var_name);
                }
                else
                {
                    std::string errormsg = "Ops Generator error - Redefine a variable name = '" + var_name + "';";
                    throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
                }
            }
            break;
        }
        case vartable::Float:
        {
            if (is_constant && is_array)
            {
                std::string errormsg = "Ops Generator error - Constant can't be an array = '" + var_name + "';";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            else
            {
                if (std::count(names_table.begin(), names_table.end(), var_name) == 0)
                {
                    interdata.massFloat_table.insert({ var_name, std::vector<float>(0) });
                    names_table.push_back(var_name);
                }
                else
                {
                    std::string errormsg = "Ops Generator error - Redefine a variable name = '" + var_name + "';";
                    throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
                }
            }
            break;
        }
        case vartable::String:
        {
           
            std::string errormsg = "Ops Generator error - String can't be an array = '" + var_name + "';";
            throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
        }
        }

        if (interdata.int_table.count(var_name) ||
            interdata.massInt_table.count(var_name))
        {
            interdata.ops_item.emplace_back(var_name, OpsItemType::IntVar, current_lexeme.lex_debuginfo);
        }
        else if (interdata.float_table.count(var_name) ||
            interdata.massFloat_table.count(var_name))
        {
            interdata.ops_item.emplace_back(var_name, OpsItemType::FloatVar, current_lexeme.lex_debuginfo);
        }
        else
        {
            std::string errormsg = "OpsGenerator error - Unknown variable name = '" + var_name + "';";
            throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
        }
        break;
        //current_table = vartable::Int;
        //is_array = true;
        // current_table = table::MassInt;
    }
    case GeneratorTask::Task11: //const
    {
        ///////////////////////////////
        std::string var_name = current_lexeme.lex_value;
        is_constant = true;
        switch (current_table)
        {
        case vartable::Int:
        {

            if (is_constant && is_array)
            {
                std::string errormsg = "Ops Generator error - Constant can't be an array = '" + var_name + "';";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            else
            {
                if (std::count(names_table.begin(), names_table.end(), var_name) == 0)
                {
                    interdata.int_table.insert({ var_name, 0 });
                    interdata.constid_table.push_back(var_name);
                    names_table.push_back(var_name);
                }
                else
                {
                    std::string errormsg = "Ops Generator error - Redefine a variable name = '" + var_name + "';";
                    throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
                }
            }
            break;
        }
        case vartable::Float:
        {
            if (is_constant && is_array)
            {
                std::string errormsg = "Ops Generator error - Constant can't be an array = '" + var_name + "';";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            else
            {
                if (std::count(names_table.begin(), names_table.end(), var_name) == 0)
                {              
                    interdata.float_table.insert({ var_name, 0 });
                    interdata.constid_table.push_back(var_name);
                    names_table.push_back(var_name);
                }
                else
                {
                    std::string errormsg = "Ops Generator error - Redefine a variable name = '" + var_name + "';";
                    throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
                }
            }
            break;
        }
        case vartable::String:
        {
            if (is_constant && is_array)
            {
                std::string errormsg = "Ops Generator error - Constant can't be an array = '" + var_name + "';";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
            else
            {
                if (std::count(names_table.begin(), names_table.end(), var_name) == 0)
                {
                    interdata.string_table.insert({ var_name, "" });
                    interdata.constid_table.push_back(var_name);
                    names_table.push_back(var_name);
                }
                else
                {
                    std::string errormsg = "Ops Generator error - Redefine a variable name = '" + var_name + "';";
                    throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
                }
            }
            break;
        }
        }
        
        if (interdata.int_table.count(var_name) ||
            interdata.massInt_table.count(var_name))
        {
            interdata.ops_item.emplace_back(var_name, OpsItemType::IntVar, current_lexeme.lex_debuginfo);
        }
        else if (interdata.float_table.count(var_name) ||
            interdata.massFloat_table.count(var_name))
        {
            interdata.ops_item.emplace_back(var_name, OpsItemType::FloatVar, current_lexeme.lex_debuginfo);
        }
        else if (interdata.string_table.count(var_name))
        {
            interdata.ops_item.emplace_back(var_name, OpsItemType::StringVar, current_lexeme.lex_debuginfo);
        }
        else
        {
            std::string errormsg = "OpsGenerator error - Unknown variable name = '" + var_name + "';";
            throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
        }
        break;

       // current_table = vartable::Int;
        //is_constant = true;
        // current_table = table::MassInt;
        //break;
    }
    case GeneratorTask::Memory:
    {
        interdata.ops_item.emplace_back(OpsItemOperation::Memory, current_lexeme.lex_debuginfo);
        break;
    }
    case GeneratorTask::Resize:
    {
        interdata.ops_item.emplace_back(OpsItemOperation::Resize, current_lexeme.lex_debuginfo);
        break;
    }
    default: {
        std::string errormsg = "Generator error - Unknown Ops Generator task;";
        throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
    }
    }
}

OpsGenerator::OpsGenerator(std::vector<LexemeInfo> input)
{
	input_lexemes = input;
}

InterData OpsGenerator::GetOpsData()
{
	magazine.emplace(Nonterminal::S);
	generator.push(GeneratorTask::Empty);

	int current_lexeme_id = 0;
	current_lexeme = input_lexemes[current_lexeme_id];

	while (!generator.empty() && !magazine.empty())
	{
		MagazineItem current_mag_item = magazine.top();
		magazine.pop();

		current_nonterminal = current_mag_item.nonterminal;
		current_task = generator.top();
		generator.pop();

        DoTask();

        if (current_mag_item.is_terminal)
        {
            if (current_lexeme.lex_type == LexemeType::Finish)
            {
                std::string errormsg = "Ops Generator error - All lexemes are read, but magazine is not empty;";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }

            if (current_mag_item.lexeme_type == current_lexeme.lex_type)
            {
                if (current_lexeme.lex_type == LexemeType::Semicolon)
                {
                    is_array = false;
                    is_constant = false;
                }
                current_lexeme = input_lexemes[++current_lexeme_id];
            }
            else if (current_mag_item.lexeme_type == LexemeType::FloatNum && current_lexeme.lex_type == LexemeType::IntNum)
            {
                current_lexeme = input_lexemes[++current_lexeme_id];
            }
            else
            {

                std::string errormsg = "Ops Generator error Main - Unexpected lexeme;";
                throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
            }
        }
        else GrammNonterminal();
	}

    if (current_lexeme.lex_type != LexemeType::Finish) {
        std::string errormsg = "Generator error - There are unrecognized lexemes;";
        throw InterDebug(errormsg, current_lexeme.lex_debuginfo);
    }

	return interdata;
}
