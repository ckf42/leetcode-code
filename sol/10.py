class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        ns = len(s)
        np = len(p)
        memo = [[False] * (np + 1) for _ in range(ns + 1)]
        memo[-1][-1] = True
        for i in range(ns, -1, -1):
            for j in range(np - 1, -1, -1):
                # this is usually a good optimization,
                # but some test cases has patten with consecutive '*'
                # if p[j] == '*':
                #     continue
                m = i != ns and (p[j] == '.' or p[j] == s[i])
                if j < np - 1 and p[j + 1] == '*':
                    memo[i][j] = memo[i][j + 2] or (m and memo[i + 1][j])
                else:
                    memo[i][j] = m and memo[i + 1][j + 1]
        return memo[0][0]
