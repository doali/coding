#!/usr/bin/env nodejs

/*
 * Inner function
 * Extra syntax to generate an array
 * https://developer.mozilla.org/fr/docs/Web/JavaScript/Reference/Op%C3%A9rateurs/Syntaxe_d%C3%A9composition
 * - spread operator `...`
 * https://developer.mozilla.org/fr/docs/Web/JavaScript/Reference/Objets_globaux/Array/forEach
 * - <Array>.forEach(([arg, ...]) => { statement; [statement, ...] }
 */

function f(y) {
    return function(k) {
        return y + k
    }
}

let l = [...Array(10).keys()]; // spread operator

let f_10 = f(10) //

l.forEach(element => {
    console.log(`${element}:f_10(${element})=${f_10(element)}`)
})
