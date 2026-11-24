#include "parser.hpp"
#include <stdexcept>

Parser::Parser(Lexer& lexer)
    : lexer(lexer)
{
    advance();
}

void Parser::advance()
{
    currentToken = lexer.nextToken();
}

void Parser::expect(TokenType type)
{
    if (currentToken.type != type)
    {
        throw std::runtime_error("Unexpected token: " + currentToken.value);
    }

    advance();
}

Token Parser::getCurrentToken() const
{
    return currentToken;
}

void Parser::parseVariableDeclaration()
{
    expect(TokenType::LET);
    expect(TokenType::IDENTIFIER);
    expect(TokenType::EQUAL);
    expect(TokenType::NUMBER);
    expect(TokenType::SEMICOLON);
}

void Parser::parseProgram()
{
    parseVariableDeclaration();
}