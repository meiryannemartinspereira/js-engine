#include "parser_test.hpp"
#include "../../src/lexer/lexer.hpp"
#include "../../src/parser/parser.hpp"
#include <string>

void ParserTest::run()
{
    std::string source = "let idade = 25;";

    Lexer lexer(source);
    Parser parser(lexer);

    parser.parseProgram();
}