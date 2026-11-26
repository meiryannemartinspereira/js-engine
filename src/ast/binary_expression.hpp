
#ifndef BINARY_EXPRESSION_HPP
#define BINARY_EXPRESSION_HPP

#include "ast_node.hpp"
#include <memory>
#include <string>
#include <utility>

class BinaryExpression : public ASTNode
{
public:
    std::unique_ptr<ASTNode> left;
    std::string op;
    std::unique_ptr<ASTNode> right;

    BinaryExpression(
        std::unique_ptr<ASTNode> left,
        const std::string& op,
        std::unique_ptr<ASTNode> right
    )
        : left(std::move(left)),
          op(op),
          right(std::move(right))
    {

    }
};

#endif