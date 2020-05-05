#!/usr/bin/env nodejs

/*
 * https: // medium.com/better-programming/prototypes-in-javascript-5bba2990e04b
 */

class Person {
  constructor(nom, prenom) {
    this._nom = nom;
    this._prenom = prenom;
  }

  affiche() { console.log(this._nom + " " + this._prenom); }

  static f_affiche(p) { console.log(p._nom + " " + p._prenom); }
}

function test() {
  p = new Person("Brendan", "Eich");
  p.affiche();
  Person.f_affiche(p);
}

test()
