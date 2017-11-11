#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#include "RPN.hpp"
#include "DefaultTokenProvider.hpp"
#include "Operator.hpp"
#include "Associativity.hpp"

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