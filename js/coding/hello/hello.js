#!/usr/bin/env nodejs

// --------------------------------------------------------------------------------
// https://developer.mozilla.org/fr/docs/Web/JavaScript/Reference/Template_literals
// --------------------------------------------------------------------------------

var fac =
    function(n) {
        if (n == 0) {
            return 1
        } else {
            return n * fac(n - 1)
        }
    }

console.log("fac(6)")
console.log(fac(6))
console.log("\n")

console.log(`fac(5)=${fac(5)}`)
