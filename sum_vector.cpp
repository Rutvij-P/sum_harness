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
    printf(" inside sum_vector problem_setup, N=%lld \n", (long long int) N);
    for (int i = 0; i < N; i++) {
        A[i] = i;
    }
}

int64_t sum(int64_t N, uint64_t A[]) {
    std::vector<uint64_t> vec_A(N);
    std::memcpy(vec_A.data(), A, N * sizeof(uint64_t));

    // Start timing
    auto start_time = std::chrono::high_resolution_clock::now();

    uint64_t sum = std::accumulate(vec_A.begin(), vec_A.end(), 0UL);

    // End timing and calculate elapsed time
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;

    // Print elapsed time
    std::cout << "Elapsed time: " << elapsed_time.count() << " seconds" << std::endl;

    return sum;
}
