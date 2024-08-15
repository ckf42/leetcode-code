from collections import defaultdict

class Solution:
    def gardenNoAdj(self, n: int, paths: List[List[int]]) -> List[int]:
        edgeList = defaultdict(list)
        for i, j in paths:
            edgeList[i - 1].append(j - 1)
            edgeList[j - 1].append(i - 1)
        res = []
        for i in range(n):
            choice = {1, 2, 3, 4}
            for j in edgeList[i]:
                if j < len(res):
                    choice.discard(res[j])
            res.append(choice.pop())
        return res
