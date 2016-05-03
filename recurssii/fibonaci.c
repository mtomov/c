#include<stdio.h>

int Fibonacci(int);

main()
{
   int n, i = 0, c = 5;

   // scanf("%d",&n);

   printf("Fib(5): %d\n", Fibonacci(10));

   return 0;
}

int Fibonacci(int n)
{
   if ( n == 0 )
      return 0;
   else if ( n == 1 )
      return 1;
   else
      return ( Fibonacci(n-1) + Fibonacci(n-2) );
}

