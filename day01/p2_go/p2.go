package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Open the file for reading
	file, err := os.Open("input.txt")
	if err != nil {
		fmt.Println("Error opening file:", err)
		return
	}
	defer file.Close()

	var lList []int
	var rList []int
	similarityScore := 0

	// Create a buffered reader
	scanner := bufio.NewScanner(file)

	// Read the file line by line
	for scanner.Scan() {
		line := scanner.Text()
		// Split the line into components
		parts := strings.Fields(line)
		if len(parts) < 2 {
			continue // Skip lines that don't have at least two numbers
		}

		// Parse the two numbers from the line
		numL, err := strconv.Atoi(parts[0])
		if err != nil {
			continue // Skip lines with invalid numbers
		}
		numR, err := strconv.Atoi(parts[1])
		if err != nil {
			continue // Skip lines with invalid numbers
		}

		// Add the numbers to the respective lists
		lList = append(lList, numL)
		rList = append(rList, numR)
	}

	// Count the frequencies of numbers in rList
	freqMap := make(map[int]int)
	for _, numR := range rList {
		freqMap[numR]++
	}

	// Calculate the similarity score
	for _, numL := range lList {
		similarityScore += numL * freqMap[numL]
	}

	// Print the result
	fmt.Printf("The similarity score of these lists: %d\n", similarityScore)
}
