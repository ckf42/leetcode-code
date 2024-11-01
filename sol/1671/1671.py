import bisect

class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        n = len(nums)
        lisLen = [1] * n
        m = [nums[0]]
        for i in range(1, n):
            if nums[i] > m[-1]:
                m.append(nums[i])
                lisLen[i] = len(m)
            else:
                ip = bisect.bisect_left(m, nums[i])
                m[ip] = nums[i]
                lisLen[i] = ip + 1
        ldsLen = [1] * n
        m = [nums[n - 1]]
        for i in range(n - 2, -1, -1):
            if nums[i] > m[-1]:
                m.append(nums[i])
                ldsLen[i] = len(m)
            else:
                ip = bisect.bisect_left(m, nums[i])
                m[ip] = nums[i]
                ldsLen[i] = ip + 1
        res = 0
        for a, b in zip(lisLen, ldsLen):
            if a > 1 and b > 1:
                res = max(res, a + b - 1)
        return n - res
