#include "lexer.hpp"
#include <cctype>

Lexer::Lexer(const std::string& source)
    : source(source), position(0) {
}

char Lexer::currentChar() const {
    if (position >= source.length()) {
        return '\0';
    }

    return source[position];
}

void Lexer::advance() {
    if (position < source.length()){
        position++;
    }
}

void Lexer::skipWhitespace() {
    while (std::isspace(currentChar())) {
        advance();
    }
}

void Lexer::prepareNextChar() {
    skipWhitespace();
}