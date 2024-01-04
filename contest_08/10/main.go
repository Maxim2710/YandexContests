package main

import "fmt"

type Human struct {
	name string
	age  int
}

// Ваш код здесь

func printTypes(data []interface{}) {
	for _, v := range data {
		if _, ok := v.(int); ok {
			fmt.Print("int ")
		} else if _, ok := v.(string); ok {
			fmt.Print("string ")
		} else if _, ok := v.(Human); ok {
			fmt.Print("Human ")
		} else if _, ok := v.(*Human); ok {
			fmt.Print("*Human ")
		} else {
			fmt.Print("interface ")
		}
	}
}

func main() {
	var count int
	fmt.Scan(&count)

	var data []interface{} = make([]interface{}, count)
	for i := 0; i < count; i++ {
		var t string
		fmt.Scan(&t)
		switch t {
		case "int":
			var val int = 0
			data[i] = interface{}(val)
		case "string":
			var val string = "0"
			data[i] = interface{}(val)
		case "Human":
			var val Human = Human{}
			data[i] = interface{}(val)
		case "*Human":
			var val *Human = &Human{}
			data[i] = interface{}(val)
		}
	}

	printTypes(data)
}
