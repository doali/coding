#!/usr/bin/env nodejs

/*
 * Commentaires ayant sens dans le cadre suivant
 * - exécution en mode console
 * - interpreteur : node (nodejs)
 */

/*
 * http://speakingjs.com/es5/ch16.html
 */

// Variable globale
var x = 1234

// Fonction globale (declaration definition)
function function_1() {
    // Utilisation de la variable x
    // dans la portée LEXICALE !!
    console.log(x) // 1234
    // ATTENTION
    // si var x = 1234 était après la déclaration définition de function_1
    // alors x aurait été undefined
}

// Fonction globale (declaration definition)
function main() { // => retourne une fonction
    // Variable locale
    var x = 4321
    // Retourne une fonction
    return function_1
    console.log(x) // Code jamais atteint
}

// Declaration d'une variable
var gg;

// Declaration et initialisation
var t = main()
// affectation d'une fonction (similitude aux pointeurs sur fonction)

// Execution !!
// de la fonction : function_1 retournée par la fonction : main
t()

// Fonction globale (déclaration et définition)
function un() {
    var x = 456
    return function() {
        console.log(x)
    } // PORTEE LEXICALE
    // x a pour valeur 456
    // car déclaration définition ICI
}

console.log(x) // 1234

var m = un() // retourne la fonction anonyme définie dans la fonction un()

m() // exécution