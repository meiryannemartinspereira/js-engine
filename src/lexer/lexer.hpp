#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include "token.hpp"

class Lexer {
private:
    std::string source;
    size_t position;

public:
    explicit Lexer(const std::string& source);

};

#endif