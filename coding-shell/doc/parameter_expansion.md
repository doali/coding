# Bash parameter expansion
_Permet de modifier, filtrer, substituer des elements d'une variables, de définir des valeurs par défaut..._

# Utilisation
- substitution, filtrage selon un `<pattern>`

```bash
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
# ends to the FIRST pattern
echo "${WORD%%.*}" # one

# trim from TAIL to head
# looking for anything which matches the patter *.
# ends to the FIRST pattern
echo "${WORD%.*}" # one.two.three
```

## Biblio

- [linux journal](https://www.linuxjournal.com/content/bash-parameter-expansion)
- [stack exvhange](https://unix.stackexchange.com/questions/147560/explain-this-bash-script-echo-1)
