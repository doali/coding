# Python _magic methods_

## `class`

> texte de rszalski

```text
__new__(cls, [...)
    __new__ is the first method to get called in an object's instantiation. It takes the class, then any other arguments that it will pass along to __init__. __new__ is used fairly rarely, but it does have its purposes, particularly when subclassing an immutable type like a tuple or a string. I don't want to go in to too much detail on __new__ because it's not too useful, but it is covered in great detail in the Python docs.
__init__(self, [...)
    The initializer for the class. It gets passed whatever the primary constructor was called with (so, for example, if we called x = SomeClass(10, 'foo'), __init__ would get passed 10 and 'foo' as arguments. __init__ is almost universally used in Python class definitions.
__del__(self)
    If __new__ and __init__ formed the constructor of the object, __del__ is the destructor. It doesn't implement behavior for the statement del x (so that code would not translate to x.__del__()). Rather, it defines behavior for when an object is garbage collected. It can be quite useful for objects that might require extra cleanup upon deletion, like sockets or file objects. Be careful, however, as there is no guarantee that __del__ will be executed if the object is still alive when the interpreter exits, so __del__ can't serve as a replacement for good coding practices (like always closing a connection when you're done with it. In fact, __del__ should almost never be used because of the precarious circumstances under which it is called; use it with caution!
```

```python
class Pattern(object):
    def __new__(cls):
        print("__new__")
        return super(Pattern, cls).__new__(cls)

    def __init__(self):
        #super().__init__()
        print("__init__")

    def __del__(self):
        print(f"__del__ called")

if __name__ == '__main__':
    inst = Pattern()
    print(f"Instance: {inst}")
```

qui renvoie

```bash
__new__
__init__
Instance: <__main__.Pattern object at 0x7f91e62a0780>
__del__ called
```

## Biblio

- [rszalski](https://rszalski.github.io/magicmethods/)
