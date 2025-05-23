from collections import defaultdict

class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        d = defaultdict(list)
        res = []
        for i, x in enumerate(groupSizes):
            d[x].append(i)
            if len(d[x]) == x:
                res.append(d[x].copy())
                d[x].clear()
        return res
