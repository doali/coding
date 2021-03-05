#!/bin/bash
# repris de : https://www.linuxjournal.com/content/bash-arrays
# https://linuxhint.com/associative_array_bash/

array=(one two three four [5]=five)

echo "Array size: ${#array[*]}"

echo "Array items:*"
for item in ${array[*]}; do
  printf "   %s\n" $item
done

echo "Array items:@"
for item in ${array[@]}; do
  printf "   %s\n" $item
done

echo "Array indexes:"
for index in ${!array[*]}; do
  printf "   %d\n" $index
done

echo "Array items and indexes:"
for index in ${!array[*]}; do
  printf "%4d: %s\n" $index ${array[$index]}
done

# ------------------------------------------------------------------------------
# BE CAREFUL
#Both syntax let us access all the values of the array and produce the same results, unless the expansion it's quoted. In this case a difference arises: in the first case, when using @, the expansion will result in a word for each element of the array. This becomes immediately clear when performing a for loop. As an example, imagine we have an array with two elements, "foo" and "bar"

my_array=(foo bar)

for i in "${my_array[@]}"; do echo "$i"; done # result on multiple lines

for i in "${my_array[*]}"; do echo "$i"; done # result on a single line
