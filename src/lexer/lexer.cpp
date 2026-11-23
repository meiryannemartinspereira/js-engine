
#include "lexer.hpp"
#include <cctype>
#include <unordered_map>

const std::unordered_map<std::string, TokenType> keywords = {
    {"let", TokenType::LET},
    {"const", TokenType::CONST},
    {"var", TokenType::VAR},
    {"function", TokenType::FUNCTION},
    {"return", TokenType::RETURN}};

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
    while (std::isspace(static_cast<unsigned char>(currentChar())))
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

    auto it = keywords.find(value);

    if (it != keywords.end())
    {
        return {it->second, value};
    }

    return {TokenType::IDENTIFIER, value};
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

Token Lexer::readOperator()
{
    char character = currentChar();

    advance();

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

    if (character == '+' ||
        character == '-' ||
        character == '*' ||
        character == '/' ||
        character == '%')
    {
        return readOperator();
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
