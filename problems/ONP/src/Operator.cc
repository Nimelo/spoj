#include "Operator.hpp"

#include <string>
#include "Associativity.hpp"

namespace spoj::operators {
  Operator::Operator(const std::string & literal, const Associativity & associativity, const unsigned int precedence)
    : _literal(literal), _associativity(associativity), _precedence(precedence) {}

  std::string Operator::getLiteral() const {
    return this->_literal;
  }

  unsigned int Operator::getPrecedence() const {
    return this->_precedence;
  }

  Associativity Operator::getAssociativity() const {
    return this->_associativity;
  }

  bool Operator::operator==(const Operator & rhs) const {
    return this->getLiteral() == rhs.getLiteral();
  }

  bool Operator::operator!=(const Operator & rhs) const {
    return !(*this==rhs);
  }
}