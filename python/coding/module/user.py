#!/usr/bin/env python3

import calcul as mod_cal


def op(a, b):
    return mod_cal.sum(a, b)


if __name__ == "__main__":
    import file_is_module as m

    print(m.info())

    res_op = op(1, 2)
    print(f"{op}|{res_op}")
