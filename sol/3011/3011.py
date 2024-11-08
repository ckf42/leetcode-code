class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        lower = 0
        rgMax = 0
        rgBitCount = 0
        for x in nums:
            if (bc := x.bit_count()) != rgBitCount:
                lower = rgMax
                rgMax = x
                rgBitCount = bc
            if x < lower:
                return False
            rgMax = max(rgMax, x)
        return True
