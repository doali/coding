#!/usr/bin/env bash
#===============================================================================
#
#          FILE: script_dir.sh
# 
#         USAGE: ./script_dir.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 09/04/2020 15:01
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error
#set -x

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
