package main

import "fmt"

import "math"

func main() {
	var person_on_day float64 = 0.5
	var dub_year int = 20
	var topol_year int = 32
	var neobx_for_one_person = person_on_day * 365
	var kol_vo_top = neobx_for_one_person / float64(topol_year)
	var kol_vo_dub = neobx_for_one_person / float64(dub_year)
	fmt.Println(neobx_for_one_person, math.Ceil(kol_vo_top), math.Ceil(kol_vo_dub))
}
