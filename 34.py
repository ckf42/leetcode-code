class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if len(nums) == 0:
            return (-1, -1)
        s, e = 0, len(nums)
        while s < e:
            m = (s + e) // 2
            if nums[m] < target:
                s = m + 1
            else:
                e = m
        if s >= len(nums) or nums[s] != target:
            return (-1, -1)
        head = s
        s, e = 0, len(nums)
        while s < e:
            m = (s + e) // 2
            if nums[m] <= target:
                s = m + 1
            else:
                e = m
        return (head, e - 1)
