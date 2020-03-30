# List et range(...)

_Generation de listes_

## En bref
|python 2  |python 3|
|----------|--------|
|range(...)|list(range(...)|

## Explication
```text
So in Python 3.x, the range() function got its own type. In basic terms, if you want to use range() in a for loop, then you're good to go. However you can't use it purely as a list object. For example you cannot slice a range type.

When you're using an iterator, every loop of the for statement produces the next number on the fly. Whereas the original range() function produced all numbers instantaneously, before the for loop started executing. The problem with the original range() function was that it used a very large amount of memory when producing a lot of numbers. However it tends to be quicker with a small amount of numbers. Note that in Python 3.x, you can still produce a list by passing the generator returned to the list() function.

Jackson Cooper 
```

## Exemples
*Python 2*
```python
>>> range(4)
[0, 1, 2, 3]
>>> range(4,5)
[4]
>>> range(4,10)
[4, 5, 6, 7, 8, 9]
>>> 
```

*Python 3*
```python
>>> list(range(4))
[0, 1, 2, 3]
>>> list(range(4,5))
[4]
>>> list(range(4,10))
[4, 5, 6, 7, 8, 9]
>>> 
```

## Biblio
- [pythonceltral](https://www.pythoncentral.io/pythons-range-function-explained/)
