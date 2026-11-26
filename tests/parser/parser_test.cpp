#include "parser_test.hpp"
#include "../../src/lexer/lexer.hpp"
#include "../../src/parser/parser.hpp"
#include <string>
#include <stdexcept>

void ParserTest::run()
{
    std::string validSource =
        "let a = (2 + 3) * 4;"
        "let b = 10 - (4 / 2);"
        "let c = (10 * 2) / (5 % 3);"
        "let d = ((2 + 3) * 4) - 5;";

    Lexer validLexer(validSource);
    Parser validParser(validLexer);

    validParser.parseProgram();

    std::string invalidSource[] = {
        "let a = (2 + 3;",
        "let b = 10 + ;",
        "let c = (5 * 2));"};

    for (const auto& source : invalidSource)
    {
        try
        {
            Lexer lexer(source);
            Parser parser(lexer);

            parser.parseProgram();

            throw std::runtime_error("Invalid source was accepted");
        }
        catch(const std::runtime_error& error)
        {
            if (std::string(error.what()) == "Invalid source was accepted"){
                throw;
            }
        }
        
    }
}
