#pragma once

#include <cstddef>
#include <vector>

namespace spoj::generators {
    class PrimeGenerator {
    public:
        PrimeGenerator(std::size_t lower_bound, std::size_t upper_bound) :
            lower_bound(lower_bound), upper_bound(upper_bound){}

        std::vector<unsigned long> generate();
    private:
        std::size_t lower_bound;
        std::size_t upper_bound;
    };
}