class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        M = 10 ** 4 + 1
        minEles = [[], [M, M], [M, M]]
        count = sum(nums)
        for x in nums:
            r = x % 3
            if r != 0:
                if x <= minEles[r][0]:
                    minEles[r][0], minEles[r][1] = x, minEles[r][0]
                elif x <= minEles[r][1]:
                    minEles[r][1] = x
        r = count % 3
        if r != 0:
            opt = count
            if minEles[r][0] != M:
                opt = minEles[r][0]
            if minEles[3 - r][1] != M:
                opt = min(opt, minEles[3 - r][0] + minEles[3 - r][1])
            count -= opt
        return count
