class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        root = dict()
        for w in dictionary:
            ptr = root
            for c in w:
                if c not in ptr:
                    ptr[c] = dict()
                ptr = ptr[c]
            ptr['$'] = True
        n = len(s)
        memo = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            val = memo[i + 1] + 1
            ptr = root
            for j in range(i, n):
                if s[j] not in ptr:
                    break
                ptr = ptr[s[j]]
                if '$' in ptr:
                    val = min(val, memo[j + 1])
            memo[i] = val
        return memo[0]
