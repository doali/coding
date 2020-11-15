package main

import (
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
