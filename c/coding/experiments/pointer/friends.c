#include <stdio.h>
#include <stdlib.h>

typedef struct person {
  const char *firstname;
  struct person *friends;
} Person;

Person *create_person(const char *first_name) {
  struct person *new_person = (struct person *)(malloc(sizeof(Person)));

  new_person->firstname = first_name;
  new_person->friends = NULL;

  return new_person;
};

Person *detach_person(Person *p) {
  Person *p_person = (p && p->friends) ? p->friends : NULL;
  if (p_person)
    p->friends = NULL;
  return p_person;
}

void add_friends(Person *person, Person *friends) {
  if (person)
    person->friends = friends;
}

void print_person(Person *person) { printf("%s\n", person->firstname); }

void print_friends(Person *person) {
  Person *p_person = person;
  while (p_person) {
    print_person(p_person);
    p_person = p_person->friends;
  }
}

int main(int argc, char **argv) {
  //
  Person person_ulyss = {"Ulyss", NULL};
  Person person_penelope = {"Penelope", NULL};
  Person person_zeus = {"Zeus", NULL};
  Person *person_neptune = create_person("Neptune");

  add_friends(&person_ulyss, &person_penelope);
  add_friends(&person_ulyss, person_neptune);
  add_friends(&person_ulyss, &person_zeus);

  print_friends(&person_ulyss);

  detach_person(person_neptune); // OK
  detach_person(&person_zeus);
  detach_person(person_neptune);
  detach_person(NULL);

  if (person_neptune)
    free(person_neptune);

  return 0;
}
