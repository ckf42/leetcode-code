class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        res = []
        n = len(candidates)
        def gen(idx, remain, prefix):
            if remain == 0:
                res.append(prefix.copy())
                return
            if idx == n or candidates[idx] > remain:
                return
            gen(idx + 1, remain, prefix)
            x = candidates[idx]
            r = remain // x
            for i in range(1, r + 1):
                prefix.append(x)
                gen(idx + 1, remain - x * i, prefix)
            for _ in range(r):
                prefix.pop()
        gen(0, target, [])
        return res
