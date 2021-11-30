import functools

# exemple de fichier ./tmp
# wc -l * | awk '{print$1}' >tmp

with open('./tmp', 'r') as f:
    d = {}
    ll = [ int(x) for x in f.readlines()]
    d = {(x + 1): ll[x] for x in list(range(len(ll)))}
    print(d)
    res = functools.reduce(lambda x, y: x + y, ll)
    m = functools.reduce(lambda x, y: x if x > y else y, ll)
    print(f"lines={len(ll)} max={m} total={res}")

