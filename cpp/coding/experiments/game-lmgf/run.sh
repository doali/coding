#!/bin/bash - 

# permet d'exécuter du code
# dans une zone autorisée sur smartphone

TMP_RUN=$(mktemp -d)

[ -d ${TMP_RUN} ] && cp $1 ${TMP_RUN}
cd ${TMP_RUN} && chmod +x $1 && ./$1
cd - >/dev/null

rm -rf ${TMP_RUN}
