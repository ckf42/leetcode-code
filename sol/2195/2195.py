class Solution:
    def minimalKSum(self, nums: List[int], k: int) -> int:
        res = k * (k + 1) // 2
        nums = sorted(frozenset(nums))
        for x in nums:
            if x > k:
                break
            k += 1
            res += k - x
        return res
