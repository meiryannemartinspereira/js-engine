
#include "token.hpp"

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
    case TokenType::STRING: return "STRING";

    case TokenType::EQUAL: return "EQUAL";
    case TokenType::PLUS: return "PLUS";
    case TokenType::MINUS: return "MINUS";
    case TokenType::MULTIPLY: return "MULTIPLY";
    case TokenType::DIVIDE: return "DIVIDE";
    case TokenType::MODULO: return "MODULO";

    case TokenType::PLUS_PLUS: return "PLUS_PLUS";
    case TokenType::MINUS_MINUS: return "MINUS_MINUS";

    case TokenType::PLUS_EQUAL: return "PLUS_EQUAL";
    case TokenType::MINUS_EQUAL: return "MINUS_EQUAL";
    case TokenType::MULTIPLY_EQUAL: return "MULTIPLY_EQUAL";
    case TokenType::DIVIDE_EQUAL: return "DIVIDE_EQUAL";
    case TokenType::MODULO_EQUAL: return "MODULO_EQUAL";

    case TokenType::EQUAL_EQUAL: return "EQUAL_EQUAL";
    case TokenType::STRICT_EQUAL: return "STRICT_EQUAL";
    case TokenType::NOT_EQUAL: return "NOT_EQUAL";
    case TokenType::STRICT_NOT_EQUAL: return "STRICT_NOT_EQUAL";

    case TokenType::GREATER: return "GREATER";
    case TokenType::LESS: return "LESS";
    case TokenType::GREATER_EQUAL: return "GREATER_EQUAL";
    case TokenType::LESS_EQUAL: return "LESS_EQUAL";

    case TokenType::AND: return "AND";
    case TokenType::OR: return "OR";
    case TokenType::NOT: return "NOT";

    case TokenType::SEMICOLON: return "SEMICOLON";
    case TokenType::INVALID: return "INVALID";
    case TokenType::END_OF_FILE: return "END_OF_FILE";
    }

    return "UNKNOWN";
}
