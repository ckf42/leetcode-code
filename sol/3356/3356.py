class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        n = len(nums)
        q = len(queries)
        diff = [0] * (n + 1)
        cumsum = 0
        ptr = 0
        for i in range(n):
            cumsum += diff[i]
            while ptr < q and cumsum < nums[i]:
                l, r, v = queries[ptr]
                diff[l] += v
                diff[r + 1] -= v
                if l <= i <= r:
                    cumsum += v
                ptr += 1
            if cumsum < nums[i]:
                return -1
        return ptr

