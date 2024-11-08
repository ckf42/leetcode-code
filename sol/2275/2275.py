class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        res = 0
        for i in range(max(candidates).bit_length()):
            m = 1 << i
            res = max(res, sum((x & m) != 0 for x in candidates))
        return res
