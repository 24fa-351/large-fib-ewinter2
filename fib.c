#include <stdio.h>
#include <stdlib.h>

unsigned long long int terms[1000];

unsigned long long int fib_r(unsigned long long int n) {
   if (n == 1) 
      return 1;
   else if (n <= 0)
      return 0;
    
   return fib_r(n - 1) + fib_r(n - 2);
}

unsigned long long int fib_i(int n) {
   if (n <= 1) 
      return 1;
   else if (n <= 0)
      return 0;

   unsigned long long int a = 0;
   unsigned long long int b = 1;
   unsigned long long int fib;

   for (int i = 2; i <= n; i++) {
      fib = a + b;
      a = b;
      b = fib;
   }
   return b;
}

int main(int argc, char *argv[]) {

   if (argc != 3) {
      printf("Invalid Input\n");
      return 0;
   }

   int num = atoi(argv[1]) - 1;
   
   unsigned long long int result;

   if (argv[2][0] == 'r') {
      result = fib_r(num);
   }
   else if (argv[2][0] == 'i') {
      result = fib_i(num);
   }
   else {
    printf("Invalid method.\n");
    return 0;
   }

   printf("%llu", result);

   return 0;
}
