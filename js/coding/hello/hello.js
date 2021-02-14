#!/usr/bin/env nodejs

var fac =
    function(n) {
        if (n == 0) {
            return 1
        } else {
            return n * fac(n - 1)
        }
    }

console.log("fac(10)")
console.log(fac(6))
console.log("\n")
