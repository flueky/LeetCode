package main

import "fmt"

func twoSum(nums []int, target int) []int {
	var temp map[int]int
	temp = make(map[int]int)
	var result [2]int
	for i := 0; i < len(nums); i++ {
		var cur int = nums[i]
		var complement int = target - cur
		if value, ok := temp[complement]; ok {
			result[0] = value
			result[1] = i
			return result[:]
		}
		temp[cur] = i
	}
	return []int{}
}

func main() {
	var result = twoSum([]int{2, 7, 11, 15}, 9)
	for _, v := range result {
		fmt.Println(v)
	}

}
