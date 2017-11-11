#include "RPN.hpp"

#include <string>
#include <stack>
#include <vector>

#include "Operator.hpp"
#include "ITokenProvider.hpp"

namespace spoj::rpn {
  RPN::RPN(const std::vector<spoj::operators::Operator> & operators) {
    for(auto op : operators) {
      _operators.insert({op.getLiteral(), op});
    }
  }

  std::vector<std::string> RPN::shuntingYardAlgorithm(spoj::tokens::ITokenProvider & tokenProvider) const {
      using namespace std;
      using namespace spoj::operators;
      vector<std::string> output;
      stack<Operator> operatorStack;

      while(tokenProvider.hasNext()) {
        auto token = tokenProvider.getNext();
        if(isNonOperator(token)) {
          output.push_back(token);
        } else{
          auto op = _operators.find(token)->second;
          if (op.getLiteral() == "(") {
            operatorStack.push(op);
          } else if (op.getLiteral() == ")") {
            while (operatorStack.size() != 0 &&
              operatorStack.top().getLiteral() != "(") {
              auto pop = operatorStack.top();
              operatorStack.pop();
              output.push_back(pop.getLiteral());
            }
            operatorStack.pop();
            // Error
          } else {
            while(operatorStack.size() != 0) {
              auto top = operatorStack.top();
              if(!(top.getPrecedence() >= op.getPrecedence()
                && op.getAssociativity() == Associativity::LEFT)) {
                  break;
              }
              auto pop = operatorStack.top();
              operatorStack.pop();
              output.push_back(pop.getLiteral());
            }
            operatorStack.push(op);
          }
        }
      }

      while (operatorStack.size() != 0) {
        auto pop = operatorStack.top();
        operatorStack.pop();
        output.push_back(pop.getLiteral());
      }

      return output;
    }

    bool RPN::isNonOperator(std::string & token) const {
      return token != "("
       && token != ")"
       && _operators.find(token) == _operators.end();
    }
}

