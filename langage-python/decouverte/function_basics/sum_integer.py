#!/usr/bin/env python

l = [1, 2, 3, 4, 5, 6, 7]


def _sum(n):
    return n * (n + 1) / 2


def _sum_rec(l):
    if l == []:
        return 0
    else:
        return l.pop() + _sum_rec(l)


def _sum_list(liste):
    res = 0
    for element in liste:
        res += element
    return res


print _sum(7)
print _sum_list(l)  # mettre avant l'appel de _sum_rec <= vide la liste pop() :-)
print _sum_rec(l)


def fac(n):
    res = 1
    while n > 0:
        res *= n
        n -= 1

    return res


def fac_rec(n):
    if n == 0:
        return 1
    else:
        return n * fac_rec(n - 1)


print fac_rec(5)
print fac(5)
