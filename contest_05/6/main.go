package main

import (
	"fmt"
	"math/rand"
	"time"
)

type Box struct {
}

type Cat struct {
	alive bool
}

func (box Box) open() Cat {
	rand.Seed(time.Now().UnixNano())
	return Cat{rand.Intn(2) == 1}
}

func (cat Cat) is_alive() bool {
	return cat.alive
}

func main() {
	var box Box
	cat := box.open()
	if cat.is_alive() {
		fmt.Print("alive")
	} else {
		fmt.Print("dead")
	}
}
