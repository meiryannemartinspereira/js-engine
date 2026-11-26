
#include "parser_test.hpp"
#include "../../src/lexer/lexer.hpp"
#include "../../src/parser/parser.hpp"
#include "../../src/ast/variable_declaration.hpp"
#include "../../src/ast/binary_expression.hpp"
#include "../../src/ast/number_expression.hpp"
#include <string>
#include <stdexcept>

void ParserTest::run()
{
    std::string validSource =
        "let a = (2 + 3) * 4;"
        "let b = 10 - (4 / 2);"
        "let c = (10 * 2) / (5 % 3);"
        "let d = ((2 + 3) * 4) - 5;";

    Lexer validLexer(validSource);
    Parser validParser(validLexer);

    auto program = validParser.parseProgram();

    if (program->body.size() != 4)
    {
        throw std::runtime_error("Invalid number of declarations");
    }

    auto* declaration = dynamic_cast<VariableDeclaration*>(
        program->body[0].get()
    );

    if (declaration == nullptr)
    {
        throw std::runtime_error("Invalid variable declaration");
    }

    if (declaration->kind != "let" || declaration->name != "a")
    {
        throw std::runtime_error("Invalid declaration properties");
    }

    auto* multiplication = dynamic_cast<BinaryExpression*>(
        declaration->initializer.get()
    );

    if (multiplication == nullptr || multiplication->op != "*")
    {
        throw std::runtime_error("Invalid multiplication expression");
    }

    auto* addition = dynamic_cast<BinaryExpression*>(
        multiplication->left.get()
    );

    if (addition == nullptr || addition->op != "+")
    {
        throw std::runtime_error("Invalid addition expression");
    }

    auto* leftNumber = dynamic_cast<NumberExpression*>(
        addition->left.get()
    );

    auto* middleNumber = dynamic_cast<NumberExpression*>(
        addition->right.get()
    );

    auto* rightNumber = dynamic_cast<NumberExpression*>(
        multiplication->right.get()
    );

    if (
        leftNumber == nullptr ||
        middleNumber == nullptr ||
        rightNumber == nullptr ||
        leftNumber->value != 2 ||
        middleNumber->value != 3 ||
        rightNumber->value != 4
    )
    {
        throw std::runtime_error("Invalid expression values");
    }

    std::string invalidSource[] = {
        "let a = (2 + 3;",
        "let b = 10 + ;",
        "let c = (5 * 2));"
    };

    for (const auto& source : invalidSource)
    {
        try
        {
            Lexer lexer(source);
            Parser parser(lexer);

            parser.parseProgram();

            throw std::runtime_error("Invalid source was accepted");
        }
        catch (const std::runtime_error& error)
        {
            if (std::string(error.what()) == "Invalid source was accepted")
            {
                throw;
            }
        }
    }
}
