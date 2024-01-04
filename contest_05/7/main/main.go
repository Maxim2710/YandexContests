package main

import "fmt"

// Ваш код будет вставлен сюда

type Water struct {
	value int
}

func NewWater(initValue int) Water {
	return Water{initValue}
}

type Teapot struct {
	value int
}

func (teapot Teapot) is_boiling() bool {
	if teapot.value >= 100 {
		return true
	}
	return false
}

func (teapot *Teapot) heat_up(new_val int) {
	teapot.value += new_val
}

func NewTeapot(water Water) Teapot {
	return Teapot(water)
}

func main() {
	var temperature, count int
	fmt.Scan(&temperature, &count)

	heat := NewQueue()
	for i := 0; i < count; i++ {
		var t int
		fmt.Scan(&t)
		heat.Push(t)
	}

	water := NewWater(temperature)
	teapot := NewTeapot(water)

	for !teapot.is_boiling() {
		teapot.heat_up(heat.Pop())
	}

	for !heat.IsEmpty() {
		fmt.Print(heat.Pop(), " ")
	}
}
