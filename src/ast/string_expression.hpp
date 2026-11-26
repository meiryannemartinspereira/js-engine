#ifndef STRING_EXPRESSION_HPP
#define STRING_EXPRESSION_HPP

#include "ast_node.hpp"
#include <string>

class StringExpression : public ASTNode
{
public:
    std::string value;

    explicit StringExpression(const std::string& value)
        : value(value)
    {

    }
};

#endif