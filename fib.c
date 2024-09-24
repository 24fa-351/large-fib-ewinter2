#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

bool sumWouldOverflow(unsigned long long a, unsigned long long b) {
   return a > ULLONG_MAX - b;
}

unsigned long long int fib_r(int index) {
   if (index <= 1) {
      return index;
   }

   unsigned long long minus1result = fib_r(index - 1);
   unsigned long long minus2result = fib_r(index - 2);

   if (sumWouldOverflow(minus1result, minus2result)){
      fprintf(stderr, "Overflow at Index %d\n", index + 2);
      return ULLONG_MAX;
   }   
   return minus1result + minus2result;
}

unsigned long long int fib_i(int n) {
   if (n <= 1) {
      return n;
   }
   unsigned long long int a = 0;
   unsigned long long int b = 1;

   for (int i = 2; i <= n; i++) {
      if (sumWouldOverflow(a, b)){
         fprintf(stderr, "Overflow at Index %d\n", i + 2);
         return ULLONG_MAX;
      }
      unsigned long long int fib = a + b;
      a = b;
      b = fib;
   }
   return b;
}

int main(int argc, char *argv[]) {

   if (argc != 3 || argv[2][0] == 'r' && argv[2][0] == 'i') {
      printf("Invalid Input\n");
      return 0;
   }

   int num = atoi(argv[1]) - 1;
   
   unsigned long long int result = 0;

   if (argv[2][0] == 'r') {
      result = fib_r(num);
   }
   else {
      result = fib_i(num);
   }

   printf("%lld\n", result);

   return 0;
}
