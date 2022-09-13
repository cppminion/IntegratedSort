#include "integrated_sort.hpp"
#include <iostream>
#include <vector>
int main(int argc, char *argv[]) {
    std::cout << "Hello world!" << std::endl;
    std::vector<int> a = {5, 1, 1, 2, 3};
    IntegratedSort<int>::sort(a);
    for (auto i : a) {
        std::cout << i << " ";
    }
}