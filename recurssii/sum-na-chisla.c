#include <stdio.h>
int add(int n);

int main()
{
    int n = 5;
    printf("Sum = %d\n",add(n));
    return 0;
}

int add(int n) {
    if(n!=0)
     return n+add(n-1);  /* recursive call */
}


// int add_without_recursion(int n) {
//     int sum = 0;
//     while(n--) {
//       sum = sum + n;
//     }
//     return sum;
// }
