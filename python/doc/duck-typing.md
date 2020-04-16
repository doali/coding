# Python _duck typing_

## Definition

```text
In Python, you don’t have to explicitly declare an interface. Any object that implements the desired interface can be used in place of another object. This is known as duck typing. Duck typing is usually explained as “if it behaves like a duck, then it’s a duck.”
```

## Exemple

```python
# In disgruntled.py

class DisgruntledEmployee:
    def __init__(self, id, name):
        self.id = id
        self.name = name

    def calculate_payroll(self):
        return 1000000
```

```text
The DisgruntledEmployee class doesn’t derive from Employee, but it exposes the same interface required by the PayrollSystem. The PayrollSystem.calculate_payroll() requires a list of objects that implement the following interface:

    An id property or attribute that returns the employee’s id
    A name property or attribute that represents the employee’s name
    A .calculate_payroll() method that doesn’t take any parameters and returns the payroll amount to process

All these requirements are met by the DisgruntledEmployee class, so the PayrollSystem can still calculate its payroll.
```

```python
class PayrollSystem:
    def calculate_payroll(self, employees):
        print('Calculating Payroll')
        print('===================')
        for employee in employees:
            print(f'Payroll for: {employee.id} - {employee.name}')
            print(f'- Check amount: {employee.calculate_payroll()}')
            print('')
```

> Code repris de realpython

## Bilio

- [realpython](https://realpython.com/inheritance-composition-python/#whats-composition)
