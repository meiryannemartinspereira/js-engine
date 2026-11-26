
#include "tests/parser/parser_test.hpp"
#include "tests/ast/ast_test.hpp"
#include "src/lexer/lexer.hpp"
#include "src/parser/parser.hpp"
#include "src/ast/ast_printer.hpp"
#include "src/ast/variable_declaration.hpp"
#include "src/interpreter/interpreter.hpp"
#include "tests/interpreter/interpreter_test.hpp"
#include <iostream>
#include <string>

int main()
{
    ParserTest parserTest;
    parserTest.run();

    ASTTest astTest;
    astTest.run();

    InterpreterTest interpreterTest;
    interpreterTest.run();
    
    std::string source = "let resultado = 2 + 3 * 4;";

    Lexer lexer(source);
    Parser parser(lexer);

    auto program = parser.parseProgram();

    ASTPrinter printer;
    printer.print(*program, std::cout);

    auto* declaration = dynamic_cast<VariableDeclaration*>(
        program->body[0].get()
    );

    Interpreter interpreter;

    double result = interpreter.evaluate(*declaration->initializer);

    std::cout << "Result: " << result << '\n';

    return 0;
}
