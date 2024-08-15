class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        rk = {
            v: i
            for i, v in enumerate(sorted(frozenset(arr)))
        }
        return tuple(rk[v] + 1 for v in arr)
