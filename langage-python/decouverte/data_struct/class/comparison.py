class A:
    pass

class B:
    pass

a = A()
b = B()

print('a:', a)
print('b:', b)
print("a is b", a is b)
b = a

print('a:', a)
print('b:', b)
print("a is b", a is b)
