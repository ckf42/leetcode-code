from collections import defaultdict

class Solution:
    def maxStarSum(self, vals: List[int], edges: List[List[int]], k: int) -> int:
        nbVals = defaultdict(list)
        for edge in edges:
            nbVals[edge[0]].append(vals[edge[1]])
            nbVals[edge[1]].append(vals[edge[0]])
        for key in nbVals:
            nbVals[key].sort(reverse=True)
        maxSum = max(vals)
        for node, nbv in nbVals.items():
            ptr = min(k, len(nbv))
            while ptr > 0 and nbv[ptr - 1] < 0:
                ptr -= 1
            maxSum = max(maxSum, sum(nbv[:ptr]) + vals[node])
        return maxSum
