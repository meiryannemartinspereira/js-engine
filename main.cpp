
#include "tests/parser/parser_test.hpp"
#include "tests/ast/ast_test.hpp"
#include "src/lexer/lexer.hpp"
#include "src/parser/parser.hpp"
#include "src/ast/ast_printer.hpp"
#include <iostream>
#include <string>

int main()
{
    ParserTest parserTest;
    parserTest.run();

    ASTTest astTest;
    astTest.run();

    std::string source = "let resultado = 2 + 3 * 4;";

    Lexer lexer(source);
    Parser parser(lexer);

    auto program = parser.parseProgram();

    ASTPrinter printer;
    printer.print(*program, std::cout);

    return 0;
}
