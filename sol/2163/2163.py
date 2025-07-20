import heapq as hq

class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        m = len(nums)
        n = m // 3
        prefix = [0] * (n + 1)
        h = [-x for x in nums[:n]]
        prefix[0] = -sum(h)
        hq.heapify(h)
        for i in range(1, n + 1):
            prefix[i] = prefix[i - 1] + nums[n + i - 1] + hq.heappushpop(h, -nums[n + i - 1])
        suffix = [0] * (n + 1)
        h = nums[m - n:]
        suffix[n] = sum(h)
        hq.heapify(h)
        for i in range(n - 1, -1, -1):
            suffix[i] = suffix[i + 1] + nums[n + i] - hq.heappushpop(h, nums[n + i])
        return min(a - b for a, b in zip(prefix, suffix))

