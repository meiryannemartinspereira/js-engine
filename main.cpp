
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
    case TokenType::PLUS: return "PLUS";
    case TokenType::MINUS: return "MINUS";
    case TokenType::MULTIPLY: return "MULTIPLY";
    case TokenType::DIVIDE: return "DIVIDE";
    case TokenType::MODULO: return "MODULO";
    default: return "UNKNOWN";
    }
}

int main()
{
    std::string source = "10 + 5 - 2 * 3 / 1 % 2;";

    Lexer lexer(source);

    while (true)
    {
        Token token = lexer.nextToken();
        if (token.type == TokenType::END_OF_FILE)
        {
            break;
        }

        std::cout << tokenTypeToString(token.type)
                  << " -> " << token.value << std::endl;
    }

    return 0;
}
