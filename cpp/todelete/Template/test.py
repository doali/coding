import os

l10 = []
with open('titi_10', 'r') as f:
    l10 = [ line.rstrip() for line in f ]

l20 = []
with open('titi_20', 'r') as f:
    l20 = [ line.rstrip() for line in f ]

l = zip(l10, l20)
for a,b in l:
    os.system(f"diff {a} {b}")
