class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        n = len(questions)
        dp = [None] * n
        dp[-1] = questions[-1][0]
        for i in range(n - 2, -1, -1):
            dp[i] = max(
                questions[i][0] + (dp[i + questions[i][1] + 1] if i + questions[i][1] + 1 < n else 0),
                dp[i + 1])
        return dp[0]
