package main

import (
	"fmt"
	"testing"
)

func TestAddKey(t *testing.T) {
	result := false

	// TODO

	if !result {
		t.Error("Reason", result)
	}
}

func TestNesqdfq(t *testing.T) {

	fmt.Println(Person{"Bob", 20})

	fmt.Println(Person{name: "Alice", id: 30})

	fmt.Println(Person{name: "Fred"})

	fmt.Println(&Person{name: "Ann", id: 40})

	fmt.Println(newPerson("Jhon", 10))

	s := Person{name: "Sean", id: 50}
	fmt.Println(s.name)

	sp := &s
	fmt.Println(sp.id)

	sp.id = 51
	fmt.Println(sp.id)
}
