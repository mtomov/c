#include <stdio.h>
#include <stdlib.h>

void zad1(void);
void zad2(void);
void zad3(void);
void zad4(void);
void zad5(void);
void zad6(void);
void zad7(void);
void zad8(void);
void zad9(void);
void zad10(void);
void zad11(void);
void zad12(void);



int main()
{

  int zadachka=0,yesorno=0,n;

  do {

    printf(">Programa 1 is Sum from 1 to n \n");
    printf(" Programa 2 is Sum na n proizvolni  \n");
    printf(" Programa 3 is Sreden uspeh \n");
    printf(" Programa 4 is ax+b=0 \n");
    printf(" Programa 5 is Deliteli na n \n");
    printf(" Programa 6 is Prosto li e \n");
    printf(" Programa 7 is Prostite deliteli na n i tehniq broi \n");
    printf(" Programa 8 is Broi na cifri v chislo \n");
    printf(" Programa 9 is Sumata na cifrite v n \n");
    printf(" Programa 10 is Kolko pyti a se sreshta v n \n");
    printf(" Programa 11 is Da se izpishe n s cifrite na m naobratno naredeni \n");


    printf("Choose Programa: \n");
    scanf("%d",&zadachka);


    switch(zadachka){

      case 1: zad1();break;
      case 2: printf("Programa 2 \n");zad2();break;
      case 3: printf("Programa 3 \n"); zad3();break;
      case 4: printf("Programa 4 \n"); zad4();break;
      case 5: printf("Programa 5 \n");zad5();break;
      case 6: printf("Programa 6 \n");zad6();break;
      case 7: printf("Programa 7 \n");zad7();break;
      case 8: printf("Programa 8 \n");zad8();break;
      case 9: printf("Programa 9 \n");zad9();break;
      case 10: printf("Programa 10 \n");zad10();break;
      case 11: printf("Programa 11 \n");zad11();break;

      default:

      printf("There is not a zadachka with that number!");

    }

    printf(" \n Do you want to carry on? yes-1 no-just write ");
    scanf("%d",&yesorno);

    // system("cls");
    system("clear");


  } while(yesorno == 1);


  return 0;
}


void zad1(void) {
  int n,sum=0,i=1;
  printf("Programa 1 \n");

  printf("Enter:");
  scanf ("%d",&n);
  while (i<=n){

    sum=sum+i;
    i++;
  }

  printf("Sum = %d", sum);
}

void zad2(void) {
  int b=0,x,y,br=0,reverse=0,s=0,a=0,k=0,n=0,sum=0,i=0,zadachka=0,yesorno=0;
  printf("br");
  scanf("%d" , &n);

  while ( i < n ) {
    printf("write");
    scanf("%d",&a);
    s=s+a;
    i++;
  }

  printf("sum %d",s);
}

void zad3(void) {
  int b=0,x,y,br=0,reverse=0,s=0,a=0,k=0,n=0,sum=0,i=0,zadachka=0,yesorno=0;

  do {
    printf("kolko");
    scanf("%d",&n);
  } while(n<0);

  while(i<n){
    printf("ocenki");
    scanf("%d",&a);
    i++;
    s=s+a;
  }


  if( i<=n ){
    k=s%n;
    s=s/n;
    printf("%d(%d)",s,k);
  }

  n = 0;
  i  = 0;
  a  = 0;
  s  = 0;
  k=0;
  do {

    printf("kolko");
    scanf("%d",&n);
  } while(n<0);

  while(i<n){
    printf("ocenki");
    scanf("%d",&a);
    i++;
    s=s+a;
  }


  if( i<=n ){

    k=s%n;
    s=s/n;
    printf("%d(%d)",s,k);
  }

  n = 0;
  i  = 0;
  a  = 0;
  s  = 0;
  k=0;
  do{

    printf("kolko");
    scanf("%d",&n);
  }
  while(n<0);

  while( i < n) {
    printf("ocenki");
    scanf("%d",&a);
    i++;
    s=s+a;
  }


  if( i<=n ){

    k=s%n;
    s=s/n;
    printf("%d(%d)",s,k);
  }

  n = 0;
  i  = 0;
  a  = 0;
  s  = 0;
  k=0;

  do {
    printf("kolko");
    scanf("%d",&n);
  } while(n<0);

  while(i<n){
    printf("ocenki");
    scanf("%d",&a);
    i++;
    s=s+a;
  }

  if( i<=n ){
    k=s%n;
    s=s/n;
    printf("%d(%d)",s,k);
  }
}
void zad4(void) {
  int b=0,x,y,br=0,reverse=0,s=0,a=0,k=0,n=0,sum=0,i=0,zadachka=0,yesorno=0;
  printf("Think of a ax+b=0 type of a equation!");

  printf("Write a :");
  scanf("%d",&a);

  printf("Write b :");
  scanf("%d",&b);

  if(a==0){

    if(b==0) {

      printf("Every x");
    } else{
      printf("No way");
    }

  } else {
    x = -b / a;
    y = b % a;

    printf("Your x : %d ostatyk ( %d)",x,y);
  }
}

void zad5(void) {
  int b=0,x,y,br=0,reverse=0,s=0,a=0,k=0,n=0,sum=0,i=0,zadachka=0,yesorno=0;
  printf("Enter n:");
  scanf("%d",&n);
  printf("dividots of %d are:",n);

  for(i=1;i<=n;i++) {
    if(n%i==0){
      b++;
    }
  }

  printf("%d",b);
}

void zad6(void) {
  int b=0,x,y,br=0,reverse=0,s=0,a=0,k=0,n=0,sum=0,i=0,zadachka=0,yesorno=0;

  i=2;
  scanf("%d",&n);
  while(n%i!=0){
    i++;
  }
  if(i==n)
    printf("prosto");
  else{
    printf("neprosto");
  }
}

void zad7(void) {
  int b=0,x,y,br=0,reverse=0,s=0,a=0,k=0,n=0,sum=0,i=0,zadachka=0,yesorno=0;
  printf("Write your magic numb3r:");
  scanf("%d",&n);
  i=2;

  while(i<=n){
    if(n%i==0){
      k=2;

      while(i%k!=0){
        k++;
      }
      if(i==k){
        printf(" %d ;",i);
        br++;
      }
    }

    i++;
  }

  printf("\n numb %d ",br);
}

void zad8(void) {
  int b=0,x,y,br=0,reverse=0,s=0,a=0,k=0,n=0,sum=0,i=0,zadachka=0,yesorno=0;

  printf("Enter a number: ");
  scanf("%d",&n);

  while(n>0){
    n=n/10;
    i++;
  }
  printf("Total digits is: %d",i);

  n = 0;
  i = 0;
}

void zad9(void) {
  int b=0,x,y,br=0,reverse=0,s=0,a=0,k=0,n=0,sum=0,i=0,zadachka=0,yesorno=0;

  printf("Enter a number: ");
  scanf("%d",&n);

  while(n>0) {
    k=n%10;
    n=n/10;

    i++;
    sum=sum+k;
  }

  printf("Total sum of digits is:  %d",sum);
}

void zad10(void) {
  int b=0,x,y,br=0,reverse=0,s=0,a=0,k=0,n=0,sum=0,i=0,zadachka=0,yesorno=0;

  printf("Input n:");
  scanf("%d",&n);
  printf("Input a:");
  scanf("%d",&a);

  while(n!=0) {

    if(n%10==a){
      sum++;
    }
    n=n/10;
  }

  printf("Chisloto %d se sreshta %d pyti ",a,sum);
}

void zad11(void) {
  int b=0,x,y,br=0,reverse=0,s=0,a=0,k=0,n=0,sum=0,i=0,zadachka=0,yesorno=0;

  printf("Enter:\n");
  scanf("%d",&n);

  while(n!=0){
    reverse=reverse*10;
    reverse=reverse+n%10;
    n=n/10;
  }

  printf("Reversed:%d\n",reverse);
}