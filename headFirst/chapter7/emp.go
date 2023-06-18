package main

import (
	"fmt"
	"sort"
)

type emp struct {
	name  string
	lname string
	age   int
}

type emps []emp

func (e emps) Len() int {
	return len(e)
}

func (e emps) Swap(i int, j int) {
	e[i], e[j] = e[j], e[i]
}

func (e emps) Less(i, j int) bool {
	return e[i].age < e[j].age
}

func main() {
	fmt.Println("vim-go")
	x := emps{
		emp{"abc", "abc", 22},
		emp{"def", "def", 23},
		emp{"ghi", "ghi", 20},
	}
	sort.Sort(x)
	for _, val := range x {
		fmt.Println(val.name)
	}
}
