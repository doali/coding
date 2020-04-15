# Ruby Exceptions

## Gestion des exceptions

```ruby
begin
  rescue OneTypeOfException
  rescue AnotherTypeOfException
  else # Other exceptions
  ensure # Always will be executed
end
```

- le code sensible est ecrit entre `begin` et `rescue`
- si une exception est levée alors on entre dans un bloc délimité par `rescue` et`end`
- chaque exception levée est comparée à celle filtrée et permet d'entrer dans le bloc
    - si l'exception match avec celle introduite par `rescue`
    - si l'exception match avec une superclasse de celle introduite par `rescue`
    - si aucune correspondance n'est trouvée alors on entre dans la clause `else` (qui doit-être après les clauses `rescue`)



## Biblio

- [tutorialspoint](https://www.tutorialspoint.com/ruby/ruby_exceptions.htm)
