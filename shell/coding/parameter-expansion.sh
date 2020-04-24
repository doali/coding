#!/usr/bin/env bash

#===============================================================================
set -o nounset                              # Treat unset variables as an error
#===============================================================================

WORD="one.two.three.four"
echo ${WORD}

# trim from HEAD to tail
# looking for anything which matches the pattern *.
# ends to the LAST pattern
echo "${WORD##*.}" # four

# trim from HEAD to tail
# looking for anything which matches the patter *.
# ends to the FIRST pattern
echo "${WORD#*.}" # two.three.four

# trim from TAIL to head
# looking for anything which matches the patter *.
# ends to the LAST pattern
echo "${WORD%%.*}" # one

# trim from TAIL to head
# looking for anything which matches the patter *.
# ends to the FIRST pattern
echo "${WORD%.*}" # one.two.three

# ASTUCE
# il faut voir les patterns comme des MASQUES
