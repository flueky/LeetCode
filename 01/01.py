from typing import List

class Solution(object):
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        result = []
        map = {}
        for i in range(len(nums)):
            cur = nums[i]
            complement = target-cur
            if complement in map.keys():
                result = [map[complement], i]
            map[cur] = i
        return result

for i in Solution().twoSum([2, 7, 11, 15],9):
    print(i)