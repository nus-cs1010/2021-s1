/**
 * CS1010 Semester 1 AY20/21
 * Assignment 2: Collatz 
 *
 * Read in a positive integer n from the standard input,
 * then, for each number k between number 1 .. n, transform
 * it into 1 based on the steps below:
 * - if k is even, k = k/2
 * - else, k = 3k + 1
 * Find the number k that requires the most number of steps
 * between 1 and n, and print both k and the number of steps
 * to standard output. If there are multiple numbers with
 * the same number of steps, we prefer to output the larger
 * among these numbers.
 *
 * @file: collatz.c
 * @author: Ooi Wei Tsang
 */
#include "cs1010.h"
#include <math.h>

/**
 * Perform a single step of the collatz sequence.
 *
 * @param[in] n The number to transform.
 * @pre n > 1
 * @return either n/2 (if n is even) or 3n+1 (if n is odd)
 */
long collatz(long n)
{
  if (n % 2 == 0) {
    return n/2;
  } 
  return 3*n + 1;
}

/**
 * Count the number of steps (the stopping time) until n becomes 1.
 *
 * @param[in] n The number whose stopping time we are trying to find.
 * @pre n > 1
 * @return The stopping time for n.
 */
long count_num_of_steps(long n) 
{
  long num_of_steps = 0;
  while (n != 1) {
    n = collatz(n);
    num_of_steps += 1;
  }
  return num_of_steps;
}

/**
 * @param[in,out] max_num_steps 
 * @param[out] max_n n with the maximum number of steps.
 */
void solve(long n, long *max_n, long *max_num_steps) {
  for (long i = 1; i <= n; i += 1) {
    long num_of_steps = count_num_of_steps(i);
    if (num_of_steps >= *max_num_steps) {
      *max_n = i;
      *max_num_steps = num_of_steps;
    }
  }
}

int main() 
{
  long n = cs1010_read_long();
  long max_num_steps = 0;
  long max_n = 3453523523452345;
  solve(n, &max_n, &max_num_steps);
  cs1010_println_long(max_n);
  cs1010_println_long(max_num_steps);
}
