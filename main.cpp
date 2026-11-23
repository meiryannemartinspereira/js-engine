#include <iostream>
#include "src/lexer/lexer.hpp"

int main() {
    std::string source = "let idade = 12345;";

    Lexer lexer(source);

    for (int i = 0; i < 5; i++) {
        Token token = lexer.nextToken();
        std::cout << token.value << std::endl;
    }

    return 0;
}