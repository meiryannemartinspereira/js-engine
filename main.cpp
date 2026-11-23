#include <iostream>
#include "src/lexer/lexer.hpp"

int main() {
    std::string source = "idade 12345";
    Lexer lexer(source);

    Token firstToken = lexer.nextToken();
    Token secondToken = lexer.nextToken();

    std::cout << "Primeiro token: " << firstToken.value << std::endl;
    std::cout << "Segundo token: " << secondToken.value << std::endl;

    return 0;
}