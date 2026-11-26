
#include "ast_printer.hpp"
#include "number_expression.hpp"
#include "string_expression.hpp"
#include "identifier_expression.hpp"
#include "binary_expression.hpp"
#include "variable_declaration.hpp"
#include <string>

void ASTPrinter::print(const Program& program, std::ostream& output) const
{
    output << "Program\n";

    for (const auto& node : program.body)
    {
        printNode(*node, output, 1);
    }
}

void ASTPrinter::printIndentation(std::ostream& output, int indentation) const
{
    for (int i = 0; i < indentation; i++)
    {
        output << "    ";
    }
}

void ASTPrinter::printNode(
    const ASTNode& node,
    std::ostream& output,
    int indentation
) const
{
    printIndentation(output, indentation);

    if (const auto* number = dynamic_cast<const NumberExpression*>(&node))
    {
        output << "NumberExpression: " << number->value << '\n';
        return;
    }

    if (const auto* string = dynamic_cast<const StringExpression*>(&node))
    {
        output << "StringExpression: " << string->value << '\n';
        return;
    }

    if (const auto* identifier = dynamic_cast<const IdentifierExpression*>(&node))
    {
        output << "IdentifierExpression: " << identifier->name << '\n';
        return;
    }

    if (const auto* binary = dynamic_cast<const BinaryExpression*>(&node))
    {
        output << "BinaryExpression: " << binary->op << '\n';

        printIndentation(output, indentation + 1);
        output << "left:\n";
        printNode(*binary->left, output, indentation + 2);

        printIndentation(output, indentation + 1);
        output << "right:\n";
        printNode(*binary->right, output, indentation + 2);

        return;
    }

    if (const auto* declaration = dynamic_cast<const VariableDeclaration*>(&node))
    {
        output << "VariableDeclaration\n";

        printIndentation(output, indentation + 1);
        output << "kind: " << declaration->kind << '\n';

        printIndentation(output, indentation + 1);
        output << "name: " << declaration->name << '\n';

        printIndentation(output, indentation + 1);
        output << "initializer:\n";

        printNode(*declaration->initializer, output, indentation + 2);

        return;
    }

    output << "Unknown ASTNode\n";
}
