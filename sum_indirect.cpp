#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <string.h>

void 
setup(int64_t N, uint64_t A[])
{
   std::cout << "inside sum_indirect problem_setup, N=" << N << std::endl;
    srand48(0);
    for (int64_t i = 0; i < N; i++) {
        A[i] = lrand48() % N;
    }
}

int64_t
sum(int64_t N, uint64_t A[])
{
    std::cout << "inside sum_indirect perform_sum, N=" << N << std::endl;

    // Start timing
    auto start_time = std::chrono::high_resolution_clock::now();

    int64_t result = 0;
    for (int64_t i = 0; i < N; i++) {
        result += A[i];
    }

    // End timing and calculate elapsed time
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;

    // Print elapsed time
    std::cout << "Elapsed time: " << elapsed_time.count() << " seconds" << std::endl;

   return result;
}


