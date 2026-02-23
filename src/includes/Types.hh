#pragma once

#include "EDF.hh"

namespace EDF::Types {
  enum class States : short;
  struct Token;
  
  class Lexer;
}

enum class EDF::Types::States : short {
  UNKNOWN = -1,
  START,
  
  NEWLINE,
  WHITESPACE,
  
  IDENTIFIER,
  INTEGER,
  STRING_START,
  STRING_BODY,
  STRING_END,
  CHAR_START,
  CHAR_BODY,
  CHAR_END,

  TEMPLATE_START,
  TEMPLATE_END,
  INTERPOLATION_START,
  INTERPOLATION_END,
  
  LEFT_PARENTHESIS,
  RIGHT_PARENTHESIS,
  LEFT_BRACKET,
  RIGHT_BRACKET,
  LEFT_BRACE,
  RIGHT_BRACE,
  COMMA,
  AT,
  
  COLON,
  DECIMAL,
  PLUS,
  MINUS,
  MULT,
  DIV,
  MOD,
  SPREAD,

  DEFINE,
  MIXIN,
  CONST,
  
  NUMBER_STATES
};

struct EDF::Types::Token {
  EDF::Types::States state;
  std::string_view lexeme;
  
  Token(EDF::Types::States state, std::string_view lexeme) : state(state), lexeme(lexeme) {};
  ~Token() = default;
};

using States = EDF::Types::States;
using Token = EDF::Types::Token;
