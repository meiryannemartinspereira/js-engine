#include "readers.hpp"

Token StringReader::read(const std::string& source, size_t& position)
{
    char delimiter = source[position];
    std::string value;

    position++;

    while (position < source.length() && source[position] != delimiter)
    {
        value += source[position];
        position++;
    }

    if (position >= source.length())
    {
        return {TokenType::INVALID, value};
    }

    position++;

    return {TokenType::STRING, value};
}