package main

import (
	"fmt"
	"time"
)

func main() {
	status := make(chan string)

	go func(s int) {
		//time.Sleep(time.Duration(s) * time.Second)
		t := s
		for t > 0 {
			time.Sleep(1 * time.Second)
			fmt.Println("Be patient", t, "seconds remaining")
			t--
		}
		status <- "Finished !!"
	}(5)

	go func() {
		cpt := 0
		for {
			fmt.Println(" ", cpt)
			time.Sleep(100 * time.Millisecond)
			cpt++
		}
	}()

	finished := <-status
	fmt.Println(finished)
}
