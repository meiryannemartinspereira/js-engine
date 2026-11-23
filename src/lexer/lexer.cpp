#include "lexer.hpp"
#include <cctype>

Lexer::Lexer(const std::string &source)
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
    while (std::isspace(currentChar()))
    {
        advance();
    }
}

void Lexer::prepareNextChar()
{
    skipWhitespace();
}

bool Lexer::isAlpha(char character) const
{
    return std::isalpha(static_cast<unsigned char>(character));
}

bool Lexer::isDigit(char character) const
{
    return std::isdigit(static_cast<unsigned char>(character));
}

Token Lexer::readIdentifier()
{
    std::string value;

    while (isAlpha(currentChar()) || isDigit(currentChar()))
    {
        value += currentChar();
        advance();
    }

    return {TokenType::IDENTIFIER, value};
}

Token Lexer::nextToken()
{
    skipWhitespace();

    char character = currentChar();

    if (isAlpha(character))
    {
        return readIdentifier();
    }

    if (isDigit(character))
    {
        return readNumber();
    }

    return {TokenType::END_OF_FILE, ""};
}

Token Lexer::readNumber()
{
    std::string value;

    while (isDigit(currentChar()))
    {
        value += currentChar();
        advance();
    }

    return {TokenType::NUMBER, value};
}