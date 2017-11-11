#define BOOST_TEST_MODULE OperatorTest

#include "Operator.hpp"
#include <string>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(OperatorSuite)

BOOST_AUTO_TEST_CASE(ShouldBeEqual)
{
    using namespace spoj::operators;
    // Arrange
    auto expectedOperator = Operator(std::string("+"), Associativity::RIGHT, 0);
    auto actualOperator = Operator(std::string("+"), Associativity::LEFT, 1);
    
    // Act
    auto areEqual = expectedOperator==actualOperator;

    // Assert
    BOOST_CHECK(areEqual);
}

BOOST_AUTO_TEST_CASE(ShouldNotBeEqual)
{
    using namespace spoj::operators;
    // Arrange
    auto expectedOperator = Operator(std::string("+"), Associativity::RIGHT, 0);
    auto actualOperator = Operator(std::string("-"), Associativity::LEFT, 1);
    
    // Act
    auto areDifferent = expectedOperator!=actualOperator;

    // Assert
    BOOST_CHECK(areDifferent);
}

BOOST_AUTO_TEST_SUITE_END()