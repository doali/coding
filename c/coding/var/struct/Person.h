#include <stdio.h>
#include <stdlib.h>

#define NUMBER 1
#define STREET "rue des mesanges"
#define CODE 75001
#define NAME_1 "Jean"
#define NAME_2 "Dubourg"

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

struct s_geek {
  Person person;
  const char *hobby;
} brianKernighan = {{
                        "Brian",
                        "Kernighan",
                        {1, "rue du code", 1010},
                        NULL, // WRITING print_addr IS NOT ALLOWED here
                              // either any functions or function pointers
                    },
                    "computing"};

typedef struct s_geek *Geek;

void print_hobby(Geek geek) {
  // geek->person.print_s_person(&geek->person); // OK (but that ugly...
  print_person(&geek->person);
  printf("- hobby %s\n", geek->hobby);
}

/*
void print_geek(const struct s_geek *geek) {
  geek->person.print_s_person(&geek->person);
  printf(", com
  */
