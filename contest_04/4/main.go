package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type Person struct {
	PassengerId string
	Survived    string
	Pclass      string
	Name        string
	Sex         string
	Age         string
	SibSp       string
	Parch       string
	Ticket      string
	Fare        string
	Cabin       string
	Embarked    string
}

func main() {
	var inputAge int
	var inputPclass int
	fmt.Scan(&inputPclass, &inputAge)
	var lines []string
	my_slice := [][]string{}
	file, _ := os.Open("train.csv")
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		not_parse := scanner.Text()
		lines = strings.Split(not_parse, "\r")
	}
	current_len := len(lines)
	for i := 1; i < current_len; i++ {
		new_lines := strings.Split(lines[i], ",")
		person := Person{
			PassengerId: new_lines[0],
			Survived:    new_lines[1],
			Pclass:      new_lines[2],
			Name:        new_lines[3] + "," + new_lines[4],
			Sex:         new_lines[5],
			Age:         new_lines[6],
			SibSp:       new_lines[7],
			Parch:       new_lines[8],
			Ticket:      new_lines[9],
			Fare:        new_lines[10],
			Cabin:       new_lines[11],
			Embarked:    new_lines[12],
		}
		var controler_Age, controler_Pclass int
		if person.Pclass == "" {
			controler_Pclass = 0
		} else {
			controler_Pclass, _ = strconv.Atoi(person.Pclass)
		}
		if person.Age == "" {
			controler_Age = 0
		} else {
			controler_Age, _ = strconv.Atoi(person.Age)
		}

		if person.Sex == "female" && controler_Age > inputAge && controler_Pclass == inputPclass {
			res := []string{person.Age, person.Name}
			my_slice = append(my_slice, res)
		}
	}
	sort.Slice(my_slice[:], func(i, j int) bool {
		if my_slice[i][0] == my_slice[j][0] {
			return my_slice[i][1] < my_slice[j][1]
		}
		return my_slice[i][0] < my_slice[j][0]
	})
	var new_con string
	for iterator := 0; iterator < len(my_slice); iterator++ {
		con := strings.Replace(my_slice[iterator][1], "\"\"", "\"", -1)
		new_con = con[1 : len(con)-1]
		fmt.Println(new_con)
	}
}
