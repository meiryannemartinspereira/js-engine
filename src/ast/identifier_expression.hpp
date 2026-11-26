#ifndef IDENTIFIER_EXPRESSION_HPP
#define IDENTIFIER_EXPRESSION_HPP

#include "ast_node.hpp"
#include <string>

class IdentifierExpression : public ASTNode
{
public:
    std::string name;

    explicit IdentifierExpression(const std::string& name)
        :name(name)
    {

    }
};

#endif