#!/usr/bin/env python3


import json
import colorama
from colorama import Fore, Style

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

    # print(f"DEBUG {field_1} ? {field_2} | {rule}")

    switcher = {
        "equal" : (field_1 == field_2),
        "different" : (field_1 != field_2)
    }

    res = switcher.get(rule, False)

    log = ""
    if (not res):
        log = f"KO:{rule} \n{field_1:>30} \n{field_2:>30}"

    return res, log


def check_constraints(dico):
    all_satisfied = True
    res = True

    for comp in obj_rules["components"]:

        for dependence in comp["depends"]:
            obj_comp_2 = dico[dependence["name"]]

            for k, v in dependence["constraint"].items():
                if k in obj_comp_2:

                    res, log = is_atomic_rule_satisfied(dico[comp["name"]][k], obj_comp_2[k], v)
                    all_satisfied = all_satisfied and res

                    if not res:
                        print(f"{log}")
                        print(f"{comp['path']} => {get_path(dependence['name'])}")
                        print("---")
                        
                else:
                    if 'target' in v:                        
                        if v['target'] == 'flat':
                            # print(f"DEBUG flat")

                            obj_flat = obj_comp_2 #dico['component_2']
                            # print(f"obj_flat {obj_flat}")

                            obj_list = dico[comp['name']][k] #dico['component_1']['field_list_1']
                            # print(f"obj_list {obj_list}")

                            # res = is_flat_to_list_satisfied(obj_flat, obj_list, { "field_list_1_1" : "equal", "field_list_1_2" : "equal"})
                            res = is_flat_to_list_satisfied(obj_flat, obj_list, v['pattern']) # { "field_list_1_1" : "equal", "field_list_1_2" : "equal"})
                            all_satisfied = all_satisfied and res

                            if not res:
                                print(f"{log}")
                                print(f"{comp['path']} => {get_path(dependence['name'])}")
                                print("---")

                        elif v['target'] == 'list':
                            # print(f"DEBUG list")

                            obj_flat = dico[comp['name']] #dico['component_2']
                            # print(f"obj_flat {obj_flat}")

                            obj_list = dico[dependence['name']][v['name']] #dico['component_1']['field_list_1']
                            # print(f"obj_list {obj_list}")

                            # res = is_flat_to_list_satisfied(obj_flat, obj_list, { "field_list_1_1" : "equal", "field_list_1_2" : "equal"})
                            res = is_flat_to_list_satisfied(obj_flat, obj_list, v['pattern']) # { "field_list_1_1" : "equal", "field_list_1_2" : "equal"})
                            all_satisfied = all_satisfied and res

                            if not res:
                                print(f"{log}")
                                print(f"{comp['path']} => {get_path(dependence['name'])}")
                                print("---")

                        else:
                            # print(f"DEBUG 'rename'")
                            # print(f"DEBUG target => {v['target']}")
                            res, log = is_atomic_rule_satisfied(dico[comp["name"]][k], obj_comp_2[v["target"]], v['op'])
                            all_satisfied = all_satisfied and res
                            
                            if not res:
                                print(f"{log}")
                                print(f"{comp['path']} => {get_path(dependence['name'])}")
                                print("---")
                            
    return all_satisfied and res

def is_atomic_rule_obj_satisfied(obj_1, obj_2, pattern_rule):
    for e_pattern in pattern_rule:

        res, log = is_atomic_rule_satisfied(obj_1[e_pattern], obj_2[e_pattern], pattern_rule[e_pattern])
        if not res:
            #print(f"{log}")
            return False, log

    return True, ""


def is_flat_to_list_satisfied(obj_flat, obj_list, pattern):
    # Ajouter dans constraints.json 
    # - un moyen d'indiquer la liste : target = list, name = clef_liste    
    # Algo
    
    obj_flat_restricted = flat_to_obj(obj_flat, pattern)

    stack_log = []
    for e_list in obj_list:
                
        result, log = is_atomic_rule_obj_satisfied(obj_flat_restricted, e_list, pattern)
        if result:
            # Au moins un element e_list satisfait la regle (pattern)            
            return True
        else:
            stack_log.append(log)

    for e_log in stack_log:
        print(f"{e_log}")

    return False


def flat_to_obj(obj_flat, pattern):
    obj = {}

    for e_pattern in pattern:
        obj[e_pattern] = obj_flat[e_pattern]
    
    return obj


if __name__ == "__main__":
    dico = fill_dico()

    res_ok = f"{Fore.GREEN}OK{Style.RESET_ALL}"
    res_ko = f"{Fore.RED}KO{Style.RESET_ALL}"

    res_check = res_ok if (check_constraints(dico)) else res_ko

    print(res_check)

    # obj_flat = dico['component_2']
    # obj_list = dico['component_1']['field_list_1']
    # res = is_flat_to_list_satisfied(obj_flat, obj_list, { "field_list_1_1" : "equal", "field_list_1_2" : "equal"})
    # ok = "ok" if res else "ko"
    # print(ok)
