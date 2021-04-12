package main

/*
https://golang.org/cmd/cgo/
*/

// #cgo LDFLAGS: -L/workspace/coding/go/coding/cgo/operation -loperation
// #include "operation/operation.h"
import "C"
import "fmt"

func main() {
	resLibOpAdd := C.op_add(10, 20)
	fmt.Println("resLibOpAdd:", resLibOpAdd)
	message := C.affiche()
	fmt.Println("Message:", C.GoString(message))

	var s C.s_address	
	C.s_address_init(&s)
	fmt.Println("Number:", s.number)
	fmt.Println("Street:", C.GoString(s.street))
	fmt.Println("Titi:", s.s_titi.lol)
}