package main

import (
	"fmt"
	"math/rand"
	"time"
)

type Board [3][3]string

func NewBoard() Board {
	return [3][3]string{{" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "}}
}

func (b *Board) set(row, col int, marker string) (ok bool) {
	if b[row][col] != " " {
		return false
	}
	b[row][col] = marker
	return true
}

func (b *Board) isGameOver() (ok bool, winner string) {
	for row := 0; row < 3; row++ {
		if b[row][0] != " " && b[row][0] == b[row][1] && b[row][0] == b[row][2] {
			return true, b[row][0]
		}
	}

	for col := 0; col < 3; col++ {
		if b[0][col] != " " && b[0][col] == b[1][col] && b[0][col] == b[2][col] {
			return true, b[0][col]
		}
	}

	if b[0][0] != " " && b[0][0] == b[1][1] && b[0][0] == b[2][2] {
		return true, b[0][0]
	}
	if b[0][2] != " " && b[0][2] == b[1][1] && b[0][2] == b[2][0] {
		return true, b[0][2]
	}

	isDraw := true
	for row := 0; row < 3; row++ {
		for col := 0; col < 3; col++ {
			if b[row][col] == " " {
				isDraw = false
				break
			}
		}
	}

	return isDraw, "-"
}

type Bot interface {
	startGame(marker string)
	getMarker() string
	step(board Board) (row, col int, marker string)
	endGame(winner string)
}

type RandomBot struct {
	marker string
}

func NewRandomBot() *RandomBot {
	return &RandomBot{"?"}
}

func (b *RandomBot) startGame(marker string) {
	b.marker = marker
}

func (b *RandomBot) getMarker() string {
	return b.marker
}

func (b *RandomBot) step(board Board) (row, col int, marker string) {
	for {
		row, col, marker = rand.Intn(3), rand.Intn(3), b.marker
		if board[row][col] == " " {
			return
		}
	}
}

func (b *RandomBot) endGame(winner string) {
	// Бот не обучается
}

// Ваш код здесь

type UserBot struct {
	marker string
}

func NewUserBot() *UserBot {
	return &UserBot{"?"}
}

func (b *UserBot) startGame(marker string) {
	b.marker = marker
}

func (b *UserBot) getMarker() string {
	return b.marker
}

func (b *UserBot) step(board Board) (row, col int, marker string) {
	marker = b.marker
	pair_list := [][][]int{{{0, 0}, {1, 1}, {2, 2}}, {{2, 0}, {1, 1}, {0, 2}}, {{0, 0},
		{0, 1}, {0, 2}}, {{1, 0}, {1, 1}, {1, 2}},
		{{2, 0}, {2, 1}, {2, 2}}, {{0, 0}, {1, 0}, {2, 0}}, {{0, 1}, {1, 1}, {2, 1}}, {{0, 2},
			{1, 2}, {2, 2}}}

	for _, pair := range pair_list {
		count := 0
		for _, iterator := range pair {
			if board[iterator[0]][iterator[1]] == b.marker {
				count++
			}
		}

		if count == 2 {
			for _, iterator := range pair {
				if board[iterator[0]][iterator[1]] == " " {
					row, col = iterator[0], iterator[1]
					return
				}
			}
		}
	}

	if board[1][1] == " " {
		row, col = 1, 1
		return
	} else {
		if board[1][1] == b.marker {
			for _, iterator := range pair_list {
				count := 0
				for _, iterator := range iterator {
					if board[iterator[0]][iterator[1]] != b.marker && board[iterator[0]][iterator[1]] != " " {
						count++
					}
				}

				if count == 2 {
					for _, iterator := range iterator {
						if board[iterator[0]][iterator[1]] == " " {
							row, col = iterator[0], iterator[1]
							return
						}
					}
				}
			}

			if board[0][0] == b.marker && board[0][2] == b.marker {
				if board[0][1] == " " {
					row, col = 0, 1
					return
				}

				if board[2][2] == " " {
					row, col = 2, 2
					return
				}

				if board[2][0] == " " {
					row, col = 2, 0
					return
				}
			}

			if board[0][0] == b.marker && board[2][0] == b.marker {
				if board[1][0] == " " {
					row, col = 1, 0
					return
				}

				if board[2][2] == " " {
					row, col = 2, 2
					return
				}

				if board[0][2] == " " {
					row, col = 0, 2
					return
				}
			}

			if board[2][2] == b.marker && board[0][2] == b.marker {
				if board[1][2] == " " {
					row, col = 1, 2
					return
				}

				if board[0][0] == " " {
					row, col = 0, 0
					return
				}

				if board[2][0] == " " {
					row, col = 2, 0
					return
				}
			}

			if board[2][2] == b.marker && board[2][0] == b.marker {
				if board[2][1] == " " {
					row, col = 2, 1
					return
				}

				if board[0][0] == " " {
					row, col = 0, 0
					return
				}

				if board[0][2] == " " {
					row, col = 0, 2
					return
				}
			}

			i := 0
			for i < 9 {
				if board[i%3][i/3] == " " {
					row, col = i%3, i/3
					return
				}
				i += 2
			}

			i = 0
			for i < 9 {
				if board[i%3][i/3] == " " {
					row, col = i%3, i/3
					return
				}
				i++
			}
		} else {
			for _, combination := range pair_list {
				count := 0
				for _, position := range combination {
					if board[position[0]][position[1]] != b.marker && board[position[0]][position[1]] != " " {
						count++
					}
				}

				if count == 2 {
					for _, position := range combination {
						if board[position[0]][position[1]] == " " {
							row, col = position[0], position[1]
							return
						}
					}
				}
			}

		}
	}

	i := 0
	for i < 9 {
		if board[i%3][i/3] == " " {
			row, col = i%3, i/3
			return
		}
		i++
	}
	return
}

func (b *UserBot) endGame(winner string) {
	// Бот не обучается
}

func main() {
	rand.Seed(time.Now().UnixNano())
	trainGames, battleGames := 10000, 1000
	totalGames := trainGames + battleGames

	userBot := NewUserBot()
	randomBot := NewRandomBot()

	var winsCount int
	for i := 0; i < totalGames; i++ {
		isRandomBotTurn := (rand.Int()%2 == 0)
		if isRandomBotTurn {
			randomBot.startGame("X")
			userBot.startGame("O")
		} else {
			randomBot.startGame("O")
			userBot.startGame("X")
		}

		board := NewBoard()
		for {
			if ok, winner := board.isGameOver(); ok {
				userBot.endGame(winner)
				randomBot.endGame(winner)
				if i >= trainGames {
					if winner != "-" && winner != randomBot.getMarker() {
						winsCount++
					}
				}

				break
			}

			if isRandomBotTurn {
				if !board.set(randomBot.step(board)) {
					panic("Сell is not empty")
				}
			} else {
				if !board.set(userBot.step(board)) {
					panic("Сell is not empty")
				}
			}
			isRandomBotTurn = !isRandomBotTurn
		}
	}

	if winsCount >= int(0.8*float64(battleGames)) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
