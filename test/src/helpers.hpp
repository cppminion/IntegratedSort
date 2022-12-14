#ifndef SORTCOMP_HELPERS_HPP
#define SORTCOMP_HELPERS_HPP

#include <algorithm>
#include <chrono>
#include <random>
#include <vector>

// helper function to shuffle vector
template <class It> void shuffle_vec(It begin, It end) {
    auto rd = std::random_device{};
    auto rng = std::default_random_engine{rd()};
    std::shuffle(begin, end, rng);
}

// helper function to create a vector from range [0, size]
auto create_vec(int size) {
    std::vector<int> arr(size);
    iota(arr.begin(), arr.end(), 0);
    return arr;
};

// helpre function to calculate power of 10
int pow10(int n) {
    int res = 1;
    for (int i = 1; i <= n; ++i) {
        res *= 10;
    }
    return res;
}

#endif // SORTCOMP_HELPERS_HPP
