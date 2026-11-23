#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include "token.hpp"

class Lexer {
private:
    std::string source;
    size_t position;

    char currentChar() const;
    void advance();
    void skipWhitespace();
    bool isAlpha(char character) const;
    bool isDigit(char character) const;

    Token readNumber();
    Token readIdentifier();

public:
    explicit Lexer(const std::string& source);
    void prepareNextChar();
    Token nextToken();
    char readCurrentChar() {
    char character = currentChar();
    advance();
    return character;
}
};

#endif