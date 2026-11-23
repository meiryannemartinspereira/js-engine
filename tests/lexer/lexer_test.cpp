
#include "lexer_test.hpp"
#include "../../src/lexer/lexer.hpp"
#include <iostream>

void LexerTest::run()
{
    std::string source = "total _total $resultado valor_1 $item123";
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
