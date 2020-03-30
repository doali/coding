# Here TAG

_Utilisation pratique dans la console pour une écriture multi-lignes_

---

## En bref
```bash
cat <<EOF | bash
while [ 1 ]; do
clear
./thread_1.py 
./thread_2.py 
./thread_3.py 
done
EOF
```

## Règles
_[...] "EOF" is known as a "Here Tag". Basically <<Here tells the shell that you are going to enter a multiline string until the "tag" Here. You can name this tag as you want, it's often EOF or STOP._

**Some rules about the Here tags:**

- The tag can be any string, uppercase or lowercase, though most people use uppercase by convention.
- The tag will not be considered as a Here tag if there are other words in that line. In this case, it will merely be considered part of the string. The tag should be by itself on a separate line, to be considered a tag.
- The tag should have no leading or trailing spaces in that line to be considered a tag. Otherwise it will be considered as part of the string.

## Usage
### Assign multi-line string to a shell variable

```bash
$ sql=$(cat <<EOF
SELECT foo, bar FROM db
WHERE foo='baz'
EOF
)
```
> The `$sql` variable now holds the new-line characters too. You can verify with `echo -e "$sql"`.

### Pass multi-line string to a file in Bash

```bash
$ cat <<EOF > print.sh
#!/bin/bash
echo \$PWD
echo $PWD
EOF
```
> The print.sh file now contains:
```bash
#!/bin/bash
echo $PWD
echo /home/user
```

### Pass multi-line string to a pipe in Bash
```bash
$ cat <<EOF | grep 'b' | tee b.txt
foo
bar
baz
EOF
```
> The b.txt file contains bar and baz lines. The same output is printed to stdout.

## Biblio
- [stack over flow](https://stackoverflow.com/questions/2500436/how-does-cat-eof-work-in-bash)