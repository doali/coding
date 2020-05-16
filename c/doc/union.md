# `union`

## Definition

```
Unions allow one portion of memory to be accessed as different data types. Its declaration and use is similar to the one of structures, but its functionality is totally different
```

> [cplusplus.com](http://www.cplusplus.com/doc/tutorial/other_data_types/)

```c
union type_name {
  member_type1 member_name1;
  member_type2 member_name2;
  member_type3 member_name3;
  ...
} object_names;
```

- `type_name` identifies the union,
- all its member elements occupy the same physical space in memory,
- they share the same memory location (=> only one member at a time !!)
- the size of this type is the one of the largest member element.

## Examples

```c
union mytypes_t {
  char c;
  int i;
  float f;
} mytypes;
```

## Alignment

- [doali union-1.c](https://github.com/doali/coding/blob/master/c/coding/var/union/union-1.c)

## Anonymous unions

- members of anonymous unions can be accessed from their names directly

- [cplusplus](http://www.cplusplus.com/doc/tutorial/other_data_types/)

## Biblio

- [cppreference union](https://en.cppreference.com/w/c/language/union)
