#include "PrimeGenerator.h"

#include <numeric>
#include <cmath>
#include <cstddef>

namespace spoj::generators {
        std::vector<unsigned long> PrimeGenerator::generate() {
            using namespace std;
            std::vector<unsigned long> primes;
            std::vector<bool> sieve(upper_bound + 1);
            std::fill(sieve.begin(), sieve.end(), true);
            for(size_t i = 2; i < (size_t)ceil(sqrt(upper_bound)); ++i) {
                if(sieve[i])
                    for(size_t j = i * i; j <= upper_bound; j += i) {
                        sieve[j] = false;
                    }
            }

            for(size_t i = max((size_t)2, lower_bound); i < sieve.size(); ++i) {
                if (sieve[i]) {
                    primes.push_back(i);
                }
            }
            return primes;
        }
    
}
