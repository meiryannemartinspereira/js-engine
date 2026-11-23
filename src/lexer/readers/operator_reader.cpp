
#include "readers.hpp"

char OperatorReader::peek(const std::string& source, size_t position)
{
    if (position + 1 >= source.length())
    {
        return '\0';
    }

    return source[position + 1];
}

Token OperatorReader::read(const std::string& source, size_t& position)
{
    char character = source[position];
    char next = peek(source, position);

    position++;

    switch (character)
    {
    case '+':
        if (next == '+')
        {
            position++;
            return {TokenType::PLUS_PLUS, "++"};
        }

        if (next == '=')
        {
            position++;
            return {TokenType::PLUS_EQUAL, "+="};
        }

        return {TokenType::PLUS, "+"};

    case '-':
        if (next == '-')
        {
            position++;
            return {TokenType::MINUS_MINUS, "--"};
        }

        if (next == '=')
        {
            position++;
            return {TokenType::MINUS_EQUAL, "-="};
        }

        return {TokenType::MINUS, "-"};

    case '*':
        if (next == '=')
        {
            position++;
            return {TokenType::MULTIPLY_EQUAL, "*="};
        }

        return {TokenType::MULTIPLY, "*"};

    case '/':
        if (next == '=')
        {
            position++;
            return {TokenType::DIVIDE_EQUAL, "/="};
        }

        return {TokenType::DIVIDE, "/"};

    case '%':
        if (next == '=')
        {
            position++;
            return {TokenType::MODULO_EQUAL, "%="};
        }

        return {TokenType::MODULO, "%"};

    case '=':
        if (next == '=')
        {
            position++;

            if (position < source.length() && source[position] == '=')
            {
                position++;
                return {TokenType::STRICT_EQUAL, "==="};
            }

            return {TokenType::EQUAL_EQUAL, "=="};
        }

        return {TokenType::EQUAL, "="};

    case '!':
        if (next == '=')
        {
            position++;

            if (position < source.length() && source[position] == '=')
            {
                position++;
                return {TokenType::STRICT_NOT_EQUAL, "!=="};
            }

            return {TokenType::NOT_EQUAL, "!="};
        }

        return {TokenType::NOT, "!"};

    case '>':
        if (next == '=')
        {
            position++;
            return {TokenType::GREATER_EQUAL, ">="};
        }

        return {TokenType::GREATER, ">"};

    case '<':
        if (next == '=')
        {
            position++;
            return {TokenType::LESS_EQUAL, "<="};
        }

        return {TokenType::LESS, "<"};

    case '&':
        if (next == '&')
        {
            position++;
            return {TokenType::AND, "&&"};
        }
        break;

    case '|':
        if (next == '|')
        {
            position++;
            return {TokenType::OR, "||"};
        }
        break;
    }

    return {TokenType::INVALID, std::string(1, character)};
}
