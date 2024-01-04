package main

import (
	"fmt"
)

func main() {
	var n, x int
	var control_nul_1, control_nul_2 int
	fmt.Scan(&n, &x)
	var value int
	var bag []int = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&value)
		bag[i] = value
	}
	var ans1, ans2 int
	my_list := make(map[int]int, len(bag))
	for j := 0; j < len(bag); j++ {
		if bag[j]+my_list[bag[j]] == x {
			ans1 = bag[j]
			ans2 = my_list[bag[j]]
			break
		}
		my_list[x-bag[j]] = bag[j]
	}
	if ans1 != 0 && ans2 != 0 && ans1 >= ans2 {
		fmt.Println(ans2, ans1)
	} else if ans1 != 0 && ans2 != 0 && ans1 <= ans2 {
		fmt.Println(ans1, ans2)
	} else if ans1 == 0 && ans2 == 0 {
		fmt.Println(control_nul_1, control_nul_2)
	}
}
