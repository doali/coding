# Methodes _static_ et _d'instance_

## Methodes statiques : `@classmethod`, `@staticmethod`

### `@classmethod`

- `cls` est la classe courante

> permet d'agir sur les membres static

```python
class Student(object):
    def __init__(self, first_name, last_name):
        self._first_name = first_name
        self._last_name = last_name

    @classmethod
    def from_string_class(cls, name_str):
        first_name, last_name = map(str, name_str.split(" "))
        student = cls(first_name, last_name)
        return student
```

> `cls` permet de connaitre la classe !!

### `@staticmethod`

```python
class Student(object):
    def __init__(self, first_name, last_name):
        self._first_name = first_name
        self._last_name = last_name

    @staticmethod
    def from_string_static(name_str):
        first_name, last_name = map(str, name_str.split(" "))
        student = Student(first_name, last_name)
        return student
```

> pas de paramètre _cls_, on indique directement le nom de la classe

## Methodes d'instance :`self`

- `self` est la reference de l'instance courante

> permet d'agir sur les membres d'instance de la classe (l'objet)

```python
class Student(object):
    def __init__(self, first_name, last_name):
        self._first_name = first_name
        self._last_name = last_name

    def __str__(self):
        return f"{self._first_name} {self._last_name}"


scott = Student("Scott", "Robinson")
print(scott)
```

## Biblio

- [stackabuse](https://stackabuse.com/pythons-classmethod-and-staticmethod-explained/)
- [medium](https://medium.com/@arkilis/python-instance-method-vs-static-method-vs-class-method-5e43cef6df78)
