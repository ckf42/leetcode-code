class Solution:
    def countInterestingSubarrays(self, nums: List[int], modulo: int, k: int) -> int:
        res = 0
        bins = {0: 1}
        count = 0
        for x in nums:
            if x % modulo == k:
                count = (count + 1) % modulo
            res += bins.get((count + modulo - k) % modulo, 0)
            bins[count] = bins.get(count, 0) + 1
        return res
