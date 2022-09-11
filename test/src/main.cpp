#include <iostream>
#include <fstream>
#include "helpers.hpp"
#include "sorting.hpp"

// section c.1
// fixed S, plot number of key comparisons w.r.t. size
void plot_key_comp (int S) {
    std::vector<int> sizes; // sizes of input array
    for (int i = 1000; i < 100000; i+=500) {
        sizes.push_back(i);
    }

    std::vector<std::vector<int>> arrs; // generate test data
    for (auto size : sizes) {
        arrs.push_back(create_vec(size));
    }
    std::vector<int> res;
    for (auto arr : arrs) {
        shuffle_vec(arr.begin(), arr.end());
        KEY_COMPS = 0;
        integrated_sort(arr, S);
        res.push_back(KEY_COMPS);
    }

    std::ofstream myfile;
    std::string file_name = "key_comp_" + std::to_string(S);
    myfile.open("../data/" + file_name + ".csv");
    
    myfile << "comps,size\n";
    for (int i = 0; i < res.size(); ++i) {
        myfile << res[i] << "," << sizes[i] << std::endl;
    }
    myfile.close();
}

// section c.ii
// time w.r.t size of the array 
void plot_S_val(int S) {
    std::vector<int> sizes; // sizes of input array
    for (int i = 1000; i < 100000; i+=500) {
        sizes.push_back(i);
    }

    std::vector<std::vector<int>> arrs; // generate test data
    for (auto size : sizes) {
        arrs.push_back(create_vec(size));
    }
    std::vector<int> res;
    for (auto arr : arrs) {
        shuffle_vec(arr.begin(), arr.end());
        auto start = std::chrono::high_resolution_clock::now();
        integrated_sort(arr, S);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
        res.push_back(duration.count());
    }
    
    std::ofstream myfile;
    std::string file_name = "val_S_" + std::to_string(S);
    myfile.open("../data/" + file_name + ".csv");
    
    myfile << "time,size\n";
    for (int i = 0; i < res.size(); ++i) {
        myfile << res[i] << "," << sizes[i] << std::endl;
    }
    myfile.close();
}

// try different S w.r.t. time, tring to find the S that minimize the time
void plot_optimal_S(int size_10_log) {
    int size = pow10(size_10_log);
    std::vector<int> arr = create_vec(size);
    std::vector<int> res;
    std::vector<int> thresholds;
    for (int i = 4; i < 512; i += 4)
        thresholds.push_back(i);
    for (auto threshold : thresholds) {
        shuffle_vec(arr.begin(), arr.end());
        auto start = std::chrono::high_resolution_clock::now();
        integrated_sort(arr, threshold);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
        res.push_back(duration.count());
    }
    std::ofstream myfile;
    std::string file_name = "optimal_S_1e" + std::to_string(size_10_log);
    myfile.open("../data/" + file_name + ".csv");
    
    myfile << "time,S\n";
    for (int i = 0; i < res.size(); ++i) {
        myfile << res[i] << "," << thresholds[i] << std::endl;
    }
    myfile.close();
    
}

int main() {
    plot_key_comp(16);
    std::cout << "Generated file for threshold 16." << std::endl;
    plot_S_val(16);
    std::cout << "Generated file for threshold 16." << std::endl;
    plot_optimal_S(5);
    std::cout << "Generated file for 1e5." << std::endl;
    std::cout << "Done!" << std::endl;
    return 0;
}
