package main

import (
	"bufio"
	"fmt"
	"os"
)

// Ваш код будет вставлен сюда

import (
	"regexp"
	"strings"
)

func isPalindrome(str_in string) bool {
	var max_proxod int
	if len(str_in)%2 == 0 {
		max_proxod = len(str_in) / 2
	} else if len(str_in)%2 != 0 {
		max_proxod = len(str_in)/2 + 1
	}
	var low_new_str string = strings.ToLower(str_in)
	var flag bool = true
	m := regexp.MustCompile(`[~!@#%^&*() ]`)
	low_new_str = m.ReplaceAllString(low_new_str, "")
	if low_new_str == "" {
		return true
	}
	var i int
	for i = 0; i < max_proxod; i++ {
		if low_new_str[i] != low_new_str[len(low_new_str)-i-1] {
			return false
			break
		}
	}
	return flag
}

func main() {
	line, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	if isPalindrome(line[:len(line)-1]) { // Обрезаем \n в конце строки
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
