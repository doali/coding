package main

import (
	"fmt"
)

func main() {
	(func(s string) {
		fmt.Println("=====>")
		fmt.Println(s)
		fmt.Println("<=====")
	})("titi")

	lf := func(a int) func(int) int {
		return (func(b int) int {
			return a + b
		})
	}

	a := 10
	b := 1

	fmt.Println(lf(a)(b))
	fmt.Println((func(a int, b int) int { return a + b })(3, 4))

	f := func(a int) int { return 10 + a }
	g := func(a int, c func(int) int) int { return c(a) }
	fmt.Println(f(1))
	fmt.Println(g(2, f))

	k := func(a int) func(int) int {
		return (func(b int) int {
			return a + b
		})
	}
	k_20 := k(20)
	fmt.Println(k_20(3))
}
