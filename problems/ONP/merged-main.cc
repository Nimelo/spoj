#include <string>
#include <iostream>
#include <cstddef>
#include <map>
#include <numeric>
#include <vector>
#include <stack>

namespace spoj::operators {
enum Associativity {
  LEFT = 0,
  RIGHT = 1,
  NONE = 2
};
}

namespace spoj::tokens {
  class DefaultTokenProvider : public ITokenProvider {
  public:
    DefaultTokenProvider(const std::string & line);
    DefaultTokenProvider(const char* line);

    virtual std::string getNext();
    virtual bool hasNext() const;
  private:
    std::string content_;
    std::size_t position_;
  };
}

namespace spoj::tokens {
  class ITokenProvider {
  public:
    virtual std::string getNext() = 0;
    virtual bool hasNext() const = 0;
  };
}

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

namespace spoj::tokens {
  DefaultTokenProvider::DefaultTokenProvider(const std::string & line)
    : content_{line}, position_{0} {}

  DefaultTokenProvider::DefaultTokenProvider(const char* line)
    : DefaultTokenProvider(std::string(line)) {}


  std::string DefaultTokenProvider::getNext() {
    return content_.substr(position_++, 1);
  }

  bool DefaultTokenProvider::hasNext() const {
    return position_ < content_.size();
  }
}


int main(int argc, char* argv []) {
  using namespace std;
  using namespace spoj::tokens;
  using namespace spoj::operators;
  using namespace spoj::rpn;
    
  vector<Operator> operators = { 
    Operator(string("^"), Associativity::RIGHT, 4),
    Operator(string("*"), Associativity::LEFT, 3),
    Operator(string("/"), Associativity::LEFT, 3),
    Operator(string("+"), Associativity::LEFT, 2),
    Operator(string("-"), Associativity::LEFT, 2),
    Operator(string("("), Associativity::NONE, 0),
    Operator(string(")"), Associativity::NONE, 0),
  };

  RPN rpn(operators);

  int numberOfTests = 0;
  string line;

  cin >> numberOfTests;

  while(numberOfTests--) {
    cin >> line;
    DefaultTokenProvider tokenProvider(line);
    auto tokens = rpn.shuntingYardAlgorithm(tokenProvider);
    cout << accumulate(tokens.begin(), tokens.end(), string("")) << endl;
  }

  return 0;
}


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

