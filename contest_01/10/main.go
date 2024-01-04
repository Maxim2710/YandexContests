package main

import (
	"fmt"
	"os"
)

func main() {
	var ans [3]string
	fmt.Fscan(os.Stdin, &ans[0], &ans[1], &ans[2])
	var kot [3]string = [3]string{"Нет", "Нет", "Нет"}
	var jur [3]string = [3]string{"Нет", "Нет", "Да"}
	var chicken [3]string = [3]string{"Нет", "Да", "Нет"}
	var straus [3]string = [3]string{"Нет", "Да", "Да"}
	var dolphin [3]string = [3]string{"Да", "Нет", "Нет"}
	var plez [3]string = [3]string{"Да", "Нет", "Да"}
	var pin [3]string = [3]string{"Да", "Да", "Нет"}
	var ytka [3]string = [3]string{"Да", "Да", "Да"}
	if ans == kot {
		fmt.Println("Кот")
	} else if ans == jur {
		fmt.Println("Жираф")
	} else if ans == chicken {
		fmt.Println("Курица")
	} else if ans == straus {
		fmt.Println("Страус")
	} else if ans == dolphin {
		fmt.Println("Дельфин")
	} else if ans == plez {
		fmt.Println("Плезиозавры")
	} else if ans == pin {
		fmt.Println("Пингвин")
	} else if ans == ytka {
		fmt.Println("Утка")
	}
}
