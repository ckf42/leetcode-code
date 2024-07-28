from bisect import bisect_left
from collections import defaultdict

class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 2:
            return 0
        indices = defaultdict(list)
        for i, x in enumerate(nums):
            indices[x].append(i)
        memo = [defaultdict(int) for _ in range(n)]
        res = 0
        for i in range(2, n):
            for j in range(1, i):
                diff = nums[i] - nums[j]
                y = nums[j] - diff
                ip = bisect_left(indices[y], j)
                if ip != 0:
                    memo[i][diff] += memo[j][diff] + ip
            res += sum(memo[i].values())
        return res
