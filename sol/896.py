class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        if len(nums) <= 2:
            return True
        ptr = 1
        while ptr < len(nums) and nums[ptr] == nums[ptr - 1]:
            ptr += 1
        if ptr == len(nums):
            return True
        if nums[ptr] > nums[ptr - 1]:
            for i in range(ptr, len(nums) - 1):
                if nums[i] > nums[i + 1]:
                    return False
        else:
            for i in range(ptr, len(nums) - 1):
                if nums[i] < nums[i + 1]:
                    return False
        return True
