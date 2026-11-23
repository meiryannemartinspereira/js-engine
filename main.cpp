
#include <iostream>
#include "src/lexer/lexer.hpp"

std::string tokenTypeToString(TokenType type)
{
    switch (type)
    {
    case TokenType::LET: return "LET";
    case TokenType::CONST: return "CONST";
    case TokenType::VAR: return "VAR";
    case TokenType::FUNCTION: return "FUNCTION";
    case TokenType::RETURN: return "RETURN";
    case TokenType::IDENTIFIER: return "IDENTIFIER";
    case TokenType::NUMBER: return "NUMBER";
    case TokenType::EQUAL: return "EQUAL";
    case TokenType::SEMICOLON: return "SEMICOLON";
    default: return "UNKNOWN";
    }
}

int main()
{
    std::string source = "let idade = 12345;";

    Lexer lexer(source);

    for (int i = 0; i < 5; i++)
    {
        Token token = lexer.nextToken();

        std::cout << tokenTypeToString(token.type)
                  << " -> " << token.value << std::endl;
    }

    return 0;
}
