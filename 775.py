class Solution:
    def isIdealPermutation(self, nums: List[int]) -> bool:
        ptr = 0
        minToCheck = 0
        while ptr < len(nums):
            if nums[ptr] == minToCheck:
                ptr += 1
                minToCheck += 1
            elif nums[ptr] == minToCheck + 1 and nums[ptr + 1] == minToCheck:
                ptr += 2
                minToCheck += 2
            else:
                return False
        return True
