package main

import "fmt"

func main() {
	var i, j int = 1, 2
	k := 3
	c, python, java := true, false, "no!"

	fmt.Println(i, j, k, c, python, java)

	var l = "1A"
	fmt.Printf("Type: %T Value:%v\n", l, l)
}
