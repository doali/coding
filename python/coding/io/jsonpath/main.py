#!/usr/bin/env python3

# ------------------------------------------------------------------------------
# pip install --upgrade jsonpath-ng
# https://pypi.org/project/jsonpath-ng/
# https://www.journaldev.com/33265/python-jsonpath-examples
# ------------------------------------------------------------------------------

import json
from jsonpath_ng import jsonpath, parse

with open("db.json", 'r') as json_file:
    json_data = json.load(json_file)

print(json_data)

jsonpath_expression = parse('employees[*].id')

for match in jsonpath_expression.find(json_data):
    print(f'Employee id: {match.value}')

