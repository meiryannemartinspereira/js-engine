#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

enum class TokenType
{
    LET,
    CONST,
    VAR,
    FUNCTION,
    RETURN,
    IDENTIFIER,
    NUMBER,
    STRING,
    EQUAL,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    MODULO,
    SEMICOLON,
    END_OF_FILE
};

struct Token
{
    TokenType type;
    std::string value;
};

#endif