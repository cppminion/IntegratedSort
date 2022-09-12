#include "helpers.hpp"
#include "sorting.hpp"
#include <chrono>
#include <chrono>
#include <fstream>
#include <iostream>
#include <ratio>
#include <thread>

// section c.1
// fixed S, plot number of key comparisons w.r.t. size
void plot_key_comp(int S) {
    std::vector<int> sizes; // sizes of input array
    for (int i = 1000; i < 1000000; i += 1000) {
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
        SORTING::integrated_sort(arr, S);
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
// average sorting time w.r.t size of the array
void plot_S_val(int S) {
    std::vector<int> sizes; // sizes of input array
    for (int i = 1000; i < 1000000; i += 1000) {
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
        SORTING::integrated_sort(arr, S);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration =
            std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
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
void plot_optimal_S_time(int size_10_log) {
    int size = pow10(size_10_log);
    std::vector<int> arr = create_vec(size);
    std::vector<int> res;
    std::vector<int> thresholds;
    for (int i = 4; i < 32; i += 1)
        thresholds.push_back(i);
    for (auto threshold : thresholds) {
        shuffle_vec(arr.begin(), arr.end());
        auto start = std::chrono::high_resolution_clock::now();
        SORTING::integrated_sort(arr, threshold);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration =
            std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        res.push_back(duration.count());
    }
    std::ofstream myfile;
    std::string file_name = "optimal_S_1e" + std::to_string(size_10_log);
    myfile.open("../data/" + file_name + ".csv");

    myfile << "time,S\n";
    for (int i = 0; i < res.size(); ++i) {
        myfile << res[i]<< "," << thresholds[i] << std::endl;
    }
    myfile.close();
}

// try different S w.r.t. key_comparisons, tring to find the S that minimize the
// time
void plot_optimal_S_comp(int size_10_log) {
    int size = 5 * pow10(size_10_log);
    std::vector<int> arr = create_vec(size);
    std::vector<int> res; // array to store key comparisons

    std::vector<int> thresholds; //
    for (int i = 4; i < 32; i += 1)
        thresholds.push_back(i);

    for (auto threshold : thresholds) {
        shuffle_vec(arr.begin(), arr.end());
        KEY_COMPS = 0;
        SORTING::integrated_sort(arr, threshold);
        // sort(arr.begin(), arr.end());
        res.push_back(KEY_COMPS);
        // break;
    }
    std::ofstream myfile;
    std::string file_name = "optimal_S_1e" + std::to_string(size_10_log);
    myfile.open("../data/" + file_name + ".csv");

    myfile << "time,S\n";
    for (int i = 0; i < res.size(); ++i) {
        // average time of sorting (total_sorting_time / size)
        myfile << res[i] << "," << thresholds[i] << "\n";
    }
    myfile.flush();
    std::cout << "Generated file " << file_name << ".csv" << std::endl;
    myfile.close();
}

int main() {
    /*
    auto start = std::chrono::system_clock::now();
    plot_key_comp(8); // about 7 minutes
    auto t1 = std::chrono::system_clock::now();
    plot_optimal_S_comp(4); // 1 seconds
    auto t2 = std::chrono::system_clock::now();
    plot_optimal_S_comp(5);
    auto t3 = std::chrono::system_clock::now();
    plot_optimal_S_comp(6);
    auto t4 = std::chrono::system_clock::now();
    plot_optimal_S_comp(7);
    auto t5 = std::chrono::system_clock::now();
    auto d1 =
        double(std::chrono::duration_cast<std::chrono::microseconds>(t1 - start)
                   .count()) *
        std::chrono::microseconds::period::num /
        std::chrono::microseconds::period::den;
    auto d2 =
        double(std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1)
                   .count()) *
        std::chrono::microseconds::period::num /
        std::chrono::microseconds::period::den;
    auto d3 =
        double(std::chrono::duration_cast<std::chrono::microseconds>(t3 - t2)
                   .count()) *
        std::chrono::microseconds::period::num /
        std::chrono::microseconds::period::den;
    auto d4 =
        double(std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3)
                   .count()) *
        std::chrono::microseconds::period::num /
        std::chrono::microseconds::period::den;
    auto d5 =
        double(std::chrono::duration_cast<std::chrono::microseconds>(t5 - t4)
                   .count()) *
        std::chrono::microseconds::period::num /
        std::chrono::microseconds::period::den;
    std::cout << d1 << " " << d2 << " " << d3 << " " << d4 << " " << d5 << "\n";
    // 38.1401 0.086449 0 12.6004 120
    
    // choose 16 as optimal threshold, plot key comparisons w.r.t. size
    plot_key_comp(16);
    // threshold 1 as merge sort, plot key comparisons w.r.t. size
    plot_key_comp(1);
    // plot execution time w.r.t. size for merge sort
    plot_S_val(1);
    // plot execution time w.r.t. size for integrated sort
    plot_S_val(16);
*/
    // generate array of size 10 million
    std::vector<int> arr = create_vec(100000000);
    
    KEY_COMPS = 0;
    shuffle_vec(arr.begin(), arr.end());
    auto start = std::chrono::high_resolution_clock::now();
    SORTING::integrated_sort(arr, 1);
    auto t1 = std::chrono::high_resolution_clock::now();
    int key_comps1 = KEY_COMPS;
    
    shuffle_vec(arr.begin(), arr.end());
    KEY_COMPS = 0;
    auto t2 = std::chrono::high_resolution_clock::now();
    SORTING::integrated_sort(arr, 16);
    auto t3 = std::chrono::high_resolution_clock::now();
    int key_comps2 = KEY_COMPS;

    auto d1 =
        double(std::chrono::duration_cast<std::chrono::microseconds>(t1 - start)
                   .count()) *
        std::chrono::microseconds::period::num /
        std::chrono::microseconds::period::den;
    auto d2 =
        double(std::chrono::duration_cast<std::chrono::microseconds>(t3 - t2)
                   .count()) *
        std::chrono::microseconds::period::num /
        std::chrono::microseconds::period::den;
    std::cout << "Merge sort: \n" << "Time: " << d1 << " seconds" << 
        "\tKey comparisions: " << key_comps1 << std::endl;
    std::cout << "Integrated sort:\n" << "Time: " << d2 << " seconds" << 
        "\tKey comparisions: " << key_comps2 << std::endl;
    
    return 0;
}
