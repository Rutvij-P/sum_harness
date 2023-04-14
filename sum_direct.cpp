#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <string.h>

void setup(int64_t N, uint64_t A[])
{
   printf(" inside direct_sum problem_setup, N=%ld \n", N);

   // generate random numbers for the array A
   std::mt19937_64 rng(std::random_device{}());
   std::uniform_int_distribution<uint64_t> dist(1, 1000);
   for (int64_t i = 0; i < N; i++) {
      A[i] = dist(rng);
   }
}

int64_t sum(int64_t N, uint64_t A[])
{
   printf(" inside direct_sum perform_sum, N=%ld \n", N);

   int64_t sum = 0;

   // measure time consumed by the sum operation
   auto start_time = std::chrono::high_resolution_clock::now();

   // compute sum using a loop
   for (int64_t i = 0; i < N; i++) {
      sum += A[i];
   }

   auto end_time = std::chrono::high_resolution_clock::now();
   auto elapsed_time =
       std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();

   printf(" Time elapsed for sum operation: %ld ns\n", elapsed_time);

   return sum;
}

double run_benchmark(int64_t N, uint64_t A[]) {
   double sum_time = 0;

   // perform sum operation multiple times
   for (int i = 0; i < 100000; i++) {
      sum_time += sum(N, A);
   }

   return sum_time;
}
