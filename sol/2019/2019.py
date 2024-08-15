class Solution:
    def scoreOfStudents(self, s: str, answers: List[int]) -> int:
        n = len(s)
        m = (n + 1) // 2
        corrAns = 0
        i = 0
        while i < n:
            j = i + 1
            while j < n and s[j] != '+':
                j += 2
            prod = 1
            for k in range(i, j, 2):
                prod *= ord(s[k]) - ord('0')
            corrAns += prod
            i = j + 1
        memo = [[set() for _ in range(m)] for __ in range(m)]
        for i in range(m):
            memo[i][i].add(ord(s[i * 2]) - ord('0'))
        for l in range(1, m):
            for i in range(m - l):
                j = i + l
                for k in range(i, j):
                    for a in memo[i][k]:
                        for b in memo[k + 1][j]:
                            if s[k * 2 + 1] == '+':
                                if a + b <= 1000:
                                    memo[i][j].add(a + b)
                            elif a * b <= 1000:
                                memo[i][j].add(a * b)
        return sum(
            5 if a == corrAns else 2
            for a in answers
            if a in memo[0][n // 2]
        )
