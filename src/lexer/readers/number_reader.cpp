#include "readers.hpp"
#include <cctype>

Token NumberReader::read(const std::string& source, size_t& position)
{
    std::string value;

    while (position < source.length())
    {
        char character = source[position];

        if (!std::isdigit(static_cast<unsigned char>(character)))
        {
            break;
        }

        value += character;
        position++;
    }

    return {TokenType::NUMBER, value};
}