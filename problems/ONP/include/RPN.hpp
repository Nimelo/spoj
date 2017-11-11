#pragma once

#include <string>
#include <vector>
#include <map>

#include "ITokenProvider.hpp"
#include "Operator.hpp"

namespace spoj::rpn {
class RPN {
public:
  RPN(const std::vector<spoj::operators::Operator> & operators);
  std::vector<std::string> shuntingYardAlgorithm(spoj::tokens::ITokenProvider & tokenProvider) const;
private:
  std::map<std::string, spoj::operators::Operator> _operators;
  bool isNonOperator(std::string & token) const;
};
}