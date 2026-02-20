#pragma once

#include "SDN.hh"

namespace SDN::Types::AST {
  enum class Kinds : short;

  class Base;
  class Identifier;
  class Literal;
  class Binary_operator;
}

namespace AST = SDN::Types::AST;

enum class AST::Kinds {
  IDENTIFIER,
  LITERAL,
  BINARY_OPERATOR
};

class AST::Base {
  private:
};

class AST::Identifier : public AST::Base {
  private:
};

class AST::Literal : public AST::Base {
  private:
};

class AST::Binary_operator : public AST::Base {
  private:
};
