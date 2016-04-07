/*

 * C program to read N names, store them in the form of an array

 * and sort them in alphabetical order. Output the given names and

 * the sorted names in two columns side by side.

 */

#include <stdio.h>
#include <string.h>


int main() {

    char name[30][100], tname[30][100], temp[100];

    int i, j, n;

    printf("Enter the value of n \n");
    scanf("%d", &n);


    printf("Enter %d names \n", n);

    for (i = 0; i < n; i++) {
        fgets (name[i], 100, stdin);
        strcpy(tname[i], name[i]);
    }


    for (i = 0; i < n - 1 ; i++) {

        for (j = i + 1; j < n; j++) {

            if (strcmp(name[i], name[j]) > 0) {

                strcpy(temp, name[i]);

                strcpy(name[i], name[j]);

                strcpy(name[j], temp);

            }

        }

    }

    printf("\n----------------------------------------\n");

    printf("Input Names\tSorted names\n");

    printf("----------------------------------------\n");

    for (i = 0; i < n; i++)

    {

        printf("%s\t\t%s", tname[i], name[i]);

    }

    printf("------------------------------------------\n");


    return 0;
}