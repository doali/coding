package main

import (
	"testing"
)

func TestNewPerson(t *testing.T) {
	p := newPerson("titi", 100)

	pp := Person{
		"titi",
		100,
	}

	if p.name != pp.name {
		t.Error("Reason name :", p.name, "<>", pp.name)
	}

	if p.id != p.id {
		t.Error("Reason id :", p.id, "<>", pp.id)
	}
}

func TestStringPerson(t *testing.T) {
	p := newPerson("jacques", 123)

	reference := "{jacques:123}"

	if strp := p.String(); strp != reference {
		t.Error("Reason :", strp, "<>", reference)
	}
}
