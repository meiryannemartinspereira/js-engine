#ifndef NUMBER_EXPRESSION_HPP
#define NUMBER_EXPRESSION_HPP

#include "ast_node.hpp"

class NumberExpression : public ASTNode
{
    public:
        double value;

        explicit NumberExpression(double value)
            : value(value)
        
            {

            }
};

#endif