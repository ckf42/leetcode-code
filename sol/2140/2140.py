class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        n = len(questions)
        memo = [0] * n
        memo[n - 1] = questions[n - 1][0]
        for i in range(n - 2, -1, -1):
            if (j := i + questions[i][1] + 1) < n:
                memo[i] = max(memo[i + 1], questions[i][0] + memo[j])
            else:
                memo[i] = max(memo[i + 1], questions[i][0])
        return memo[0]
