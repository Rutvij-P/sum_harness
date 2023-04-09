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
    printf(" inside sum_vector problem_setup, N=%lld \n", N);
    for (int i = 0; i < N; i++) {
        A[i] = i;
    }
}

int64_t
sum(int64_t N, uint64_t A[])
{
    printf(" inside sum_vector perform_sum, N=%lld \n", N);

    // Start timing
    auto start_time = std::chrono::high_resolution_clock::now();

    uint64_t sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
    }

    // End timing and calculate elapsed time
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;

    // Print elapsed time
    std::cout << "Elapsed time: " << elapsed_time.count() << " seconds" << std::endl;

    return sum;
}
