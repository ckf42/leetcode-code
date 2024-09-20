class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        tokenized = []
        buff = []
        for c in expression:
            if c.isdigit():
                buff.append(c)
            else:
                tokenized.append(int(''.join(buff)))
                buff.clear()
                tokenized.append(c)
        tokenized.append(int(''.join(buff)))
        n = len(tokenized)
        memo = [[list() for __ in range(n)] for _ in range(n)]
        for i in range(0, n, 2):
            memo[i][i] = [tokenized[i]]
        for l in range(3, n + 1, 2):
            for i in range(0, n - l + 1, 2):
                j = i + l - 1
                for k in range(i + 1, j, 2):
                    for a in memo[i][k - 1]:
                        for b in memo[k + 1][j]:
                            if tokenized[k] == '+':
                                memo[i][j].append(a + b)
                            elif tokenized[k] == '-':
                                memo[i][j].append(a - b)
                            else:
                                memo[i][j].append(a * b)
        return memo[0][n - 1]
