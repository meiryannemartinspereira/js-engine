
#include "parser.hpp"
#include "../ast/number_expression.hpp"
#include "../ast/string_expression.hpp"
#include "../ast/identifier_expression.hpp"
#include "../ast/binary_expression.hpp"
#include "../ast/variable_declaration.hpp"
#include <stdexcept>
#include <memory>
#include <string>
#include <utility>

Parser::Parser(Lexer &lexer)
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

std::unique_ptr<ASTNode> Parser::parseVariableDeclaration()
{
    std::string kind = currentToken.value;
    expect(TokenType::LET);

    std::string name = currentToken.value;
    expect(TokenType::IDENTIFIER);

    expect(TokenType::EQUAL);

    auto initializer = parseExpression();

    expect(TokenType::SEMICOLON);

    return std::make_unique<VariableDeclaration>(
        kind,
        name,
        std::move(initializer));
}

std::unique_ptr<Program> Parser::parseProgram()
{
    auto program = std::make_unique<Program>();

    while (currentToken.type != TokenType::END_OF_FILE)
    {
        program->body.push_back(parseVariableDeclaration());
    }

    return program;
}

std::unique_ptr<ASTNode> Parser::parsePrimaryExpression()
{
    if (currentToken.type == TokenType::NUMBER)
    {
        double value = std::stod(currentToken.value);
        advance();

        return std::make_unique<NumberExpression>(value);
    }

    if (currentToken.type == TokenType::STRING)
    {
        std::string value = currentToken.value;
        advance();

        return std::make_unique<StringExpression>(value);
    }

    if (currentToken.type == TokenType::IDENTIFIER)
    {
        std::string name = currentToken.value;
        advance();

        return std::make_unique<IdentifierExpression>(name);
    }

    if (currentToken.type == TokenType::LEFT_PAREN)
    {
        advance();

        auto expression = parseExpression();

        expect(TokenType::RIGHT_PAREN);

        return expression;
    }

    throw std::runtime_error("Invalid expression: " + currentToken.value);
}

std::unique_ptr<ASTNode> Parser::parseExpression()
{
    return parseAdditiveExpression();
}

std::unique_ptr<ASTNode> Parser::parseMultiplicativeExpression()
{
    auto left = parsePrimaryExpression();

    while (
        currentToken.type == TokenType::MULTIPLY ||
        currentToken.type == TokenType::DIVIDE ||
        currentToken.type == TokenType::MODULO)
    {
        std::string op = currentToken.value;
        advance();

        auto right = parsePrimaryExpression();

        left = std::make_unique<BinaryExpression>(
            std::move(left),
            op,
            std::move(right));
    }

    return left;
}

std::unique_ptr<ASTNode> Parser::parseAdditiveExpression()
{
    auto left = parseMultiplicativeExpression();

    while (
        currentToken.type == TokenType::PLUS ||
        currentToken.type == TokenType::MINUS)
    {
        std::string op = currentToken.value;
        advance();

        auto right = parseMultiplicativeExpression();

        left = std::make_unique<BinaryExpression>(
            std::move(left),
            op,
            std::move(right));
    }

    return left;
}
