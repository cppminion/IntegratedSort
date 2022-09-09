#include "sorting_test.hpp"
#include "integrated_sort.hpp"

class IntegratedSortTest : public SortingTest {
    void SetUp() override {
        create_int_vec(20);
    }
};

TEST_F(IntegratedSortTest, SimpleInt) {
    shuffle_vec(arr.begin(), arr.end());
    IntegratedSort<int>::sort(arr);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
}

TEST_F(IntegratedSortTest, CustomizedCmp) {
    shuffle_vec(arr.begin(), arr.end());

    struct greater_than {
        inline bool operator() (const int& a, const int& b) {
            return a > b;
        }
    };
    IntegratedSort<int>::sort(arr, greater_than());

    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), greater_than()));
}

TEST_F(IntegratedSortTest, LambdaCmp) {
    shuffle_vec(arr.begin(), arr.end());

    auto comp = [] (int a, int b) { return a > b; };
    IntegratedSort<int>::sort(arr, comp);

    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), comp));
}