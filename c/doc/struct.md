# `struct`

## Initialization

- default values

- [cppreference](https://en.cppreference.com/w/c/language/initialization#Implicit_initialization)

## Anonymous structure

```c
struct {
  int id;
  const char *word;
} key; // key is a variable of type struct { ... }

key.id = 10;
key.word = "anonymous structure";

printf("%d:%s\n", key.id, key.word);
```

```c
// ---------------------------------------------------------------------------
struct Base {
  int fieldBase;
  struct Inner {
    int fieldInner;
  } varInner; // varInner is a VARIABLe of type struct Inner
};

struct Base s_base;
s_base.fieldBase = 1;
s_base.varInner.fieldInner = 2;

// ---------------------------------------------------------------------------
struct BaseAnonymousInner {
  int fieldBase;
  struct { // ANONYMOUS structure
    int fieldInner;
  } /* varInner */; // WARNING !!
                    // if varInner is written
                    // then to access fieldInner member 
                    // we have to add varInner !!
                    // => <instance_BaseAnonymousInner>.varInner.fieldInner !!
};

struct BaseAnonymousInner s_base_a;
s_base_a.fieldBase = 1;
s_base_a.fieldInner = 2; // if varInner is not written then
                         // we can access fieldInner directly
```

- [doali struct-2](https://github.com/doali/coding/tree/master/c/coding/var/struct/struct-2)

## Aliases vs Variables

```c
typedef struct s_person {
  const char *name;
  const char *firstname;
  Address address;
  void (*print_s_person)(const struct s_person *); // Only function pointers !!
} Person;
```

> `Person` is an alias to `struct s_person` \
> thanks to `typedef`

```c
struct s_geek {
  Person person;
  const char *hobby;
} brianKernighan =
    /* VARIABLE which type is struct s_geek, and which is initialized */
    {{
         "Jean",                   // const char *name;
         "LaCruche",               // const char *firstname;
         {1, "rue du code", 1010}, // Address address;
         p_print_person, // void (*print_s_person)(const struct s_person *);
     },
     "computing"};
```

> `brianKernighan` is a variable which type is `struct s_geek` \
> what is more, `brianKernighan` is initialized !! \
> Note that we use a fonction pointer `p_print_person` \

- [doali struct-1](https://github.com/doali/coding/tree/master/c/coding/var/struct/struct-1)
- [cppreference struct and union initialization](https://en.cppreference.com/w/c/language/struct_initialization)

## Biblio

- [cppreference struct](https://en.cppreference.com/w/c/language/struct)
- [courses whashington](https://courses.cs.washington.edu/courses/cse351/17au/lectures/14/CSE351-L14-structs_17au.pdf)
