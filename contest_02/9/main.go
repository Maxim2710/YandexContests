package main

import (
	"bufio"
	"fmt"
	"os"
)

// Ваш код будет вставлен сюда

import (
	"strconv"
)

func isLucky(n string) bool {
	var first_3, second_3 int = 0, 0
	for _, value := range n[:3] {
		point, _ := strconv.Atoi(string(value))
		first_3 += point
	}
	for _, value := range n[3:] {
		point, _ := strconv.Atoi(string(value))
		second_3 += point
	}
	if first_3 == second_3 {
		return true
	} else {
		return false
	}
}

func main() {
	number, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	if isLucky(number[:len(number)-1]) { // Обрезаем \n в конце строки
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
