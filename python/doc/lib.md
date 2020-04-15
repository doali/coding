# Python's common core functions

## `map(func, *iterables)`

Applique une fonction sur tous les elements de l'iterable

```python
def myfunc(a, b):
  return a + b

x = map(myfunc, ('apple', 'banana', 'cherry'), ('orange', 'lemon', 'pineapple'))

print(x)
print(list(x))
```

qui renvoie sur la stdout

```bash
<map object at 0x7f08652488d0>
['appleorange', 'bananalemon', 'cherrypineapple']
```

## Biblio

- [w3schools map](https://www.w3schools.com/python/ref_func_map.asp)
