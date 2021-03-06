#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conio.h"

#pragma GCC diagnostic ignored "-Wdeprecated-declarations".


#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_OUT 61 // =
#define KEY_ESC 27
#define KEY_ENTER 10


typedef struct
{
    int num;
    char name[50];
    int marks[20];
    float avr;
} student;

void dummy_slagane(student *students, int *broi);
void slagane(student *students, int *broi_uchenici);
void pisach(student *students, int broi_uchenici);
void chetene(student *students, int *broi_uchenici);
void print(student *students, int broi);
int poemane_student(student *s);
void dobavqne(student *students, int *broi_uchenici);
void avr(student *students, int broi);
void sort(student *students, int broi_uchenici);
void redaktirane(student *students, int broi_uchenici);
void myfile();
void print_menu(int num);
void print_selector(int option, int num);
int get_choice();
void triene(student *students, int *broi_uchenici);

const char *DEFAULT_FILE_NAME = "file.txt";
char filename[50];


int main()
{
    student students[40];
    int broi_uchenici = 0;

    int choice = 1;

    strcpy(filename, DEFAULT_FILE_NAME);

    do
    {
        choice = get_choice();
        switch (choice)
        {
        case 1:
            slagane(students, &broi_uchenici);
            sort(students,broi_uchenici);
            avr(students, broi_uchenici);
            pisach(students, broi_uchenici);
            break;
        case 2:
            chetene(students, &broi_uchenici);
            print(students, broi_uchenici);
            break;
        case 3:
            dobavqne(students, &broi_uchenici);
            sort(students,broi_uchenici);
            avr(students, broi_uchenici);
            pisach(students, broi_uchenici);
            break;
        case 4:
            redaktirane(students, broi_uchenici);
            sort(students,broi_uchenici);
            avr(students, broi_uchenici);
            pisach(students, broi_uchenici);
            break;
        case 5:
            myfile();
            break;
        case 6:
            triene(students, &broi_uchenici);
            sort(students,broi_uchenici);
            avr(students, broi_uchenici);
            pisach(students, broi_uchenici);
            break;
        case 7:
            printf("goodbye");
            exit (1);
            break;
        default:
            printf("Wrong choice.Enter Again");
            break;
        }
        getchar();

    }
    while(choice !=7);


    return 0;
}

void print_menu(int num) {
    // system ( "cls" );
    printf("\n\n### Menu ###\n");

    print_selector(1, num);
    printf("1. Syzdai\n");

    print_selector(2, num);
    printf("2. Cheti\n");

    print_selector(3, num);
    printf("3. Dobavi\n");

    print_selector(4, num);
    printf("4. Redaktirane\n");

    print_selector(5, num);
    printf("5. Smeni faila si\n");

    print_selector(6, num);
    printf("6. Iztrii zapis\n");

    print_selector(7, num);
    printf("7. Exit\n");

}
void print_selector(int option, int num) {
    if (option == num)
        printf("> ");
    else
        printf("  ");
}

int get_choice() {

  int current = 1;
  char ch, key, m;

  do {
    print_menu(current);
    ch = getch();

    if (ch == '\n')
      return current;

    if (ch == '\033') { // if the first value is an escape sequence
      getch(); // skip the [
      switch(getch()) { // the real value

        case 'A':
          // printf("for arrow up -> %d \n", key);
          current -= 1;// if current > 1;
          break;

        case 'B':
          // printf("for arrow down -> %d \n", key);
          current += 1;// if current < 9;
          break;
      }

      printf("\n\n");
    }
  } while(1);
}



void slagane(student *students, int *broi_uchenici)
{
    int x = 0;
    student s;

    while(1)
    {
        if(poemane_student(&students[x])==0)
            break;

        //printf("%s\n", students[x].name);

        x++;
    }


    *broi_uchenici = x;
}


void dummy_slagane(student *students, int *broi) {
    *broi = 2;
    const char *dummy_names[10] = {"pesho", "kiro"};

    int broi_predmeti = 3, i, x, br, ko=2;

    for(i=0; i < *broi; i++)
    {
        ko++;

        students[i].num=i+1;

        strcpy(students[i].name, dummy_names[i]);

        for(x = 0; x < broi_predmeti; x++) {
            students[i].marks[x] = ko+x;
        }
    }
}


int poemane_student(student *std)
{

    int broi_predmeti, i, x=0;

    printf("\n\n Input a number: ");
    scanf("%d", &std->num);

    if(std->num == 0)
        return 0;

    getchar();

    printf("\n Input name: ");
    // getchar();
    gets(std->name);


    for(i=0; i<20; i++) std->marks[i]=0;

    i=0;

    while(i<20)
    {

        printf("\n Input a mark: ");
        scanf("%d", &std->marks[i]);

        if(std->marks[i]==0)
            break;

        i++;
    }
    return 1;

}

void pisach(student *students, int broi)
{

    FILE *fptr;

    // printf("Pisach broi: %d\n", broi);
    fptr = fopen(filename,"wb");

    fwrite(students, sizeof(student) * broi, 1, fptr);

    fclose(fptr);
}

void avr(student *students, int broi)
{

    int i=0,k;
    students[i].avr=0;

    for ( i = 0; i < broi; i++)
    {

        k = 0;
        while(students[i].marks[k] != 0)
        {
            students[i].avr=students[i].avr+students[i].marks[k];
            k++;
        }
        students[i].avr=students[i].avr/k;
    }


}
void sort(student *students, int broi)
{
    int i, j = 0;
    student temp;

    for (i = 1; i < broi; i++)
    {
        for (j = 0; j < broi - i; j++)
        {
            if (students[j].num > students[j + 1].num)
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void chetene(student *students, int *broi)
{

    FILE *fptr;
    int i;
    student s;

    fptr = fopen(filename,"rb");

    if(fptr == NULL)
    {
        printf("not found");
        return;
    }

    i = 0;
    while(!feof(fptr))
    {

        if(fread(&s, sizeof(student), 1, fptr))
        {
            students[i] = s; // assign the student to the main variable
            i++;
        }
    }

    *broi = i;
    fclose(fptr);
}

void print(student *students, int broi)
{
    int k,i;

    printf("Print broi: %d\n", broi);
    for ( i = 0; i < broi; i++)
    {
        printf("\n%-3d %-30s", students[i].num, students[i].name);

        k = 0;
        while(students[i].marks[k] != 0)
        {
            printf("%-3d",students[i].marks[k]);
            k++;
        }
        printf("%-6.2f",students[i].avr);
    }
}

void dobavqne(student *students, int *broi_uchenici)
{

    int x = *broi_uchenici;
    student s;

    while(1)
    {
        if(poemane_student(&students[x])==0)
            break;

        //printf("%s\n", students[x].name);

        x++;
    }


    *broi_uchenici = x;

}

void redaktirane(student *students, int broi)
{

    int k,i,num,ok=0;

    print(students, broi);


    printf("\n Enter number of student: ");
    scanf("%d",&num);

    for(i=0; i < broi; i++)
    {

        if(students[i].num==num)
        {
            ok=1;
            break;

        }
    }
    if (ok==0)
    {

        printf("No such number!");
        return;
    }

    poemane_student(&students[i]);


}

void myfile()
{

    char  newfilename[101];


    printf ("Now the name of file to be changed is:\n %s",filename);

    printf("\n You have choosen to rename %s.\nPlease type the new name of the file:\n", filename);
    gets(newfilename);

    if(rename(filename, newfilename) == 0)
    {
        printf("\n %s has been renamed %s.\n", filename, newfilename);

        strcpy(filename, newfilename);

    }
    else
    {
        fprintf(stderr, "Error renaming %s.\n", filename);
    }

}


void triene(student *students, int *broi) {
    print(students, *broi);

    int k, i, num, ok=0;
    bool found = false;

    printf("\n Enter number of student: ");
    scanf("%d",&num);

    for (i = 0; i < *broi; i++) {
        if(students[i].num == num) {
            found = true;
            break;
        }
    }

    if(!found) return;
    *broi = *broi-1;

    for (k = i; k < *broi; k++) {
        students[k] = students[k+1];
    }


    print(students, *broi);

}
