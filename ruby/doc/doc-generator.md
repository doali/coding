# Documentation

_Générateurs de la documentation du code._

## `yard`

### Installation

```bash
gem install yard
```

### Utilisation

```bash
yard doc [<source>.rb]*
```

> La documentation est générée dans un répertoire `doc` dans le répertoire courant
> `firefox ./doc/index.html` : pour observer la documentation

### Exemple

```bash
# Converts the object into textual markup given a specific format.
#
# @param format [Symbol] the format type, `:text` or `:html`
# @return [String] the object converted into the expected format.
def to_format(format = :html)
  # format the object
end
```

## `rdoc`

### Installation

_installé avec ruby_

### Exemple

```bash
# Converts the object into textual markup given a specific `format`
# (defaults to `:html`)
#
# == Parameters:
# format::
#   A Symbol declaring the format to convert the object to. This
#   can be `:text` or `:html`.
#
# == Returns:
# A string representing the object in a specified
# format.
#
def to_format(format = :html)
  # format the object
end
```

```bash
rdoc [<source>.rb]*
```

> La documentation est générée dans un répertoire `doc` dans le répertoire courant
> `firefox ./doc/index.html` : pour observer la documentation

## Biblio

- [yard rubydoc](https://rubydoc.info/gems/yard/file/docs/GettingStarted.md)
- [yard](https://yardoc.org/)
- [cheatsheet](https://gist.github.com/chetan/1827484)
