#include "readers.hpp"
#include <cctype>

Token NumberReader::read(const std::string& source, size_t& position)

{
    std::string value;
    bool hasDecimal = false;

    while (position < source.length())
    {
        char character = source[position];

        if (std::isdigit(static_cast<unsigned char>(character))){
            value += character;
            position++;
            continue;
        }

        if (character == '.' && !hasDecimal &&
            position + 1 < source.length() &&
            std::isdigit(static_cast<unsigned char>(source[position + 1])))
        {
            value += character;
            position++;
            hasDecimal = true;
            continue;
        }

        break;

    }

    return {TokenType::NUMBER, value};
    
}