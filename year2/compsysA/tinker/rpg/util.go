package main

// Clamp a function that restricts a value between a minimum and a maxiumum
func Clamp(max, min, value float64) float64 {
	if value > min {
		if value < max {
			return value
		}
		return max
	}
	return min
}

// Ternary a function that creates tooling for ternaries in Golang
func Ternary(expression bool, resultA, resultB interface{}) interface{} {
	if expression {
		return resultA
	}
	return resultB
}
