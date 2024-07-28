from collections import defaultdict

class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        edgeDict = defaultdict(list)
        for e in adjacentPairs:
            edgeDict[e[0]].append(e[1])
            edgeDict[e[1]].append(e[0])
        lastPtr = next(k for k, v in edgeDict.items() if len(v) == 1)
        ptr = edgeDict[lastPtr][0]
        res = [lastPtr]
        while len(res) < len(adjacentPairs) + 1:
            res.append(ptr)
            ptr = next((v for v in edgeDict[ptr] if v != res[-2]), None)
        return res


