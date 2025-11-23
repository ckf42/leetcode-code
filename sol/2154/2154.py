class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        nums.sort()
        for x in nums:
            if original == x:
                original *= 2
            elif x > original:
                break
        return original
