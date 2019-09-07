package main

import "fmt"

func main() {
	text := "AABAACAADAABAABA"
	
	pattern := "AABA"
	for i := 0; i < (len(text) - len(pattern) + 1); i++ {
		if text[i:i+len(pattern)] == pattern {
			fmt.Printf("Match at index: %d \n", i)
		}
	}
}
