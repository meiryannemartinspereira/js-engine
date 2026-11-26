#include "interpreter_test.hpp"
#include "../../src/lexer/lexer.hpp"
#include "../../src/parser/parser.hpp"
#include "../../src/interpreter/interpreter.hpp"
#include "../../src/ast/variable_declaration.hpp"
#include "../../src/ast/binary_expression.hpp"
#include "../../src/ast/number_expression.hpp"
#include "../../src/ast/string_expression.hpp"
#include <stdexcept>
#include <string>
#include <memory>
#include <utility>

void InterpreterTest::run()
{
    struct TestCase
    {
        std::string source;
        double expected;
    };

    TestCase cases[] = {
        {"let resultado = 8 + 2;", 10},
        {"let resultado = 8 - 2;", 6},
        {"let resultado = 8 * 2;", 16},
        {"let resultado = 8 / 2;", 4},
        {"let resultado = 8 % 3;", 2},
        {"let resultado = 2 + 3 * 4;", 14},
        {"let resultado = (2 + 3) * 4;", 20},
        {"let resultado = 10 - (4 / 2);", 8}
    };

    Interpreter interpreter;

    for (const auto& testCase : cases)
    {
        Lexer lexer(testCase.source);
        Parser parser(lexer);

        auto program = parser.parseProgram();

        auto* declaration = dynamic_cast<VariableDeclaration*>(
            program->body[0].get()
        );

        if (declaration == nullptr)
        {
            throw std::runtime_error("Invalid variable declaration");
        }

        double result = interpreter.evaluate(*declaration->initializer);

        if (result != testCase.expected)
        {
            throw std::runtime_error(
                "Interpreter returned an unexpected result"
            );
        }
    }

    auto left = std::make_unique<NumberExpression>(2);
    auto right = std::make_unique<NumberExpression>(3);

    BinaryExpression invalidOperator(
        std::move(left),
        "^",
        std::move(right)
    );

    try
    {
        interpreter.evaluate(invalidOperator);
        throw std::runtime_error("Unknown operator was accepted");
    }
    catch (const std::runtime_error& error)
    {
        if (std::string(error.what()) == "Unknown operator was accepted")
        {
            throw;
        }
    }

    StringExpression unsupportedString("hello");

    try
    {
        interpreter.evaluate(unsupportedString);
        throw std::runtime_error("Unsupported node was accepted");
    }
    catch (const std::runtime_error& error)
    {
        if (std::string(error.what()) == "Unsupported node was accepted")
        {
            throw;
        }
    }
}
