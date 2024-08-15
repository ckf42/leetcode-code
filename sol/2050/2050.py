from collections import defaultdict

class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        edgeDict = defaultdict(list)
        indegree = [0] * n
        for e in relations:
            edgeDict[e[0] - 1].append(e[1] - 1)
            indegree[e[1] - 1] += 1
        stack = list(i for i in range(n) if indegree[i] == 0)
        res = -1
        preReqTime = [0] * n
        while len(stack) != 0:
            node = stack.pop()
            timeCost = preReqTime[node] + time[node]
            res = max(res, timeCost)
            for nei in edgeDict[node]:
                preReqTime[nei] = max(preReqTime[nei], timeCost)
                indegree[nei] -= 1
                if indegree[nei] == 0:
                    stack.append(nei)
        return res
