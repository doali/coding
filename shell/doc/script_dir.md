# Repertoire d'un script
_Connaitre le chemin d'un script que l'on exécute dans un répertoire autre que le répertoire le contenant._
# Script
```bash
# ------------------------------------------------------------------------------
# return script path from the current working directory
# https://www.ostricher.com/2014/10/the-right-way-to-get-the-directory-of-a-bash-script/
get_script_dir() {
  local source="${BASH_SOURCE[0]}"
  local dir=""
  # While $source is a symlink, resolve it
  while [ -h "$source" ]; do
    dir="$(cd -P "$(dirname "$source")" && pwd)"
    source="$(readlink "$source")"
    # If $source was a relative symlink (so no "/" as prefix,
    # need to resolve it relative to the symlink base directory
    [[ $source != /* ]] && source="$dir/$source"
  done
  dir="$(cd -P "$(dirname "$source")" && pwd)"
  echo $dir # returns to sdout (clever mean to return results)
}

# symlinks are not handled using as described in the following command
#readonly DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

# ------------------------------------------------------------------------------
readonly DIR_SCRIPT=$(get_script_dir) # gets from stdout

# Now we can use the variable
echo ${DIR_SCRIPT}
```
*Quelques explications*
- `BASH_SOURCE[0]` : renvoie le nom du script
- `dirname <obj>` : si <obj> est de la forme a/b/c/d/e alors renvoie a/b/c/d
- `readlink <obj>` : résout le lien (renvoie le chemin du fichier de référence)

*Idées*
- définir une fonction
- utiliser des variables locales
- `while [ -h ... ]` : permet de savoir si l'objet testé est un lien symbolique
- dans la fonction ecrire sur la sortie standard le résultat
- lors de l'appel de la fonction
  - capturer la sortie standard dans une variable

*Astuce*
> (!) les fonctions bash ne peuvent que renvoyer un ***status*** \
> Donc, pour exploiter une "valeur de retour"
> - on l'écrit sur la sortie standard :-)

# Biblio
- [ostricher](https://www.ostricher.com/2014/10/the-right-way-to-get-the-directory-of-a-bash-script/)
