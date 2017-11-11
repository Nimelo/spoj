#pragma once

#include <string>
#include "Associativity.hpp"

namespace spoj::operators {
class Operator {
public:
  Operator(const std::string & literal, const Associativity & associativity, const unsigned int precedence);

  std::string getLiteral() const;
  unsigned int getPrecedence() const;
  Associativity getAssociativity() const;
  
  bool operator==(const Operator & rhs) const;
  bool operator!=(const Operator & rhs) const;
private:
  std::string _literal;
  unsigned int _precedence;
  Associativity _associativity;
};
}