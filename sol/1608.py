class Solution:
    def specialArray(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        idx = 0
        for i in range(n + 1):
            while idx < n and nums[idx] < i:
                idx += 1
            if n - idx == i:
                return i
        return -1
