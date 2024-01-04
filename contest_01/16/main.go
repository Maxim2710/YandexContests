package main

import (
	"fmt"
)

func main() {
	var cnt_el int
	fmt.Scanln(&cnt_el)
	var arr []float64 = make([]float64, cnt_el)
	for i := range arr {
		fmt.Scan(&arr[i])
	}
	var comf_list []any = make([]any, cnt_el)
	for k, j := range arr {
		if k == 0 || k == cnt_el-1 {
			comf_list[k] = j
			continue
		} else {
			comf_list[k] = (arr[k-1] + j + arr[k+1]) / 3
		}
	}
	fmt.Println(comf_list...)
}
