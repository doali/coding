# Python _operator_

## `__new__()`

```text
Languages such as Java and C# use the new operator to create a new instance of a class. 
In Python the __new__() magic method is implicitly called before the __init__() method. 
The __new__() method returns a new object, which is then initialized by __init__(). 
```

## `__add__()`

```python3
blackpc@blackpc-pc:/tmp$ cat redef_add.py
class MyClass:

    def __add__(self, x):
        return int(x) + 100

blackpc@blackpc-pc:/tmp$ python3
Python 3.6.9 (default, Nov  7 2019, 10:44:02)
[GCC 8.3.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> import redef_add
>>> a = 1
>>> a
1
>>> plus_100 = redef_add.MyClass()
>>> plus_100 + a
101
>>>
```

## Biblio

- [tutorialsteacher](https://www.tutorialsteacher.com/python/magic-methods-in-python)
