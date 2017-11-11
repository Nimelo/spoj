#define BOOST_TEST_MODULE DefaultTokenProviderTest

#include "DefaultTokenProvider.hpp"
#include <string>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(DefaultTokenProviderSuite)

using namespace spoj::tokens;
using namespace std;

BOOST_AUTO_TEST_CASE(ShouldReturnTwoTokens)
{
    // Arrange
    DefaultTokenProvider tokenProvider(string("12"));
    
    // Act + Assert
    BOOST_CHECK(tokenProvider.hasNext());
    tokenProvider.getNext();
    BOOST_CHECK(tokenProvider.hasNext());
    tokenProvider.getNext();
    BOOST_CHECK(!tokenProvider.hasNext());
}

BOOST_AUTO_TEST_CASE(ShouldBeEmpty)
{
    // Arrange
    DefaultTokenProvider tokenProvider(string(""));
    
    // Act + Assert
    BOOST_CHECK(!tokenProvider.hasNext());
}

BOOST_AUTO_TEST_CASE(ShouldReturn2Letters)
{
    // Arrange
    DefaultTokenProvider tokenProvider(string("ab"));
    
    // Act + Assert
    BOOST_CHECK_EQUAL(string("a"), tokenProvider.getNext());
    BOOST_CHECK_EQUAL(string("b"), tokenProvider.getNext());
}

BOOST_AUTO_TEST_SUITE_END()