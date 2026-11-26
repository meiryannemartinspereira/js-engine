
#ifndef VARIABLE_DECLARATION_HPP
#define VARIABLE_DECLARATION_HPP

#include "ast_node.hpp"
#include <memory>
#include <string>
#include <utility>

class VariableDeclaration : public ASTNode
{
public:
    std::string kind;
    std::string name;
    std::unique_ptr<ASTNode> initializer;

    VariableDeclaration(
        const std::string& kind,
        const std::string& name,
        std::unique_ptr<ASTNode> initializer
    )
        : kind(kind),
          name(name),
          initializer(std::move(initializer))
    {
    }
};

#endif
