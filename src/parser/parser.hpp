#ifndef PARSER_HPP
#define PARSER_HPP

#include "../lexer/lexer.hpp"
#include "../ast/program.hpp"
#include "../ast/ast_node.hpp"
#include <memory>

class Parser
{
private:
    Lexer& lexer;
    Token currentToken;

    void expect(TokenType type);
    void advance();

    std::unique_ptr<ASTNode> parseVariableDeclaration();
    std::unique_ptr<ASTNode> parseExpression();
    std::unique_ptr<ASTNode> parsePrimaryExpression();
    std::unique_ptr<ASTNode> parseMultiplicativeExpression();
    std::unique_ptr<ASTNode> parseAdditiveExpression();

public:
    explicit Parser(Lexer& lexer);
    Token getCurrentToken() const;
    std::unique_ptr<Program> parseProgram();
};

#endif
