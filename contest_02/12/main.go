package main

import "fmt"

// Ваш код здесь

func fill(maze [][]int) {
	for j := 0; j < len(maze); j++ {
		for i := 0; i < len(maze[j]); i++ {
			if maze[j][i] == -1 {
				continue
			}

			go_i := max(0, i-1)
			go_j := max(0, j-1)
			drop_i := min(len(maze[j])-1, i+1)
			drop_j := min(len(maze)-1, j+1)

			for j_f := go_j; j_f <= drop_j; j_f++ {
				for i_f := go_i; i_f <= drop_i; i_f++ {
					if maze[j_f][i_f] == -1 {
						maze[j][i]++
					}
				}
			}
		}
	}
}

func main() {
	var rows, cols int
	fmt.Scanf("%d %d\n", &rows, &cols)

	// Создаём срез и заполняем его данными о расположении мин
	maze := make([][]int, rows, rows)
	for i := range maze {
		maze[i] = make([]int, cols, cols)
		for j := range maze[i] {
			fmt.Scanf("%d", &maze[i][j])
		}
	}

	// Заполняем игровое поле подсказками
	fill(maze)

	// Выводим на экран
	for _, row := range maze {
		for _, cell := range row {
			fmt.Printf("%3d", cell)
		}
		fmt.Println()
	}
}
