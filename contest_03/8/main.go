package main

import (
	"fmt"
)

func main() {
	var n int
	var k int
	var res int
	fmt.Scan(&n)
	var a []int = make([]int, n)
	for q := 0; q < n; q++ {
		fmt.Scan(&k)
		a[q] = k
	}
	word_l := make(map[int]int, len(a))
	for i := 0; i < len(a); i++ {
		word_l[a[i]]++
	}
	for j := 0; j < len(a); j++ {
		if word_l[a[j]]%2 != 0 {
			res = a[j]
		}
	}
	fmt.Println(res)
}
