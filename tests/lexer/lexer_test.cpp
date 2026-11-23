
#include "lexer_test.hpp"
#include "../../src/lexer/lexer.hpp"
#include <iostream>

void LexerTest::run()
{
    std::string source = "a + b - c * d / e % f ++ -- x += 1 @ 20 y -= 2 z *= 3 q /= 4 r %= 5 a == b === c != d !== e > f < g >= h <= i && j || k ! l & |;";
    Lexer lexer(source);

    while (true)
    {
        Token token = lexer.nextToken();

        if (token.type == TokenType::END_OF_FILE)
        {
            break;
        }
        std::cout << tokenTypeToString(token.type)
                  << " -> " << token.value << std::endl;
    }
}
