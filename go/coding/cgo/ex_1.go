package main

// #cgo LDFLAGS: -L/workspace/coding/go/coding/cgo/operation -loperation
// #include "operation/operation.h"
import "C"
import "fmt"

func main() {
	resLibOpAdd := C.op_add(10, 20)
	fmt.Println("resLibOpAdd:", resLibOpAdd)
	message := C.affiche()
	fmt.Println("Message:", C.GoString(message))
}