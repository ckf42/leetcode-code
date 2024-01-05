from collections import Counter

class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        c = Counter(nums)
        res = list()
        buffer = list()
        while len(c) != 0:
            buffer.clear()
            keys = tuple(c.keys())
            for k in keys:
                buffer.append(k)
                c[k] -= 1
                if c[k] == 0:
                    del c[k]
            res.append(buffer.copy())
        return res
