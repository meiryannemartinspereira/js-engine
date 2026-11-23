
#include "readers.hpp"
#include <cctype>
#include <unordered_map>

Token IdentifierReader::read(const std::string& source, size_t& position)
{
    std::string value;

    while (position < source.length())
    {
        char character = source[position];

        if (!std::isalpha(static_cast<unsigned char>(character)) &&
            !std::isdigit(static_cast<unsigned char>(character)))
        {
            break;
        }

        value += character;
        position++;
    }

    static const std::unordered_map<std::string, TokenType> keywords = {
        {"let", TokenType::LET},
        {"const", TokenType::CONST},
        {"var", TokenType::VAR},
        {"function", TokenType::FUNCTION},
        {"return", TokenType::RETURN}
    };

    auto it = keywords.find(value);

    if (it != keywords.end())
    {
        return {it->second, value};
    }

    return {TokenType::IDENTIFIER, value};
}
