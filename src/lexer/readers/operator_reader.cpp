
#include "readers.hpp"

Token OperatorReader::read(const std::string& source, size_t& position)
{
    char character = source[position];
    position++;

    switch (character)
    {
    case '+':
        return {TokenType::PLUS, "+"};

    case '-':
        return {TokenType::MINUS, "-"};

    case '*':
        return {TokenType::MULTIPLY, "*"};

    case '/':
        return {TokenType::DIVIDE, "/"};

    case '%':
        return {TokenType::MODULO, "%"};
    }

    return {TokenType::END_OF_FILE, ""};
}
