package main

import (
	"fmt"
	"os"
)

func main() {
	var a int
	var b int
	fmt.Fscan(os.Stdin, &a, &b)
	fmt.Println(a * b)
}
