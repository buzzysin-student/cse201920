package main

import (
	"fmt"
)

func main() {
	attributes := []Attribute{WATER, FIRE, AIR, EARTH}
	for i := 0; i < 4; i++ {
		a := attributes[i]
		for j := 0; j < 4; j++ {
			b := attributes[j]
			fmt.Println(a.name(), "vs", b.name()+":", a.compare(&b))
		}
	}
}
