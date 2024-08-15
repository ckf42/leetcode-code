class Solution:
    def arraySign(self, nums: List[int]) -> int:
        isPos = True
        for n in nums:
            if n == 0:
                return 0
            elif n < 0:
                isPos = not isPos
        return 1 if isPos else -1
