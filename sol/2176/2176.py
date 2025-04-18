from collections import defaultdict

class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        locs = defaultdict(list)
        res = 0
        for j, x in enumerate(nums):
            for i in locs[x]:
                if i * j % k == 0:
                    res += 1
            locs[x].append(j)
        return res
