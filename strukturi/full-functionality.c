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

void dummy_slagane(student *students, int *broi_uchenici);
void slagane(student *students, int *broi_uchenici);
void pisach(student *students, int broi_uchenici);
void chetene(student *students, int *broi_uchenici);
void print(student *students, int broi);
void dobavqne(void);


int main() {
    student students[40];
    int broi_uchenici = 0;

    int choice;

    do {
        printf("\n\n### Menu ###\n");
        printf("1. Syzdai\n");
        printf("2. Cheti\n");
        printf("3. Dobavi\n");
        printf("4. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            dummy_slagane(students, &broi_uchenici);
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

void dummy_slagane(student *students, int *broi) {
    *broi = 2;
    const char *dummy_names[10] = {"pesho", "kiro"};

    int broi_predmeti = 3, i, x, br, ko=2;

    for(i=0; i < *broi; i++)
    {
        ko++;

        students[i].num=i;

        strcpy(students[i].name, dummy_names[i]);

        for(x = 0; x < broi_predmeti; x++) {
            students[i].marks[x] = ko+x;
        }
    }
}



void slagane(student *students, int *broi_uchenici) {
    int broi_predmeti, i, x, br;

    do {
        printf(" Input number of students:");
        scanf("%d", broi_uchenici);
    } while(*broi_uchenici>40 || *broi_uchenici<1);

    do {
        printf("\n Input number of subjects: ");
        scanf("%d",&broi_predmeti);
    } while(broi_predmeti>20 || broi_predmeti<1);


    for(i = 0; i < *broi_uchenici; i++) {
        printf("\n Input number of the student: ");
        scanf("%d",&students[i].num);

        printf("\n Input name of the student: ");
        getchar();
        gets(students[i].name);

        for(x = 0; x < broi_predmeti; x++)
        {
            printf(" Enter mark: ");
            scanf("%d", &students[i].marks[x]);
        }
    }

}

void pisach(student *students, int broi) {
    FILE *fptr;

    // printf("Pisach broi: %d\n", broi);
    fptr = fopen("file.txt","wb");
    fwrite(students, sizeof(student) * broi, 1, fptr);

    fclose(fptr);
}



void chetene(student *students, int *broi){

    FILE *fptr;
    int i;
    student s;

    fptr = fopen("file.txt","rb");

    if(fptr == NULL) {
        printf("not found");
        return;
    }

    i = 0;
    while(!feof(fptr)) {

        if(fread(&s, sizeof(student), 1, fptr)) {
            students[i] = s; // assign the student to the main variable
            i++;
        }
    }

    *broi = i;
    fclose(fptr);
}


void print(student *students, int broi) {
    int k;

    printf("Print broi: %d\n", broi);
    for (int i = 0; i < broi; i++)
    {
        printf("\n%-3d %-30s", i+1, students[i].name);

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


