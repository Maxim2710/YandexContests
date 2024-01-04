package main

import "fmt"

// Ваш код будет вставлен сюда

import "math"

func shift(data []int, steps int) {
	new_list := make([]int, len(data))
	copy(new_list, data)
	steps_new := int(math.Abs(float64(steps))) % len(data)
	if steps < 0 {
		steps_new = -steps_new
	}
	for i := 0; i < len(data); i++ {
		ind := i - steps_new
		if ind < 0 {
			ind += len(data)
		} else if ind >= len(data) {
			ind -= len(data)
		}
		data[i] = new_list[ind]
	}
}

func main() {
	var steps int
	fmt.Scan(&steps)

	var data [10]int
	for index := range data {
		fmt.Scan(&data[index])
	}

	shift(data[:], steps)
	for _, value := range data {
		fmt.Printf("%d ", value)
	}
}
