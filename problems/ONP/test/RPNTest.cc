#define BOOST_TEST_MODULE RPNTest

#include <vector>
#include <string>
#include <numeric>

#include "RPN.hpp"
#include "DefaultTokenProvider.hpp"
#include "Operator.hpp"

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string.hpp>

BOOST_AUTO_TEST_SUITE(RPNSuite)

using namespace spoj::rpn;
using namespace spoj::operators;
using namespace spoj::tokens;
using namespace std;

BOOST_AUTO_TEST_CASE(ShouldReturnEmptyCollection)
{
    // Arrange
    vector<Operator> operators = { Operator(string("+"), Associativity::RIGHT, 1)};
    vector<string> expectedResult = {};
    DefaultTokenProvider tokenProvider("");
    RPN rpn(operators);

    
    // Act
    auto result = rpn.shuntingYardAlgorithm(tokenProvider);

    // Assert
    BOOST_CHECK_EQUAL_COLLECTIONS(
    expectedResult.begin(), expectedResult.end(),
    result.begin(), result.end());
    
}

BOOST_AUTO_TEST_CASE(SingleInputNumber)
{
    // Arrange
    vector<Operator> operators = { Operator(string("+"), Associativity::RIGHT, 1) };
    vector<string> expectedResult = { "2" };
    DefaultTokenProvider tokenProvider("2");
    RPN rpn(operators);
    
    // Act
    auto result = rpn.shuntingYardAlgorithm(tokenProvider);

    // Assert
    BOOST_CHECK_EQUAL_COLLECTIONS(
      expectedResult.begin(), expectedResult.end(),
      result.begin(), result.end()
    );
}

BOOST_AUTO_TEST_CASE(SingleOperator)
{
    // Arrange
    vector<Operator> operators = { Operator(string("+"), Associativity::RIGHT, 1) };
    vector<string> expectedResult = { "+" };
    RPN rpn(operators);
    DefaultTokenProvider tokenProvider("+");

    // Act
    auto result = rpn.shuntingYardAlgorithm(tokenProvider);

    // Assert
    BOOST_CHECK_EQUAL_COLLECTIONS(
      expectedResult.begin(), expectedResult.end(),
      result.begin(), result.end()
    );
}

BOOST_AUTO_TEST_CASE(ShouldCorrectlyParseInput)
{
    // Arrange
    vector<Operator> operators = { Operator(string("+"), Associativity::RIGHT, 1) };
    vector<string> expectedResult = { "2",  "3", "+" };
    DefaultTokenProvider tokenProvider("2+3");
    RPN rpn(operators);
    
    // Act
    auto result = rpn.shuntingYardAlgorithm(tokenProvider);

    // Assert
    BOOST_CHECK_EQUAL_COLLECTIONS(
      expectedResult.begin(), expectedResult.end(),
      result.begin(), result.end()
    );
}

BOOST_AUTO_TEST_CASE(FullTestOne)
{
    // Arrange
    vector<Operator> operators = { 
      Operator(string("^"), Associativity::RIGHT, 4),
      Operator(string("*"), Associativity::LEFT, 3),
      Operator(string("/"), Associativity::LEFT, 3),
      Operator(string("+"), Associativity::LEFT, 2),
      Operator(string("-"), Associativity::LEFT, 2),
      Operator(string("("), Associativity::LEFT, 0),
      Operator(string(")"), Associativity::LEFT, 0),
    };

    string expectedResult  = "342*15-23^^/+";
    DefaultTokenProvider tokenProvider("3+4*2/(1-5)^2^3");
    RPN rpn(operators);
    
    // Act
    auto result = rpn.shuntingYardAlgorithm(tokenProvider);
    string actualResult;
    actualResult = accumulate(result.begin(), result.end(), actualResult);

    // Assert
    BOOST_CHECK_EQUAL(expectedResult, actualResult);
}

BOOST_AUTO_TEST_CASE(SPOJTestOne)
{
    // Arrange
    vector<Operator> operators = { 
      Operator(string("^"), Associativity::RIGHT, 4),
      Operator(string("*"), Associativity::LEFT, 3),
      Operator(string("/"), Associativity::LEFT, 3),
      Operator(string("+"), Associativity::LEFT, 2),
      Operator(string("-"), Associativity::LEFT, 2),
      Operator(string("("), Associativity::LEFT, 0),
      Operator(string(")"), Associativity::LEFT, 0),
    };

    DefaultTokenProvider tokenProvider("(a+(b*c))");
    string expectedResult = "abc*+";
    RPN rpn(operators);
    
    // Act
    auto result = rpn.shuntingYardAlgorithm(tokenProvider);
    string actualResult;
    actualResult = accumulate(result.begin(), result.end(), actualResult);

    // Assert
    BOOST_CHECK_EQUAL(expectedResult, actualResult);
}

BOOST_AUTO_TEST_CASE(SPOJTestTwo)
{
    // Arrange
    vector<Operator> operators = { 
      Operator(string("^"), Associativity::RIGHT, 4),
      Operator(string("*"), Associativity::LEFT, 3),
      Operator(string("/"), Associativity::LEFT, 3),
      Operator(string("+"), Associativity::LEFT, 2),
      Operator(string("-"), Associativity::LEFT, 2),
      Operator(string("("), Associativity::LEFT, 0),
      Operator(string(")"), Associativity::LEFT, 0),
    };

    DefaultTokenProvider tokenProvider("((a+b)*(z+x))");
    string expectedResult = "ab+zx+*";
    RPN rpn(operators);
    
    // Act
    auto result = rpn.shuntingYardAlgorithm(tokenProvider);
    string actualResult;
    actualResult = accumulate(result.begin(), result.end(), actualResult);

    // Assert
    BOOST_CHECK_EQUAL(expectedResult, actualResult);
}

BOOST_AUTO_TEST_CASE(SPOJTestThree)
{
    // Arrange
    vector<Operator> operators = { 
      Operator(string("^"), Associativity::RIGHT, 4),
      Operator(string("*"), Associativity::LEFT, 3),
      Operator(string("/"), Associativity::LEFT, 3),
      Operator(string("+"), Associativity::LEFT, 2),
      Operator(string("-"), Associativity::LEFT, 2),
      Operator(string("("), Associativity::LEFT, 0),
      Operator(string(")"), Associativity::LEFT, 0),
    };
    
    DefaultTokenProvider tokenProvider("((a+t)*((b+(a+c))^(c+d)))");
    string expectedResult = "at+bac++cd+^*";
    RPN rpn(operators);
    
    // Act
    auto result = rpn.shuntingYardAlgorithm(tokenProvider);
    string actualResult;
    actualResult = accumulate(result.begin(), result.end(), actualResult);

    // Assert
    BOOST_CHECK_EQUAL(expectedResult, actualResult);
}

BOOST_AUTO_TEST_SUITE_END()