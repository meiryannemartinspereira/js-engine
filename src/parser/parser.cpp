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
    parseExpression();
    expect(TokenType::SEMICOLON);
}


void Parser::parseProgram()
{
    while (currentToken.type != TokenType::END_OF_FILE)
    {
        parseVariableDeclaration();
    }
}

void Parser::parsePrimaryExpression(){
    if (currentToken.type == TokenType::NUMBER ||
        currentToken.type == TokenType::STRING ||
        currentToken.type == TokenType::IDENTIFIER)
    {
        advance();
        return;

    }

    if (currentToken.type == TokenType::LEFT_PAREN)
    {
        advance();
        parseExpression();
        expect(TokenType::RIGHT_PAREN);
        return;
    }

    throw std::runtime_error("Invalid expression: " + currentToken.value);
}

void Parser::parseExpression()
{
    parseAdditiveExpression();
}

void Parser::parseMultiplicativeExpression()
{
    parsePrimaryExpression();

    while (
        currentToken.type == TokenType::MULTIPLY ||
        currentToken.type == TokenType::DIVIDE ||
        currentToken.type == TokenType::MODULO
    )
    {
        advance();
        parsePrimaryExpression();
    }
    
}

void Parser::parseAdditiveExpression()
{
    parseMultiplicativeExpression();

    while (
        currentToken.type == TokenType::PLUS ||
        currentToken.type == TokenType::MINUS
    )
    {
        advance();
        parseMultiplicativeExpression();
    }
    
}