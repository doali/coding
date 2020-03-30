#!/usr/bin/env python2


class Example:
    Variable = 2  # static variable


print Example.Variable  # prints 2   (static variable)

# Access through an instance
instance = Example()
print instance.Variable  # still 2  (ordinary variable)

# Change within an instance
instance.Variable = 3  # (ordinary variable)
print instance.Variable  # 3   (ordinary variable)
print Example.Variable  # 2   (static variable)

# Change through Class
Example.Variable = 5  # (static variable)
print instance.Variable  # 3  (ordinary variable)
print Example.Variable  # 5  (static variable)

# Other behaviour
instance2 = Example()
print instance2.Variable  # 5 pointe sur Example.Variable
Example.Variable = 10
print instance2.Variable  # 10 pointe toujours sur Example.Variable
instance2.Variable = 11  # pointe desormais sur 11
print instance2.Variable  # 11
print Example.Variable  # 10
