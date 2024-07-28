class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        one = 0
        two = 0
        for x in nums:
            one = (one ^ x) & ~two
            two = (two ^ x) & ~one
        return one
