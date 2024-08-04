class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + [x for x in nums if x != 0] + [1]
        n = len(nums) - 2
        if n == 1:
            return nums[1]
        memo = [[0] * (n + 2) for _ in range(n + 2)]
        for i in range(n):
            memo[i + 1][i + 1] = nums[i] * nums[i + 1] * nums[i + 2]
        for l in range(2, n + 1):
            for i in range(0, n - l + 1):
                j = i + l - 1
                for k in range(i, j + 1):
                    memo[i + 1][j + 1] = max(
                        memo[i + 1][j + 1],
                        memo[i + 1][k] + memo[k + 2][j + 1]
                            + nums[i] * nums[k + 1] * nums[j + 2]
                    )
        return memo[1][n]
