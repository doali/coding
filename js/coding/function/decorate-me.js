#!/usr/bin/env nodejs

function pretty_print(msg) { console.log(msg) }

pretty_print("coucou")

function decore(fun) {
  function dec(msg) {
    console.log("Il fait beau non ?")
    fun(msg)
    console.log("Pas vrai :-) ?")
  }

  return dec
}

pretty_print = decore(decore(pretty_print))

pretty_print("coucou")
