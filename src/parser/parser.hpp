#ifndef PARSER_HPP
#define PARSER_HPP

#include "../lexer/lexer.hpp"

class Parser
{
private:
    Lexer& lexer;
    Token currentToken;

    void expect(TokenType type);
    void advance();
    void parseVariableDeclaration();
    void parseExpression();

public:
    explicit Parser(Lexer& lexer);
    Token getCurrentToken() const;
    void parseProgram(); 
};

#endif