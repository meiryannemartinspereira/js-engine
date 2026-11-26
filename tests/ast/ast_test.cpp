
#include "ast_test.hpp"
#include "../../src/ast/number_expression.hpp"
#include "../../src/ast/binary_expression.hpp"
#include <memory>
#include <stdexcept>

void ASTTest::run()
{
    auto left = std::make_unique<NumberExpression>(2);

    auto multiplicationLeft = std::make_unique<NumberExpression>(3);
    auto multiplicationRight = std::make_unique<NumberExpression>(4);

    auto multiplication = std::make_unique<BinaryExpression>(
        std::move(multiplicationLeft),
        "*",
        std::move(multiplicationRight));

    auto addition = std::make_unique<BinaryExpression>(
        std::move(left),
        "+",
        std::move(multiplication));

    if (addition->op != "+")
    {
        throw std::runtime_error("Invalid addition operator");
    }
    auto *rightExpression = dynamic_cast<BinaryExpression *>(addition->right.get());

    if (rightExpression == nullptr || rightExpression->op != "*")
    {
        throw std::runtime_error("Invalid multiplication operator");
    }
}
