from collections import defaultdict

class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        sumDict = defaultdict(list)
        for x in nums:
            y = x
            total = 0
            while y > 0:
                y, r = divmod(y, 10)
                total += r
            sumDict[total].append(x)
        res = -1
        for v in sumDict.values():
            if len(v) < 2:
                continue
            max1, max2 = -1, -1
            for x in v:
                if x > max1:
                    max1, max2 = x, max1
                elif x > max2:
                    max2 = x
            res = max(res, max1 + max2)
        return res
