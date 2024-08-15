class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        n = len(nums)
        nums.sort()
        l = 0
        r = nums[n - 1] - nums[0] + 1
        while l < r:
            m = (l + r) // 2
            c = 0
            j = 1
            for i in range(n - 1):
                while j < n and nums[j] - nums[i] <= m:
                    j += 1
                c += j - i - 1
            if c < k:
                l = m + 1
            else:
                r = m
        return l
