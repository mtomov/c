/* Fibonacci Series c language */
#include <stdio.h>

int main()
{
  int n = 3, first = 0, second = 1, next, c;


  for ( c = 0 ; c < n ; c++ )
  {
    next = first + second;
    first = second;
    second = next;
  }

  printf("Fib(5): %d\n", first);

  return 0;
}

