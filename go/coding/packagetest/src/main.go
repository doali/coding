package main

// https://stackoverflow.com/questions/52123627/how-do-i-resolve-cannot-find-module-for-path-x-importing-a-local-go-module
// GO111MODULE=off go run main.go

import (
	"fmt"

	"./packa"
	"./packb"
)

type Common interface {
	TellWhoYouAre()
}

func process() {
	list := []Common{&packa.Titi{}, &packb.Titou{}}
	for _, e := range list {
		e.TellWhoYouAre()
	}
}

func main() {
	fmt.Println("GO111MODULE=off go run main.go")
	process()
}
