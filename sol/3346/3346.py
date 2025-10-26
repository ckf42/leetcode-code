class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        nums.sort()
        n = len(nums)
        buff = []
        prefix = [0]
        prev = nums[0]
        for i in range(1, n):
            x = nums[i]
            if x != prev:
                buff.append(prev)
                prefix.append(i)
                prev = x
        buff.append(prev)
        prefix.append(n)
        m = len(buff)
        res = 0
        e = 1
        l = 0
        r = 0
        for i in range(m):
            while e < m and buff[e] - buff[i] <= 2 * k:
                e += 1
            res = max(res, min(prefix[e] - prefix[i], numOperations))
            while l < i and buff[l] < buff[i] - k:
                l += 1
            while r < m and buff[r] <= buff[i] + k:
                r += 1
            c = prefix[i + 1] - prefix[i]
            res = max(res, min(prefix[r] - prefix[l] - c, numOperations) + c)
        return res
