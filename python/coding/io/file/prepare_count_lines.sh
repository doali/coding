#!/usr/bin/env bash

#set -x # DEBUG

readonly TMP_FILE=$(mktemp)

wc_files_curr_dir() {
  for element in $(ls ${PWD}); do
    [ -f ${element} ] && wc -l ${element} >>${TMP_FILE}
  done
}

fetch_first_field() {
  readonly FD_FILE=$(mktemp)
  cat ${TMP_FILE} | cut -d\  -f1 >${FD_FILE}
  mv ${FD_FILE} ${TMP_FILE}
}

get_tmp_file_in_pwd() {
  mv ${TMP_FILE} ${PWD}/test-$(date +%s)
}

main() {
  wc_files_curr_dir
  fetch_first_field
  get_tmp_file_in_pwd
}

# ------------------------------------------------------------------------------
main
