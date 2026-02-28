#pragma once

#include "main.hh"

class EDF::Parser {
  private:
    std::vector<Token> tokens;

    Token& current_token();
    // bool match();

  public:
    std::unique_ptr<AST::Base> parse();

    Parser(std::vector<Token> tokens) : tokens(std::move(tokens)) {};
    ~Parser() = default;
};
