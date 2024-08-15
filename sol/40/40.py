class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        n = len(candidates)
        nextIdx = [-1] * n
        i = 0
        j = 0
        while i < n:
            while j < n and candidates[j] == candidates[i]:
                j += 1
            for k in range(i, j):
                nextIdx[k] = j
            i = j
        res = []
        def backtrack(remain, idx, comb):
            if remain == 0:
                nonlocal res
                res.append(comb.copy())
                return
            if idx == n or candidates[idx] > remain:
                return
            comb.append(candidates[idx])
            backtrack(remain - candidates[idx], idx + 1, comb)
            comb.pop()
            backtrack(remain, nextIdx[idx], comb)
        backtrack(target, 0, [])
        return res
