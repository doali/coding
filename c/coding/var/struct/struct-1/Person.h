#include <stdio.h>
#include <stdlib.h>

#define NUMBER 1
#define STREET "rue des mesanges"
#define CODE 75001
#define NAME_1 "Jean"
#define NAME_2 "Dubourg"

#define LINE_BREAK printf("\n");

typedef struct s_address Address;

struct s_address {
  unsigned int number;
  const char *street;
  unsigned int postal_code;
};

void print_addr(const Address *addr) {
  printf("%d %s %d\n", addr->number, addr->street, addr->postal_code);
}

typedef struct s_person {
  const char *name;
  const char *firstname;
  Address address;
  void (*print_s_person)(const struct s_person *); // Only function pointers !!
} Person;

/*
struct in_my_dream {
  const char *name;
  const char *firstname;
  Address address;
  void print_s_person() {
    printf("%s %s\n", this->name, this->firstname);
    print_addr(&this->address);
  }
};
*/

void print_person(const Person *pers) {
  printf("%s %s\n", pers->name, pers->firstname);
  print_addr(&pers->address);
}

void p_print_person(const Person *person) {
  printf("[%s %s]\n", person->name, person->firstname);
}

struct s_geek {
  Person person;
  const char *hobby;
} brianKernighan =
    /* Initialiazation of a struct s_geek VARIABLE */
    {{
         "Jean",                   // const char *name;
         "LaCruche",               // const char *firstname;
         {1, "rue du code", 1010}, // Address address;
         p_print_person, // void (*print_s_person)(const struct s_person *);
     },
     "computing"};

typedef struct s_geek *Geek;

void print_hobby(Geek geek) {
  // geek->person.print_s_person(&geek->person); // OK (but that ugly...
  print_person(&geek->person);
  printf("- hobby : %s\n", geek->hobby);
}

/*
void print_geek(const struct s_geek *geek) {
  geek->person.print_s_person(&geek->person);
  printf(", com
  */
