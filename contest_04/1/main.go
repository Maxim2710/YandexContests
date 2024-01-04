package main

import (
	"encoding/json"
	"fmt"
	"os"
)

type Project struct {
	ProjectId int    `json:"project_id"`
	Tasks     []Task `json:"tasks"`
}

type Task struct {
	UserId    int    `json:"user_id"`
	Id        int    `json:"id"`
	Title     string `json:"title"`
	Completed bool   `json:"completed"`
}

func main() {
	var init_user int
	fmt.Scanln(&init_user)

	dat, _ := os.ReadFile("data.json")
	var parced_slice []Project
	json.Unmarshal(dat, &parced_slice)

	count := 0
	for _, project_control := range parced_slice {
		for _, task_control := range project_control.Tasks {
			if task_control.UserId == init_user && task_control.Completed {
				count++
			}
		}
	}
	fmt.Println(count)
}
