#ifndef INTEGRATEDSORT_SORTING_TEST_HPP
#define INTEGRATEDSORT_SORTING_TEST_HPP

#include <vector>
#include <algorithm>
#include <iterator>
#include <random>

#include <gtest/gtest.h>

class SortingTest : public ::testing::Test {
protected:
    void SetUp() override {
        ;
    }

    std::vector<int> arr;
    
    void create_int_vec(int size) {
        for (int i = 0; i < size; ++i) {
            arr.push_back(i);
        }
    }

    template <class It>
    void shuffle_vec(It begin, It end) {
        auto rd = std::random_device {};
        auto rng = std::default_random_engine { rd() };
        std::shuffle(begin, end, rng);
    }
};

#endif //INTEGRATEDSORT_SORTING_TEST_HPP
