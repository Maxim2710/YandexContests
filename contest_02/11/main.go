package main

import "fmt"

const rows int = 9
const cols int = 9

// Ваш код будет вставлен сюда

func isValidSudoku(bord [rows][cols]int) bool {
	var my_flag bool = true
	for i := 0; i < cols; i++ {
		check_list := make([]int, 10)
		for j := 0; j < rows; j++ {
			check_list[bord[j][i]]++
			if check_list[bord[j][i]] > 1 {
				my_flag = false
				return my_flag
				break
			}
		}
	}
	for j := 0; j < cols; j++ {
		check_list := make([]int, 10)
		for i := 0; i < rows; i++ {
			check_list[bord[j][i]]++
			if check_list[bord[j][i]] > 1 {
				my_flag = false
				return my_flag
				break
			}
		}
	}
	for j_first := 0; j_first < rows-3; j_first += 3 {
		for i_first := 0; i_first < cols-3; i_first += 3 {
			check_list := make([]int, 10)
			for j_second := 3; j_second < j_first+3; j_second++ {
				for i_second := 3; i_second < i_first+3; i_second++ {
					check_list[bord[j_second][i_second]]++
					if check_list[bord[j_second][i_second]] > 1 {
						my_flag = false
						return my_flag
						break
					}
				}
			}
		}
	}
	return true
}

func main() {
	var bord [rows][cols]int

	for row := 0; row < rows; row++ {
		for col := 0; col < cols; col++ {
			fmt.Scanf("%c", &bord[row][col]) // Считываем один символ
			bord[row][col] -= '0'            // Чтобы из ASCII кода символа получить цифру
		}
		fmt.Scanf("\n")
	}

	if isValidSudoku(bord) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
