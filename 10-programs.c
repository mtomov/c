#include <stdio.h>
#include <stdlib.h>
#include "conio.h"


#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_OUT 61 // =
#define KEY_ESC 27
#define KEY_ENTER 10

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

void print_menu(int num) {
  int current = 0;

  char menu_options[][255] = {
    "Sum from 1 to n",
    "Sum na n proizvolni ",
    "Sreden uspeh",
    "ax+b=0",
    "Deliteli na n",
    "Prosto li e",
    "Prostite deliteli na n i tehniq broi",
    "Broi na cifri v chislo",
    "Sumata na cifrite v n",
    "Kolko pyti a se sreshta v n",
    "Da se izpishe n s cifrite na m naobratno naredeni"
  };

  // system("cls");
  system("clear");

  for(int i = 0; i < 11; i++) {
    current = i + 1;
    if (current == num)
      printf("%d >   %s \n", current, menu_options[i]);
    else
      printf("%d:    %s \n", current, menu_options[i]);
  }

  printf("\n");
}

int menu() {

  int current = 1;
  char ch, key, m;

  do {
    ch = getch();

    // Go to the chose option
    if (ch == KEY_ENTER) {
      printf("enter\n");
      return current;
    }

    printf("Key# %d\n", ch);
    if (ch == KEY_ESC) { // if the first value is an escape sequence
      m = getch(); // skip the [
      printf("Middle Key# %c\n", m);

      key = getch();
      printf("Real Key# %d\n", key);

      switch(key) { // the real value

        case KEY_UP:
          printf("for arrow up -> %d \n", key);
          current -= 1;// if current > 1;
          break;

        case KEY_DOWN:
          printf("for arrow down -> %d \n", key);
          current += 1;// if current < 9;
          break;
      }

      // print_menu(current);
      printf("\n\n");
    }
  } while(1);
}


int main()
{

  int zadachka = 0, yesorno = 0, n;

  do {
    zadachka = menu();
    if (zadachka == 0) break;

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


  } while(1);


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

  printf("Sum = %d\n\n", sum);
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