#include "sorting_test.hpp"
#include "../src/integrated_sort.cpp"

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

    for (int i = 0; i < 20; ++i)
        EXPECT_EQ(19-i, arr[i]);
}

TEST_F(IntegratedSortTest, LambdaCmp) {
    shuffle_vec(arr.begin(), arr.end());

    IntegratedSort<int>::sort(arr, [](int a, int b) { return a > b; });

    for (int i = 19; i >= 0; --i)
        EXPECT_EQ(i, 19-arr[i]);
}