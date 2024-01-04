package main

import (
	"fmt"
	"os"
)

func main() {
	var x int
	var cnt = 0
	fmt.Fscan(os.Stdin, &x)
	for x > 1 {
		if x%2 == 0 {
			x = x / 2
			cnt += 1
		} else if x%2 != 0 {
			x = x*3 + 1
			cnt += 1
		}
	}
	fmt.Println(cnt)
}
