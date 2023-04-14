#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <string.h>

using namespace std::chrono;

extern void setup(int64_t N, uint64_t A[]);
extern int64_t sum(int64_t N, uint64_t A[]);

/* The benchmarking program */
int main(int argc, char** argv) 
{
   std::cout << std::fixed << std::setprecision(2);

   const int64_t MIN_PROBLEM_SIZE = 1 << 20; // 1M
   const int64_t MAX_PROBLEM_SIZE = 1 << 28; // 256M
   std::vector<int64_t> problem_sizes{ MIN_PROBLEM_SIZE, MAX_PROBLEM_SIZE };
   
   std::vector<uint64_t> A(MAX_PROBLEM_SIZE);

   int64_t t;
   int n_problems = problem_sizes.size();

   int64_t total_num_calls = 0;
   double total_elapsed_time = 0.0;

   /* For each test size */
   for (int64_t n : problem_sizes) 
   {
      int64_t num_calls = 0;
      double elapsed_time = 0.0;

      printf("Working on problem size N=%lld \n", n);

      // invoke user code to set up the problem
      setup(n, &A[0]);

      // measure time for sum method until at least 30 seconds have elapsed
      auto start_time = high_resolution_clock::now();
      while (elapsed_time < 30.0) {
        t = sum(n, &A[0]);
        num_calls++;
        auto end_time = high_resolution_clock::now();
        auto time_diff = duration_cast<nanoseconds>(end_time - start_time);
        elapsed_time = time_diff.count() / 1000000000.0;
      }

      total_num_calls += num_calls;
      total_elapsed_time += elapsed_time;

      printf(" Sum result = %lld \n",t);
      printf(" Number of calls to sum() function = %lld\n", num_calls);
      printf(" Elapsed time = %f seconds \n", elapsed_time);
   }

   printf("Total number of calls to sum() function = %lld\n", total_num_calls);
   printf("Total elapsed time = %f seconds\n", total_elapsed_time);
   printf("Number of times each problem size was executed: %d\n", 2 * n_problems);

   return 0;
}
