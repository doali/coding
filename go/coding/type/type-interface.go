package main

import "fmt"

type Common interface {
	TellWhoYouAre()
}

type Titi struct{}

func (Titi) TellWhoYouAre() {
	fmt.Println("Titi")
}

type Titou struct{}

func (Titou) TellWhoYouAre() {
	fmt.Println("Titou")
}

func process() {
	list := []Common{&Titi{}, &Titou{}}
	for _, e := range list {
		e.TellWhoYouAre()
	}
}

func main() {
	fmt.Println("Main")
	process()
}
