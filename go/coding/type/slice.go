package main

// https://golang.org/pkg/encoding/binary/
// https://www.geeksforgeeks.org/how-to-copy-one-slice-into-another-slice-in-golang/
// https://stackoverflow.com/questions/29061764/golang-convert-uint32-or-any-built-in-type-to-byte-to-be-written-in-a-file
// https://github.com/golang/go/wiki/SliceTricks
// https://yourbasic.org/golang/conversions/

import (
	"encoding/binary"
	"fmt"
)

func main() {
	// s_0 := make([]byte, 10)

	// s_0[0] = uint8(15)

	// for i, v := range s_0 {
	// 	fmt.Printf("%d %x\n", i, v)
	// }

	// b := []byte("ABC€")
	// fmt.Println(b) // [65 66 67 226 130 172]

	// s := string([]byte{65, 66, 67, 226, 130, 172})
	// fmt.Println(s) // ABC€

	// a := uint16(0x10fe)
	// fmt.Printf("%d\n", a)

	message := "je suis le message"
	fmt.Println(message)
	sz_message := len(message)
	fmt.Printf("%d\n", sz_message)

	header := uint32(sz_message)
	b_a := make([]byte, 4)
	binary.LittleEndian.PutUint32(b_a, header)
	binary.BigEndian.PutUint32(b_a, header)
	fmt.Printf("%d, %x\n", sz_message, header)

	b_all := make([]byte, 4+sz_message)
	fmt.Println(b_all)

	b_all = append(b_a, []byte(message)...)
	fmt.Println(b_all)

	b_header := b_all[:4]
	fmt.Println(b_header)
	b_message := b_all[4:]
	fmt.Println(b_message)
	fmt.Println(string(b_message))
}
