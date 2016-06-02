#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int num;
    char name[50];
    int marks[20];
    float avr;
} student;

int dummy_chetene_student(student *students);
void slagane(student *students, int *broi_uchenici);
void pisach(student *students, int broi_uchenici);
void chetene(student *students, int *broi_uchenici);
void print(student *students, int broi);
int chetene_student(student *s);
void dobavqne(void);


int main() {
    student students[40];
    int broi_uchenici = 0;

    int choice;

    do
    {
        printf("\n\n### Menu ###\n");
        printf("1. Syzdai\n");
        printf("2. Cheti\n");
        printf("3. Dobavi\n");
        printf("4. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            slagane(students, &broi_uchenici);
            pisach(students, broi_uchenici);
            break;
        case 2:
            chetene(students, &broi_uchenici);
            print(students, broi_uchenici);
            break;
        case 3:
            //dobavqne();
            break;
        case 4:
            printf("goodbye");
            exit (1);
            break;
        default:
            printf("Wrong choice.Enter Again");
            break;
        }
    }
    while(choice !=4);


    return 0;
}


void slagane(student *students, int *broi_uchenici) {
    int x = 0;
    student s;

    while(x < 2)
    {
        if(chetene_student(&students[x]))
            break;

        printf("%s\n", students[x].name);

        x++;
    }


    *broi_uchenici = x;
}



int dummy_chetene_student(student *std) {
    const char *dummy_name = "pesho";
    student s;

    int broi_predmeti = 3, i, x, br;

    std->num = 5;

    strcpy(std->name, dummy_name);

    for(x = 0; x < broi_predmeti; x++) {
        std->marks[x] = x;
    }

    return 0;
}


int chetene_student(student *std) {

    int broi_predmeti, i, x=0;

    printf("\n\n Input a number: ");
    scanf("%d", &std->num);

    if(std->num == 0)
        return 0;

    getchar();

    printf("\n Input name: ");
    // getchar();
    gets(std->name);

    //std->avr=0;
    for(i=0; i<20; i++) std->marks[i]=0;

    i=0;

    while(i<20)
    {

        printf("\n Input a mark: ");
        scanf("%d", &std->marks[i]);

        if(std->marks[i]==0)
            break;
        // std->avr=std->avr+std->marks[i];
        i++;
    }

    // if(i>0) std->avr=std->avr/i;
}

void pisach(student *students, int broi) {
    FILE *fptr;

    // printf("Pisach broi: %d\n", broi);
    fptr = fopen("file.txt","wb");
    fwrite(students, sizeof(student) * broi, 1, fptr);

    fclose(fptr);
}



void chetene(student *students, int *broi) {

    FILE *fptr;
    int i;
    student s;

    fptr = fopen("file.txt","rb");

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


void print(student *students, int broi) {
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
        //printf("%-6.2f",students[i].avr);
    }
}


/*
void dobavqne(void){

     FILE *fptr;
    student s[40];
    student pom;
    int  broi_uchenici, broi_predmeti,i, x, br;

 fptr=fopen("file.txt","wb");

   if(fptr==NULL){
       printf("Error!");
       exit(1);
   }

  do
    {
        printf(" Input number of students:");
        scanf("%d",&broi_uchenici);
    }
    while(broi_uchenici>40||broi_uchenici<1);
    do
    {
        printf("\n Input number of subjects: ");
        scanf("%d",&broi_predmeti);
    }
    while(broi_predmeti>20 || broi_predmeti<1);
    for(i=0; i<broi_uchenici; i++)
    {
        printf("\n Input number of the student: ");
        scanf("%d",&s[i].num);
        printf("\n Input name of the student: ");
        getchar();
        gets(s[i].name);
        for(x=0; x<broi_predmeti; x++){
            printf(" Enter mark: ");
            scanf("%d", &s[i].marks[x]);
        }
    }
    br=0;

    for(i=0; i<broi_uchenici; i++)
    {
        s[i].avr=0;
        for(x=0; x<broi_predmeti; x++){
            s[i].avr=s[i].avr+s[i].marks[x];
            s[i].avr=s[i].avr/broi_predmeti;
           // printf("\n Avr: %s ",s[i].avr);
        }
    }
    do
    {
        i=0;
        do
        {
            if(s[i+1].num<s[i].num)
            {
                pom=s[i];
                s[i]=s[i+1];
                s[i+1]=pom;
            }
            i++;
        }
        while(i!=broi_uchenici-1);
        br++;
    }while(br!=broi_uchenici-1);

 fprintf(fptr,"\nName: %s",s);

   fclose(fptr);

   // fwrite(s,sizeof(s),1,fptr);

 printf("\n Ocenka ");

}


void sort() {

    br=0;

    for(i=0; i<broi_uchenici; i++)
    {
        s[i].avr=0;
        for(x=0; x<broi_predmeti; x++){
            s[i].avr=s[i].avr+s[i].marks[x];
            s[i].avr=s[i].avr/broi_predmeti;
           // printf("\n Avr: %s ",s[i].avr);
        }
    }
    do
    {
        i=0;
        do
        {
            if(s[i+1].num<s[i].num)
            {
                pom=s[i];
                s[i]=s[i+1];
                s[i+1]=pom;
            }
            i++;
        }
        while(i!=broi_uchenici-1);
        br++;
    }while(br!=broi_uchenici-1);

}

*/


