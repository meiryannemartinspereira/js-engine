
#include "lexer.hpp"
#include "readers/readers.hpp"
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
    while (std::isspace(static_cast<unsigned char>(currentChar())))
    {
        advance();
    }
}

void Lexer::prepareNextChar()
{
    skipWhitespace();
}

void Lexer::skipLineComment()
{
    while (currentChar() != '\n' && currentChar() != '\0')
    {
        advance();
    }
}

bool Lexer::skipBlockComment()
{
    advance();
    advance();

    while (currentChar() != '\0')
    {
        if (currentChar() == '*' &&
            position + 1 < source.length() &&
            source[position + 1] == '/')
        {
            advance();
            advance();
            return true;
        }

        advance();
    }

    return false;
}

Token Lexer::nextToken()
{
    skipWhitespace();

    if (currentChar() == '/' && position + 1 < source.length() && source[position + 1] == '/')
    {
        skipLineComment();
        return nextToken();
    }

    if (currentChar() == '/' &&
        position + 1 < source.length() &&
        source[position + 1] == '*')
    {
        if (!skipBlockComment())
        {
            return {TokenType::INVALID, "Unterminated block comment"};
        }

        return nextToken();
    }

    char character = currentChar();

    if (character == '\0')
    {
        return {TokenType::END_OF_FILE, ""};
    }

    if (std::isalpha(static_cast<unsigned char>(character)) ||
        character == '_' ||
        character == '$')
    {
        return IdentifierReader::read(source, position);
    }

    if (std::isdigit(static_cast<unsigned char>(character)))
    {
        return NumberReader::read(source, position);
    }

    if (character == '"' || character == '\'' || character == '`')
    {
        return StringReader::read(source, position);
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
    switch (character)
    {
    case ';':
        advance();
        return {TokenType::SEMICOLON, ";"};

    case ',':
        advance();
        return {TokenType::COMMA, ","};

    case '.':
        advance();
        return {TokenType::DOT, "."};

    case '(':
        advance();
        return {TokenType::LEFT_PAREN, "("};

    case ')':
        advance();
        return {TokenType::RIGHT_PAREN, ")"};

    case '{':
        advance();
        return {TokenType::LEFT_BRACE, "{"};

    case '}':
        advance();
        return {TokenType::RIGHT_BRACE, "}"};

    case '[':
        advance();
        return {TokenType::LEFT_BRACKET, "["};

    case ']':
        advance();
        return {TokenType::RIGHT_BRACKET, "]"};
    }

    advance();
    return {TokenType::INVALID, std::string(1, character)};
}
