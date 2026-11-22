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

public:
    explicit Lexer(const std::string& source);
    void prepareNextChar();
    char readCurrentChar() {
    char character = currentChar();
    advance();
    return character;
}
};

#endif