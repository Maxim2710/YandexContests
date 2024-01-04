package main

import (
	"fmt"
)

type Stack interface {
	empty() bool
	push(r rune)
	top() rune
	pop() rune
}

// Ваш код здесь

type SimpleStack []rune

func NewSimpleStack() *SimpleStack {
	return &SimpleStack{}
}

func (s *SimpleStack) empty() bool {
	return len(*s) == 0
}

func (s *SimpleStack) push(r rune) {
	*s = append(*s, r)
}

func (s *SimpleStack) top() rune {
	return (*s)[len(*s)-1]
}

func (s *SimpleStack) pop() rune {
	r := s.top()
	*s = (*s)[:len(*s)-1]
	return r
}

func bracketValidator(stack Stack, str string) bool {
	mapping := map[rune]rune{
		')': '(',
		']': '[',
		'}': '{',
	}

	for _, char := range str {
		if char == '(' || char == '[' || char == '{' {
			stack.push(char)
		} else if char == ')' || char == ']' || char == '}' {
			if stack.empty() || stack.top() != mapping[char] {
				return false
			}
			stack.pop()
		}
	}

	return stack.empty()
}

func main() {
	var input string
	fmt.Scan(&input)
	fmt.Println(bracketValidator(NewSimpleStack(), input))
}
