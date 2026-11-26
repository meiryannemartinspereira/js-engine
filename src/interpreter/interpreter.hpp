#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include "../ast/ast_node.hpp"

class Interpreter
{
public:
    double evaluate(const ASTNode& node) const;
};

#endif