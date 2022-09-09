# IntegratedSort
SC2001 Project 1 - Integration of Merge Sort and Insertion Sort

In Mergesort, when the sizes of subarrays are small, the overhead of many recursive
calls makes the algorithm inefficient. Therefore, in real use, we often combine
Mergesort with Insertion Sort to come up with a hybrid sorting algorithm for better
efficiency. The idea is to set a small integer S as a threshold for the size of subarrays.
Once the size of a subarray in a recursive call of Mergesort is less than or equal to S,
the algorithm will switch to Insertion Sort, which is efficient for small-sized input.

## Usage
Build the project: 
``` bash
$ mkdir build && cd build
$ cmake ..
$ make all
```
Test the correctness of sorting algorithms
``` bash
# quick check
$ make test
# check each algorithms' correctness
$ ./test/SortingTest
``` 
Run the project
``` bash
$ ./IntegratedSort
```