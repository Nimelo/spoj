#include "PrimeGenerator.h"

#include <iostream>
#include <string>

int main(int argc, char* argv []){
    using namespace std;
    using namespace spoj::generators;
    int number_of_tests = 0;
    int lower_bound = 0, upper_bound = 0;
    
    std::cin >> number_of_tests;
    while(number_of_tests--) {
        std::cin >> lower_bound >> upper_bound;
        PrimeGenerator pg(lower_bound, upper_bound);
        auto primes = pg.generate();
        for(auto prime : primes)
            std::cout << prime << std::endl;
    }  
    return 0;
}
