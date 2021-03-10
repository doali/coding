#!/usr/bin/env python3

import json

obj_1 = json.load(open("comp_1.json", "r"))
obj_2 = json.load(open("comp_2.json", "r"))
obj_3 = json.load(open("comp_3.json", "r"))

obj_rules = json.load(open("data.json", "r"))

dico = {
    "component_1" : obj_1,
    "component_2" : obj_2,
    "component_3" : obj_3,
}

def check_rule(field_1, field_2, rule):
    if (rule == 'equal'):
        return field_1 == field_2
    elif (rule == 'different'):
        return field_1 != field_2
    else:
        return false

lst_comp = obj_rules['components']
print(lst_comp)

rule_comp_1 = lst_comp[0]
obj_comp_1 = dico[rule_comp_1['name']]
print(obj_comp_1)
obj_comp_1_depends = rule_comp_1['depends']
print(obj_comp_1_depends)

const_1_2 = obj_comp_1_depends[0]
obj_comp_2 = dico[const_1_2['name']]
print(obj_comp_2)

for k, v in const_1_2['constraint'].items():
    print(f"{k} => {v}")
    res = check_rule(obj_1[k], obj_comp_2[k], v)
    print("RES:" + str(res))

# for comp in obj_comp_1_depends:
#     obj = comp


if __name__ == "__main__":
    pass
    print(obj_1)
    print(obj_2)
    print(obj_3)
    print(obj_rules)
    res = check_rule('titi', 'toto', 'different')
    print(res)
    res = check_rule('titi', 'toto', 'equal')
    print(res)
    res = check_rule('titi', 'titi', 'equal')
    print(res)
    res = check_rule('titi', 'titi', 'different')
    print(res)    