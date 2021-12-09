
f = lambda x: lambda y: x + y

a = 10
b = 3

print(f"f({a}, {b})={f(a)(b)}")
