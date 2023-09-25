from itertools import accumulate

class Solution:
    def canEat(self, candiesCount: List[int], queries: List[List[int]]) -> List[bool]:
        firstIdxOfType = tuple(accumulate(candiesCount, lambda x, y: x + y, initial=0))
        ptr = 0
        res = [False] * len(queries)
        for candy, day, cap in queries:
            res[ptr] = day <= firstIdxOfType[candy + 1] - 1 \
                    and (day + 1) * cap - 1 >= firstIdxOfType[candy]
            ptr += 1
        return res
