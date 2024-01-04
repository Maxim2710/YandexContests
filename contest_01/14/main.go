package main

import (
	"fmt"
	"os"
)

func main() {

	var stroki int
	var stolbci int

	fmt.Fscan(os.Stdin, &stroki, &stolbci)

	fmt.Print("    |")

	for cnt := 1; cnt <= stolbci; cnt++ {
		fmt.Print("  ")
		if cnt < 10 {
			fmt.Print(" ")
		}
		fmt.Print(cnt)
	}

	fmt.Print("\n" + "   --")

	for t := 1; t <= stolbci; t++ {
		fmt.Print("----")
	}

	for first_num := 1; first_num <= stroki; first_num++ {
		var data = 1
		fmt.Print("\n")
		if first_num >= 100 {
			data = 1
		} else if first_num >= 10 {
			data = 2
		} else {
			data = 3
		}
		for i := 1; i <= data; i++ {
			fmt.Print(" ")
		}

		fmt.Print(first_num, "|")

		for second_num := 1; second_num <= stolbci; second_num++ {

			var data = 3

			var itog = first_num * second_num

			if itog >= 100 {
				data = 1
			} else if itog >= 10 {
				data = 2
			} else {
				data = 3
			}
			for rasst := 1; rasst <= data; rasst++ {
				fmt.Print(" ")
			}

			fmt.Print(first_num * second_num)

		}

	}

}
