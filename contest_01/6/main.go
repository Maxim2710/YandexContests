package main

import (
	"fmt"
	"os"
)

func main() {
	var summ int
	var m_5000, m_1000, m_500, m_200, m_100 int
	fmt.Fscan(os.Stdin, &summ)
	for summ > 0 {
		if summ-5000 >= 0 {
			m_5000 += 1
			summ -= 5000
		} else if summ-1000 >= 0 {
			m_1000 += 1
			summ -= 1000
		} else if summ-500 >= 0 {
			m_500 += 1
			summ -= 500
		} else if summ-200 >= 0 {
			m_200 += 1
			summ -= 200
		} else if summ-100 >= 0 {
			m_100 += 1
			summ -= 100
		}
	}
	fmt.Println(m_5000, m_1000, m_500, m_200, m_100)
}
