#include "interpreter.hpp"
#include "../ast/number_expression.hpp"
#include "../ast/binary_expression.hpp"
#include <stdexcept>

double Interpreter::evaluate(const ASTNode& node) const
{
    if (const auto* number = dynamic_cast<const NumberExpression*>(&node))
    {
        return number->value;
    }

    if (const auto* binary = dynamic_cast<const BinaryExpression*>(&node))
    {
        double left = evaluate(*binary->left);
        double right = evaluate(*binary->right);

        if (binary->op == "+")
        {
            return left + right;
        }

        if (binary->op == "-")
        {
            return left - right;
        }

        if (binary->op == "*")
        {
            return left * right;
        }

        if (binary->op == "/")
        {
            return left / right;
        }

        if (binary->op == "%")
        {
            return static_cast<int>(left) % static_cast<int>(right);
        }

        throw std::runtime_error("Unknown binary operator: " + binary->op);
    }

    throw std::runtime_error("Unsupported AST node");
}
