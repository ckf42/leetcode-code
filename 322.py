class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0
        for c in coins:
            if c > amount:
                continue
            if c == amount:
                return 1
            dp[c] = 1
            for i in range(c + 1, amount + 1):
                dp[i] = min(dp[i], dp[i - c] + 1)
        return dp[amount] if dp[amount] != float('inf') else -1
