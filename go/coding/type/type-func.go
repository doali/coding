package main

import "fmt"

type op = func(...int) int // the interesting point

func add(nums ...int) (total int) {
	total = 0
	for _, num := range nums {
		total += num
	}
	return
}

func mul(nums ...int) int {
	total := 1
	for _, num := range nums {
		total *= num
	}
	return total
}

func main() {
	fmt.Println("Type definition")
	list := []int{1, 2, 3, 4, 5}
	listOp := []op{add, mul} // the other interesting point

	for _, op := range listOp {
		res := op(list...) // unpacking array as args
		fmt.Println(res)
	}
}
