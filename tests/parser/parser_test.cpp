
#include "parser_test.hpp"
#include "../../src/lexer/lexer.hpp"
#include "../../src/parser/parser.hpp"
#include <string>

void ParserTest::run()
{
    std::string source =
        "let a = (2 + 3) * 4;"
        "let b = 10 - (4 / 2);"
        "let c = (10 * 2) / (5 % 3);"
        "let d = ((2 + 3) * 4) - 5;";

    Lexer lexer(source);
    Parser parser(lexer);

    parser.parseProgram();
}
