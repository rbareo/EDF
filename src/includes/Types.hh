#pragma once

#include "EDF.hh"

namespace EDF::Types {
  enum class Errors : short;
  enum class States : short;
  struct Token;
}

enum class EDF::Types::Errors : short {
};

enum class EDF::Types::States : short {
  UNKNOWN = -1,
  START,
  
  GREATER_PARTIAL,
  LESS_PARTIAL,
  EQUALS_PARTIAL,
  AND_PARTIAL,
  OR_PARTIAL,

  IDENTIFIER,

  TYPE_CHAR,
  TYPE_INT,
  TYPE_FLOAT,

  INTEGER_LITERAL,
  FLOAT_LITERAL,
  TEMPLATE_LITERAL,
  STRING_LITERAL,
  CHAR_LITERAL,

  TEMPLATE_START,
  TEMPLATE_BODY,
  TEMPLATE_END,
  STRING_START,
  STRING_BODY,
  STRING_END,
  CHAR_START,
  CHAR_BODY,
  CHAR_END,
  
  LEFT_PARENTHESIS,
  RIGHT_PARENTHESIS,
  LEFT_BRACKET,
  RIGHT_BRACKET,
  LEFT_BRACE,
  RIGHT_BRACE,
  COMMA,
  AT,
  POUND,
  DOLLAR,
  QUESTION,
  
  COLON,

  PLUS,
  MINUS,
  MULT,
  DIV,
  MOD,

  GREATER_THAN,
  LESS_THAN,
  GREATER_EQUALS,
  LESS_EQUALS,
  EQUALS,
  NOT_EQUALS,

  AND,
  OR,
  NOT,

  /* Going to let parser handle identifier -> keywords
  DEFINE,
  IMPORT,
  AS,
  EXTENDS,
  SCHEMA,
  LOCAL,
  MIXIN,
  CONST,
  IF,
  ELIF,
  ELSE,
  TYPE,
  OVERRIDE,
  */
  
  NUMBER_STATES
};

struct EDF::Types::Token {
  EDF::Types::States state;
  std::string_view lexeme;
  size_t line_number;
  
  Token(EDF::Types::States state, std::string_view lexeme, size_t line_number)
    : state(state), lexeme(lexeme), line_number(line_number) {};
  ~Token() = default;
};

using Errors = EDF::Types::Errors;
using States = EDF::Types::States;
using Token = EDF::Types::Token;
