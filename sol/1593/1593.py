class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        n = len(s)
        res = 0
        def backtrack(idx, oldSubstrs):
            if idx == n:
                nonlocal res
                res = max(res, len(oldSubstrs))
                return
            for i in range(idx + 1, n + 1):
                if s[idx:i] not in oldSubstrs:
                    oldSubstrs.add(s[idx:i])
                    backtrack(i, oldSubstrs)
                    oldSubstrs.remove(s[idx:i])
        backtrack(0, set())
        return res
