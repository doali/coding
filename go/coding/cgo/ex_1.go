package main

// #cgo LDFLAGS: -L//workspace/coding/go/coding/cgo/operation -loperation

// #include "operation/operation.h"
// typedef int (*intFunc) ();
//
// int
// bridge_int_func(intFunc f)
// {
//		return f();
// }
//
// int fortytwo()
// {
//	    return 42;
// }
/*
int sum(int a, int b)
{
	return a + b;
}

int mul(int a, int b)
{
	return a * b;
}
// typedef int (*p_op)(int, int); // https://golang.org/cmd/cgo/ PAS DE POINTEUR SUR FONCTION
*/
import "C"
import "fmt"

func main() {
	f := C.intFunc(C.fortytwo)	
	fmt.Println(int(C.bridge_int_func(f)))
	// Output: 42
	resMul := C.mul(2, 3)
	fmt.Println("resMul:", resMul)
	resSum := C.sum(2, 3)
	fmt.Println("resMul:", resSum)
	
	resLibOpAdd := C.op_add(10, 20)
	fmt.Println("resLibOpAdd:", resLibOpAdd)	
}