
#include "readers.hpp"

Token StringReader::read(const std::string& source, size_t& position)
{
    char delimiter = source[position];
    std::string value;

    position++;

    while (position < source.length())
    {
        char character = source[position];

        if (character == '\\')
        {
            position++;

            if (position >= source.length())
            {
                return {TokenType::INVALID, value};
            }

            char escaped = source[position];

            switch (escaped)
            {
            case 'n':
                value += '\n';
                break;

            case 't':
                value += '\t';
                break;

            case 'r':
                value += '\r';
                break;

            default:
                value += escaped;
                break;
            }

            position++;
            continue;
        }

        if (character == delimiter)
        {
            position++;
            return {TokenType::STRING, value};
        }

        value += character;
        position++;
    }

    return {TokenType::INVALID, value};
}
