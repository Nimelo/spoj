#define BOOST_TEST_MODULE PrimeGeneratorTest

#include "PrimeGenerator.h"

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(PrimeGeneratorSuite)

BOOST_AUTO_TEST_CASE(ShouldReturnFirstTwoPrimes)
{
    // Arrange
    std::vector<unsigned int> expectedPrimes = {2, 3};
    spoj::generators::PrimeGenerator pg(2, 3);
    
    // Act
    auto primes = pg.generate();

    // Assert
    BOOST_CHECK_EQUAL_COLLECTIONS(primes.begin(), primes.end(), expectedPrimes.begin(), expectedPrimes.end());
}

BOOST_AUTO_TEST_CASE(ShouldReturnFirstThreePrimes)
{
    // Arrange
    std::vector<unsigned int> expectedPrimes = {2, 3, 5};
    spoj::generators::PrimeGenerator pg(2, 5);
    
    // Act
    auto primes = pg.generate();

    // Assert
    BOOST_CHECK_EQUAL_COLLECTIONS(primes.begin(), primes.end(), expectedPrimes.begin(), expectedPrimes.end());
}

BOOST_AUTO_TEST_CASE(ShouldReturnPrimesSmallerThen60)
{
    // Arrange
    std::vector<unsigned int> expectedPrimes = 
    {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
    spoj::generators::PrimeGenerator pg(2, 60);
    
    // Act
    auto primes = pg.generate();

    // Assert
    BOOST_CHECK_EQUAL_COLLECTIONS(primes.begin(), primes.end(), expectedPrimes.begin(), expectedPrimes.end());
}

BOOST_AUTO_TEST_CASE(SpojTestOne)
{
    // Arrange
    std::vector<unsigned int> expectedPrimes = {2, 3, 5, 7};
    spoj::generators::PrimeGenerator pg(1, 10);
    
    // Act
    auto primes = pg.generate();

    // Assert
    BOOST_CHECK_EQUAL_COLLECTIONS(primes.begin(), primes.end(), expectedPrimes.begin(), expectedPrimes.end());
}

BOOST_AUTO_TEST_CASE(SpojTestTwo)
{
    // Arrange
    std::vector<unsigned int> expectedPrimes = {3, 5};
    spoj::generators::PrimeGenerator pg(3, 5);
    
    // Act
    auto primes = pg.generate();

    // Assert
    BOOST_CHECK_EQUAL_COLLECTIONS(primes.begin(), primes.end(), expectedPrimes.begin(), expectedPrimes.end());
}

BOOST_AUTO_TEST_SUITE_END()