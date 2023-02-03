package main

import "fmt"

type any = interface{}

func filter[T any](l []T, f func(e T) bool) []T {
	r := make([]T, len(l))
	index := 0
	for _, v := range l {
		if f(v) {
			r[index] = v
			index++
		}
	}

	return r[:index]
}

func heaven(num int) bool {
	return num%2 == 0
}

func main() {
	arr := []int{0, 1, 2, 3, 4, 5, 6, 7}
	fmt.Println(arr)

	f_arr := filter[int](arr, heaven)
	fmt.Println(f_arr)
}
