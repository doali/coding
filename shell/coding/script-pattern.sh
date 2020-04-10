#!/bin/bash - 
#===============================================================================
#
#          FILE: test.sh
# 
#         USAGE: ./test.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 10/04/2020 17:47
#      REVISION:  ---
#===============================================================================

set -o errexit
set -o pipefail
set -o xtrace
set -o nounset                              # Treat unset variables as an error

# Some code

# ...

trap 'echo Error at about $LINEO' ERR

exit 0
