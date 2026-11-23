
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

    PLUS_PLUS,
    MINUS_MINUS,

    PLUS_EQUAL,
    MINUS_EQUAL,
    MULTIPLY_EQUAL,
    DIVIDE_EQUAL,
    MODULO_EQUAL,

    EQUAL_EQUAL,
    STRICT_EQUAL,
    NOT_EQUAL,
    STRICT_NOT_EQUAL,

    GREATER,
    LESS,
    GREATER_EQUAL,
    LESS_EQUAL,

    AND,
    OR,
    NOT,

    SEMICOLON,
    END_OF_FILE
};

struct Token
{
    TokenType type;
    std::string value;
};

std::string tokenTypeToString(TokenType type);

#endif
