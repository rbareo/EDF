#pragma once

#include "SDN.hh"

class SDN::Parser {
  private:
    std::vector<std::unique_ptr<AST::Base>> nodes;

  public:
    std::vector<std::unique_ptr<AST::Base>> parse();
};
