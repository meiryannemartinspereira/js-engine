
#ifndef AST_PRINTER_HPP
#define AST_PRINTER_HPP

#include "program.hpp"
#include <iostream>

class ASTPrinter
{
public:
    void print(const Program& program, std::ostream& output) const;

private:
    void printNode(
        const ASTNode& node,
        std::ostream& output,
        int indentation
    ) const;

    void printIndentation(std::ostream& output, int indentation) const;
};

#endif
