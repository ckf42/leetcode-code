class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        n = len(nums)
        nums.sort()
        s = 0
        e = nums[n - 1] - nums[0] + 1
        while s < e:
            m = (s + e) // 2
            pairCount = 0
            ptr = 1
            while ptr < n and pairCount < p:
                if nums[ptr] - nums[ptr - 1] <= m:
                    pairCount += 1
                    ptr += 2
                else:
                    ptr += 1
            if pairCount == p:
                e = m
            else:
                s = m + 1
        return s
