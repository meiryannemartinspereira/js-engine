
cmake_minimum_required(VERSION 3.20)

project(JavaScriptEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(js-engine
    main.cpp
    src/lexer/token.cpp
    src/lexer/lexer.cpp
    src/lexer/readers/identifier_reader.cpp
    src/lexer/readers/number_reader.cpp
    src/lexer/readers/operator_reader.cpp
    src/lexer/readers/string_reader.cpp
    src/parser/parser.cpp
    src/ast/ast_printer.cpp
    tests/lexer/lexer_test.cpp
    tests/parser/parser_test.cpp
    tests/ast/ast_test.cpp
)
