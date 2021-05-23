package main

import (
	"fmt"
	"strconv"
)

// Person ...
type Person struct {
	name string
	id   uint64
}

func newPerson(name string, id uint64) *Person {
	p := Person{name: name}
	p.id = id

	return &p
}

func (p *Person) String() string {
	return "{" + p.name + ":" + strconv.FormatUint(p.id, 10) + "}"
}

func main() {
	var p1 *Person
	p1 = newPerson("Titi", 64)
	fmt.Println(p1.String())

	var p2 Person
	p2 = *p1
	fmt.Println(p2.String())

	var p3 *Person = &Person{"Miaou", 65}
	fmt.Println(p3)

	var p4 *Person = new(Person)
	p4.id = 62
	p4.name = "Riri"
	fmt.Println(p4)
}
