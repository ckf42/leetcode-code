class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        n1 = len(str1)
        n2 = len(str2)
        memo = [[0] * (n2 + 1) for _ in range(n1 + 1)]  # s1[0:i), s2[0:j)
        for i in range(n1 + 1):
            memo[i][0] = i
        for j in range(n2 + 1):
            memo[0][j] = j
        for i in range(n1):
            for j in range(n2):
                if str1[i] == str2[j]:
                    memo[i + 1][j + 1] = memo[i][j] + 1
                else:
                    memo[i + 1][j + 1] = min(memo[i][j + 1], memo[i + 1][j]) + 1
        l = memo[n1][n2]
        res = []
        i, j = n1 - 1, n2 - 1
        while i >= 0 and j >= 0:
            if str1[i] == str2[j]:
                res.append(str1[i])
                i -= 1
                j -= 1
            elif memo[i + 1][j + 1] == memo[i][j + 1] + 1:
                res.append(str1[i])
                i -= 1
            else:
                res.append(str2[j])
                j -= 1
        resStr = ''.join(res[::-1])
        if i >= 0:
            resStr = str1[:i + 1] + resStr
        if j >= 0:
            resStr = str2[:j + 1] + resStr
        return resStr
        
