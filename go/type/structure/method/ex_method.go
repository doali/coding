package main

// https://go-tour-fr.appspot.com/methods/1

import (
	"fmt"
	"math"
)

// Majuscule pour exporter
type Coord struct {
	X, Y float64
}

func (c Coord) abs() float64 {
	return math.Sqrt(c.X*c.X + c.Y*c.Y)
}

// c *Coord <= permet de modifier c
func (c *Coord) SetCoord(pC Coord) *Coord {
	c.X = pC.X
	c.Y = pC.Y
	return c
}

func main() {
	v := Coord{3, 4}
	fmt.Println(v.abs())
	fmt.Println(v)

	var c Coord
	fmt.Println(c)
	c.SetCoord(v)
	fmt.Println(c)
}
