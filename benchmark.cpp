//
// (C) 2022, E. Wes Bethel
// benchmark-* harness for running different versions of the sum study
//    over different problem sizes
//
// usage: no command line arguments
// set problem sizes, block sizes in the code below

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

#define MAX_PROBLEM_SIZE 1 << 28  //  256M
   std::vector<int64_t> problem_sizes{ MAX_PROBLEM_SIZE >> 5, MAX_PROBLEM_SIZE >> 4, MAX_PROBLEM_SIZE >> 3, MAX_PROBLEM_SIZE >> 2, MAX_PROBLEM_SIZE >> 1, MAX_PROBLEM_SIZE};
   
   std::vector<uint64_t> A(MAX_PROBLEM_SIZE);

   int64_t t;
   int n_problems = problem_sizes.size();

   /* For each test size */
   for (int64_t n : problem_sizes) 
   {
      printf("Working on problem size N=%d \n", n);

      // invoke user code to set up the problem
      // measure time for direct sum method
        setup(n, &A[0]);
        auto start_time = high_resolution_clock::now();
        t = sum(n, &A[0]);
        auto end_time = high_resolution_clock::now();
        auto time_diff = duration_cast<nanoseconds>(end_time - start_time);
        double direct_sum_elapsed_time = time_diff.count() / 1000000000.0;

        printf(" Direct sum result = %lld \n",t);
        printf(" Direct sum elapsed time = %f seconds \n", direct_sum_elapsed_time);
        
        // measure time for vector sum method
        setup(n, &A[0]);
        start_time = high_resolution_clock::now();
        t = sum(n, &A[0]);
        end_time = high_resolution_clock::now();
        time_diff = duration_cast<nanoseconds>(end_time - start_time);
        double vector_sum_elapsed_time = time_diff.count() / 1000000000.0;

        printf(" Vector sum result = %lld \n",t);
        printf(" Vector sum elapsed time = %f seconds \n", vector_sum_elapsed_time);
      
         // measure time for indirect sum method
         setup(n, &A[0]);
         start_time = high_resolution_clock::now();
         t = sum(n, &A[0]);
         end_time = high_resolution_clock::now();
         time_diff = duration_cast<nanoseconds>(end_time - start_time);
         double indirect_sum_elapsed_time = time_diff.count() / 1000000000.0;

         printf(" Indirect sum result = %lld \n",t);
         printf(" Indirect sum elapsed time = %f seconds \n", indirect_sum_elapsed_time);

         double direct_sum_mflops = 2 * n / (direct_sum_elapsed_time * 1e6);
         double vector_sum_mflops = 2 * n / (vector_sum_elapsed_time * 1e6);
         double indirect_sum_mflops = 2 * n / (indirect_sum_elapsed_time * 1e6);

         double mem_bandwidth = (8 * n) / (direct_sum_elapsed_time * 1e9);
         double mem_latency = indirect_sum_elapsed_time / (double)n;

         printf(" Direct sum MFLOP/s = %f\n", direct_sum_mflops);
         printf(" Vector sum MFLOP/s = %f\n", vector_sum_mflops);
         printf(" Indirect sum MFLOP/s = %f\n", indirect_sum_mflops);
         printf(" Memory bandwidth = %f GB/s\n", mem_bandwidth);
         printf(" Memory latency = %f ns\n", mem_latency * 1e9);
   }

   return 0;
}
                  
//EOF