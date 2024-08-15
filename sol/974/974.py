class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        d = {0: 1}
        prefix = 0
        for x in nums:
            prefix = (prefix + x) % k
            d[prefix] = d.get(prefix, 0) + 1
        res = 0
        for v in d.values():
            res += v * (v - 1) // 2
        return res
