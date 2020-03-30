# Arguments
***args, kwargs***

_Utilisation de l'opérateur \* pour unpacker_

## unpacking operator (\*)

### Exemples
_Repris de realpython_

#### \*args
```python
# sum_integers_args.py
def my_sum(*args):
    result = 0
    # Iterating over the Python args tuple
    for x in args:
        result += x
    return result
```
```python
print(my_sum(1, 2, 3))
```
> In this example, you’re no longer passing a list to my_sum(). Instead, you’re passing three different positional arguments. \n
> my_sum() takes all the parameters that are provided in the input and packs them all into a single iterable object named args. \n
> Note that args is just a name. You’re not required to use the name args. You can choose any name that you prefer

### Explication
```text
Bear in mind that the iterable object you’ll get using the unpacking operator * is not a list but a tuple. A tuple is similar to a list in that they both support slicing and iteration. However, tuples are very different in at least one aspect: lists are mutable, while tuples are not.
```

#### \**kargs
```python
# concatenate.py
def concatenate(**kwargs):
    result = ""
    # Iterating over the Python kwargs dictionary
    for arg in kwargs.values():
        result += arg
    return result

print(concatenate(a="Real", b="Python", c="Is", d="Great", e="!"))
```
> When you execute the script above, concatenate() will iterate through the Python kwargs dictionary \
> and concatenate all the values it finds

```python
$ python concatenate.py
```
```text
RealPythonIsGreat!
```
> (!) - kwargs.values() => values \
> (!) - kwargs => keys

#### \[...\]\(std_args, \*args, \*\*kwargs\)
```python
# correct_function_definition.py
def my_function(a, b, *args, **kwargs):
    pass
```

### So far
```python
# merging_lists.py
my_first_list = [1, 2, 3]
my_second_list = [4, 5, 6]
my_merged_list = [*my_first_list, *my_second_list]

print(my_merged_list)
```

```python
# merging_dicts.py
my_first_dict = {"A": 1, "B": 2}
my_second_dict = {"C": 3, "D": 4}
my_merged_dict = {**my_first_dict, **my_second_dict}

print(my_merged_dict)
```

```python
# string_to_list.py
a = [*"RealPython"]
print(a)
```

```python
# mysterious_statement.py
*a, = "RealPython"
print(a)
```

## Biblio
- [realpython](https://realpython.com/python-kwargs-and-args/)
