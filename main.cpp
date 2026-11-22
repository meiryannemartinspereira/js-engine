#include <iostream>
#include "src/lexer/lexer.hpp"

int main() {
    std::string source = "     let x";

    Lexer lexer(source);

    lexer.prepareNextChar();

    std::cout << lexer.readCurrentChar() << std::endl;

    return 0;
}