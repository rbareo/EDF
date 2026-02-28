#pragma once

#include "main.hh"

namespace EDF::Types::AST {
  enum class Kinds : short;
  enum class Types : short;
  enum class Operators : short;
  enum class Native_Types : short;

  class Base; // Abstract

  class Definition; // Abstract
  class Mixin;
  class Const;
  class Type;
  class Alias;

  class Expression; // Abstract
  class Unary_Expression;
  class Binary_Expression;

  class Statement; // Abstract
  class If;

  class Value; // Abstract
  class Function_Call;
  class Reference;

  class Literal; // Abstract
  class Scalar;
  class Array;
  class Record;
}

namespace AST = EDF::Types::AST;

enum class AST::Kinds : short {
  MIXIN,
  CONST,
  TYPE,
  ALIAS,
  UNARY_EXPRESSION,
  BINARY_EXPRESSION,
  IF,
  FUNCTION_CALL,
  REFERENCE,
  SCALAR,
  ARRAY,
  RECORD
};

enum class AST::Operators : short {
  PLUS,
  MINUS,
  MULT,
  DIV,
  LESS_THAN,
  GREATER_THAN,
  LESS_EQUALS,
  GREATER_EQUALS,
  EQUALS,
  NOT_EQUALS,
  NOT,
  AND,
  OR
};

enum class AST::Native_Types : short {

};

// Abstract
class AST::Base {
  public:
    AST::Kinds kind;

    Base(AST::Kinds kind) : kind(kind) {};
    ~Base() = default;
};

// Abstract
class AST::Statement : public AST::Base {
  public:
    Statement(AST::Kinds kind) : Base(kind) {};
    ~Statement() = default;
};

 // Abstract
class AST::Definition : public AST::Statement {
  public:
    std::string_view identifier;

    Definition(AST::Kinds kind, std::string_view identifier) : Statement(kind), identifier(identifier) {};
    ~Definition() = default;
};

class AST::Mixin : public AST::Definition {
  public:
    std::unique_ptr<AST::Record> value;

    Mixin(std::unique_ptr<AST::Record> value, std::string_view identifier)
      : Definition(AST::Kinds::MIXIN, identifier), value(std::move(value)) {};
    ~Mixin() = default;
};

class AST::Const : public AST::Definition {
  public:
    std::unique_ptr<AST::Value> value;

    Const(std::unique_ptr<AST::Value>, std::string_view identifier)
      : Definition(AST::Kinds::CONST, identifier), value(std::move(value)) {};
    ~Const() = default;
};
class AST::Type : public AST::Definition {
  public:
    std::vector<Native_Types> value;

    Type(std::vector<Native_Types> value, std::string_view identifier)
      : Definition(AST::Kinds::TYPE, identifier), value(value) {};
    ~Type() = default;
};

class AST::Alias : public AST::Definition {
  public:
    std::unique_ptr<AST::Type> type;

    Alias(std::unique_ptr<AST::Type> type, std::string_view identifier)
      : Definition(AST::Kinds::TYPE, identifier), type(std::move(type)) {};
    ~Alias() = default;
};

// Abstract
class AST::Expression : public AST::Base {
  public:
    Expression(AST::Kinds kind) : Base(kind) {};
    ~Expression() = default;
};

class AST::Unary_Expression : public AST::Expression {
  public:
    std::unique_ptr<AST::Expression> inner;
    AST::Operators Operator;

    Unary_Expression(std::unique_ptr<AST::Expression> inner, AST::Operators Operator)
      : Expression(AST::Kinds::UNARY_EXPRESSION), inner(std::move(inner)), Operator(Operator) {};
    ~Unary_Expression() = default;
};

class AST::Binary_Expression : public AST::Expression {
  public:
    std::unique_ptr<AST::Expression> left;
    std::unique_ptr<AST::Expression> right;
    AST::Operators Operator;

    Binary_Expression(std::unique_ptr<AST::Expression> left, std::unique_ptr<AST::Expression> right,
      AST::Operators Operator) : Expression(AST::Kinds::BINARY_EXPRESSION),
      left(std::move(left)), right(std::move(right)), Operator(std::move(Operator)) {};
    ~Binary_Expression() = default;
};

class AST::If : public AST::Statement {
  public:
    std::unique_ptr<AST::Expression> condition;
    std::unique_ptr<AST::Record> branch_true;
    std::unique_ptr<AST::Record> branch_false;

    If(std::unique_ptr<AST::Expression> condition, std::unique_ptr<AST::Record> block,
      std::unique_ptr<AST::Record> other = nullptr) : Statement(AST::Kinds::IF), condition(std::move(condition)),
      branch_true(std::move(branch_true)), branch_false(std::move(branch_false)) {};
    ~If() = default;
};

// Abstract
class AST::Value : public AST::Expression {
  public:
    Value(AST::Kinds kind) : Expression(kind) {};
    ~Value() = default;
};

class AST::Function_Call : public AST::Value {
  public:
    std::string_view identifier;
    std::vector<std::unique_ptr<AST::Expression>> arguments;

    Function_Call(std::string_view identifier, std::vector<std::unique_ptr<AST::Expression>> arguments)
      : Value(AST::Kinds::FUNCTION_CALL), identifier(identifier), arguments(std::move(arguments)) {};
    ~Function_Call() = default;
};
class AST::Reference : public AST::Value {
  public:
    std::string_view identifier;

    Reference(std::string_view identifier) : Value(AST::Kinds::REFERENCE), identifier(identifier) {};
    ~Reference() = default;
};

// Abstract
class AST::Literal : public AST::Value {
  public:
    Literal(AST::Kinds kind) : Value(kind) {};
    ~Literal() = default;
};

class AST::Scalar : public AST::Literal {
  public:
    std::string_view value;
    std::unique_ptr<Type> type;

    Scalar(std::string_view value, std::unique_ptr<Type> type)
      : Literal(AST::Kinds::SCALAR), value(value), type(std::move(type)) {};
    ~Scalar() = default;
};

class AST::Array : public AST::Literal {
  public:
    std::vector<std::string_view> value;
    std::unique_ptr<Type> type;

    Array(std::vector<std::string_view> value, std::unique_ptr<Type> type)
      : Literal(AST::Kinds::ARRAY), value(value), type(std::move(type)) {};
    ~Array() = default;
};

class AST::Record : public AST::Literal {
  public:
    std::vector<std::unique_ptr<Statement>> statements;

    Record(std::vector<std::unique_ptr<Statement>> statements)
      : Literal(AST::Kinds::RECORD), statements(std::move(statements)) {};
    ~Record() = default;
};
