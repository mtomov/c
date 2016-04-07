#include <stdio.h>
#include <string.h>

int main() {
  const char *T;
  int i, j;
  const char *array[5]={"SUNIL","ANIL","DILIP","JAY","BHARAT"};

  for( i=0; i<5; i++) {
    printf("%s \t",array[i]);
  }
  printf("\n");


  for( i=0; i<4; i++) {
    for( j=0; j<4-i; j++) {
      if(strcmp(array[j], array[j+1]) > 0) {
        T=array[j];
        array[j]=array[j+1];
        array[j+1]=T;
      }
    }
  }



  for(i=0;i<5;i++) {
    printf("%s \t",array[i]);
  }

  return 0;
}