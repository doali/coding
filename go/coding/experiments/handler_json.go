package main

import (
	"encoding/json"
	"fmt"
)

type Page struct {
	Id    string
	Title string
}

func main() {
	b, err := json.Marshal(Page{"id_page_1", "titre_page_1"})

	if err != nil {
		fmt.Println("Error:", err)
	}

	fmt.Println(string(b))
}
