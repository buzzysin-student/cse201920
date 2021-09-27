package main

import (
	"fmt"
)

// Yes, it's quicksort again. It's my favourite
// sorting algorithm, okay?

// Author: buzzysin

func main() {
	var s = make([]int, 10)
	s[0], s[1], s[2], s[3], s[4] = 9, 2, 8, 3, 7
	s[5], s[6], s[7], s[8], s[9] = 1, 0, 4, 6, 5

	fmt.Println(quick(s))
}

func quick(slice []int) []int {
	size := len(slice)

	if size <= 1 {
		return slice
	}

	pvtIndx := size / 2
	pvt := slice[pvtIndx]

	lt := make([]int, 0)
	gte := make([]int, 0)

	for i := 0; i < size; i++ {
		val := slice[i]

		if i == pvtIndx {
			continue
		}

		if val < pvt {
			lt = append(lt, val)
		} else {
			gte = append(gte, val)
		}
	}

	result := make([]int, size)

	copy(result[0:len(lt)], quick(lt))
	copy(result[len(lt):len(lt)+1], []int{pvt})
	copy(result[len(lt)+1:size], quick(gte))

	fmt.Println("lt", lt)
	fmt.Println("pvt", pvt)
	fmt.Println("gte", gte)
	fmt.Println()

	return result
}
