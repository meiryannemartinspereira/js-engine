#include "lexer.hpp"

Lexer::Lexer(const std::string& source)
    : source(source), position(0) {
}