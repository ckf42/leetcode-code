from collections import Counter

class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        c = Counter()
        c[0] = 1
        target = 0
        for x in nums:
            target |= x
            newC = Counter(c)
            for k, v in c.items():
                newC[k | x] += v
            c = newC
        return c[target]
