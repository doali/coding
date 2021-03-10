#!/usr/bin/env python3


import json


obj_rules = json.load(open("constraints.json", "r"))

def get_path(comp_name):
    for k in obj_rules["components"]:
        if k['name'] == comp_name:
            return k['path']
    return None


def fill_dico():
    dico = {}

    for comp in obj_rules["components"]:
        dico[comp["name"]] = json.load(open(comp["path"], "r"))

    return dico


def is_atomic_rule_satisfied(field_1, field_2, rule):    
    switcher = {
        "equal" : (field_1 == field_2),
        "different" : (field_1 != field_2)
    }

    res = switcher.get(rule, False)

    if (not res):
        print(f"KO:{rule} \n{field_1:>30} \n{field_2:>30}")

    return res


def check_constraints(dico):
    all_satisfied = True
    res = True

    for comp in obj_rules["components"]:

        for dependence in comp["depends"]:
            obj_comp_2 = dico[dependence["name"]]

            for k, v in dependence["constraint"].items():
                if k in obj_comp_2:
                    res = is_atomic_rule_satisfied(dico[comp["name"]][k], obj_comp_2[k], v)
                    all_satisfied = all_satisfied and res
                    if not res:
                        print(f"{comp['path']} => {get_path(dependence['name'])}")
                        print("---")
                else:
                    if 'target' in v:
                        res = is_atomic_rule_satisfied(dico[comp["name"]][k], obj_comp_2[v["target"]], v['op'])
                        all_satisfied = all_satisfied and res
                        if not res:
                            print(f"{comp['path']} => {get_path(dependence['name'])}")
                            print("---")
                            
    return all_satisfied and res


if __name__ == "__main__":
    dico = fill_dico()
    print("ok") if (check_constraints(dico)) else "ko"
