
#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include "ast_node.hpp"
#include <memory>
#include <vector>

class Program : public ASTNode
{
public:
    std::vector<std::unique_ptr<ASTNode>> body;
};

#endif
