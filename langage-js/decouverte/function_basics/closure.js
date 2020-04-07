#!/usr/bin/env nodejs

function closure(a) {
  return function(x) { return a ** x }
}

let f_10 = closure(10)

for (i = 0; i < 10; ++i) {
  let res = f_10(i)
  console.log(res)
}
