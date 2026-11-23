
#include "lexer.hpp"
#include "readers/readers.hpp"
#include <cctype>

Lexer::Lexer(const std::string& source)
    : source(source), position(0)
{
}

char Lexer::currentChar() const
{
    if (position >= source.length())
    {
        return '\0';
    }

    return source[position];
}

void Lexer::advance()
{
    if (position < source.length())
    {
        position++;
    }
}

void Lexer::skipWhitespace()
{
    while (std::isspace(static_cast<unsigned char>(currentChar())))
    {
        advance();
    }
}

void Lexer::prepareNextChar()
{
    skipWhitespace();
}

Token Lexer::nextToken()
{
    skipWhitespace();

    char character = currentChar();

    if (character == '\0')
    {
        return {TokenType::END_OF_FILE, ""};
    }

    if (std::isalpha(static_cast<unsigned char>(character)))
    {
        return IdentifierReader::read(source, position);
    }

    if (std::isdigit(static_cast<unsigned char>(character)))
    {
        return NumberReader::read(source, position);
    }

    if (character == '+' ||
        character == '-' ||
        character == '*' ||
        character == '/' ||
        character == '%' ||
        character == '=' ||
        character == '!' ||
        character == '>' ||
        character == '<' ||
        character == '&' ||
        character == '|')
    {
        return OperatorReader::read(source, position);
    }
    if (character == '=')
    {
        advance();
        return {TokenType::EQUAL, "="};
    }

    if (character == ';')
    {
        advance();
        return {TokenType::SEMICOLON, ";"};
    }

    return {TokenType::END_OF_FILE, ""};
}
