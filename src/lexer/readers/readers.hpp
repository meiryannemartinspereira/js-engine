
#ifndef READERS_HPP
#define READERS_HPP

#include <string>
#include "../token.hpp"

class IdentifierReader
{
public:
    static Token read(const std::string& source, size_t& position);
};

class NumberReader
{
public:
    static Token read(const std::string& source, size_t& position);
};

class StringReader
{
public:
    static Token read(const std::string& source, size_t& position);
};

class OperatorReader
{
public:
    static Token read(const std::string& source, size_t& position);

private:
    static char peek(const std::string& source, size_t position);
};

#endif
