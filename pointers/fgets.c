#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct phonebook_entry_t {
  struct person_t *person;
  int phone;
};

struct person_t{
  char name[20];
  int age;
  int post;
};

void print_person(struct phonebook_entry_t*);

int main() {

  int count = 0;
  struct phonebook_entry_t *entry;
  struct phonebook_entry_t *person;
  struct phonebook_entry_t *phonebook[100];

// while (fgets(entry[i].person->name, sizeof(entry[i].person->name), stdin) != NULL) {
  char ime[20];

  while (1) {
    entry = (struct phonebook_entry_t *) malloc(sizeof(struct phonebook_entry_t));
    entry->person = (struct person_t *) malloc(sizeof(struct person_t));

    printf("Enter name: ");
    if (fgets(entry->person->name, 20, stdin) == NULL)
      break;

    printf("%s\n", entry->person->name);
    // strcpy(entry->person->name, ime);

    printf("Enter phone: ");
    scanf("%d", &entry->phone);

    phonebook[count] = entry;
    count++;
  }

  printf("\n\n\n-------");

  for (int j = 0; j < count; ++j) {
    printf("%d: ", j);
    printf("\n%d", phonebook[j]->phone);
    printf("\n%s", phonebook[j]->person->name);
  }


  return 0;
}

void print_person(struct phonebook_entry_t *pp){
  printf("\n%d", pp->phone);
}








// phonebook_entry_t *cardPtr, *cardArPtr;

// int num;

// cardPtr = (phonebook_entry_t*)malloc(sizeof(phonebook_entry_t));

// cardArPtr = (phonebook_entry_t*)calloc(num,sizeof(phonebook_entry_t));
