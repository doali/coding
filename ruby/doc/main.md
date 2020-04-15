# Ruby main method ?

```text
So, that’s the MegaGreeter class, the rest of the file just calls methods on that class. There’s one final trick to notice, and that’s the line:

if __FILE__ == $0

__FILE__ is the magic variable that contains the name of the current file. $0 is the name of the file used to start the program. This check says “If this is the main file being used…” This allows a file to be used as a library, and not to execute code in that context, but if the file is being used as an executable, then execute that code.
```

## Biblio

- [ruby-lang](https://www.ruby-lang.org/en/documentation/quickstart/4/)
