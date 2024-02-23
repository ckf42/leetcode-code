class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        degree = [0] * n
        for a, b in trust:
            degree[a - 1] -= 1
            degree[b - 1] += 1
        for i in range(n):
            if degree[i] == n - 1:
                return i + 1
        return -1
